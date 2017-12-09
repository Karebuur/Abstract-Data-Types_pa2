/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int n; /*Number of nodes aka elements in the "array of intVecs" */
    int edgeCount;/*counts number of edges*/
    int flag;
    FILE *fp;
    char * fgetsRet;
    char line[1024];

    if (argc == 3){
	fp = fopen(argv[2],"r");
	if (strcmp(argv[1],"-U") == 0){
	    flag = 1;
	    printf("flag -U passed\n");
	}
    }
    else{
	    flag = 0;
	    fp = fopen(argv[1],"r");
    }

    fgetsRet = fgets(line, 1024,fp);

    //Get the number of nodes and create an array of that size
    sscanf(line, "%d", &n);
    IntVec * adjList = malloc((n+1) * sizeof(IntVec));
    IntVec * trList;
    if (fp != NULL ) {
        /*Makes an array of empty vectors*/
        for (int i= 1; i <= n; i++){
            adjList[i] = intMakeEmptyVec();
        }
        fgets(line,1024,fp);/*Read first line*/
        /*Read the rest of the file and assign values to edges*/

        edgeCount = pushEdges(fgetsRet, line, adjList, n, fp, flag);
        fclose(fp);
    }
    else{
        fprintf(stderr, "No file Received\n");
        exit(1);
    }
    int **A;
    /* Loads the graph and prints output*/
    printf("n = %d\n",n);
    printf("m = %d\n",edgeCount);
    printAdjVerts(adjList, n);
    A = makeAdjMatrix(adjList,n);
    printf("\n");
    printAdjMatrix(A,n);
    for (int i = 1; i <=n; i++){
        free(A[i]);
    }
    free(A);


    trList = transposeGraph(adjList, n);
    printf("\nTranspose: \n");
    printAdjVerts(trList, n);
    A = makeAdjMatrix(trList,n);
    printf("\n");
    printAdjMatrix(A,n);
    for (int i = 1; i <=n; i++){
        free(A[i]);
    }
    free(A);

    IntVec* temp;
    temp = transposeGraph(trList, n);
    freeAdjList(trList, n);
    trList = temp;
    printf("\nTranspose of Transpose: \n");
    printAdjVerts(trList, n);
    A = makeAdjMatrix(trList,n);
    printf("\n");
    printAdjMatrix(A,n);


    freeAdjList(adjList,n);
    freeAdjList(trList,n);
    for (int i = 1; i <=n; i++){
        free(A[i]);
    }
    free(A);

    return 0;
}
