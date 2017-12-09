/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "intVec.h"
#include "edge.h"
#include "loadGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Read in the original graph and transpose the edges into nodes and vice versa
IntVec* transposeGraph(IntVec* origGraph, int n){
    IntVec* tempGraph = malloc( (n+1) * sizeof(IntVec));
    int newE;

    for (int  i = 1; i <= n; i++){
	    tempGraph[i] = intMakeEmptyVec();
	}

	for (int k = 1; k <= n; k++){
        for(int i =intSize(origGraph[k]); i != 0; i--){
            newE=intData(origGraph[k], i);
            intVecPush(tempGraph[newE],k);
        }
	}

	return tempGraph;
}

int** makeAdjMatrix(IntVec* adjList, int n){
    int** A = calloc(n+1, sizeof(int*));
    int val;
    for (int i = 1; i <=n; i++){
        A[i]= calloc(n+1,sizeof(int));
    }

    for (int k = 1; k <= n; k++){
        for(int i =intSize(adjList[k]); i != 0; i--){
            val = intData(adjList[k], i);
            A[k][val] = 1;
        }
	}
    return A;
}

void printAdjVerts(IntVec* adjList,int n){

    for(int i = 1; i<=n; i++){
        printf("%d\t",i);
        printVector(adjList[i]);
        printf("\n");
    }

}

void printAdjMatrix(int** A, int n){
    if (n<=20){
        printf("     ");
        for (int i = 1; i <= n; i++){
            printf(" %3d ", i);
        }
        printf("\n");
        printf("     ");
        for (int i = 1; i <= 5*n; i++){
            printf("-");
        }
        printf("\n");


        for (int i = 1; i <=n; i++){
            printf("%3d :",i);
            for(int j = 1; j <=n; j++){
                printf(" %3d ", A[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("\nError: More than 20 nodes\n\n");
    }
}


void printVector(IntVec myVec){
    int top = intTop(myVec);

    if (top == 0){
        printf("null");
    }
    else{
        printf("[");
        for (int i = intSize(myVec); i != 0; i--){
            printf(" %d ", intData(myVec,i));
            if(i > 1){
                printf(",");
            }
        }
        printf("]");
    }
}
