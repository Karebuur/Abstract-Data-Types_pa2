/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Edge parseEdge(char line[], int nodes)
{
    Edge newE;
    int numFields;

    numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
    if (numFields < 2 || numFields > 3 || newE.from > nodes || newE.to > nodes || newE.from <= 0 || newE.to <= 0)
    {
        printf("Bad edge\t(from) (to) (weight):\n\t\t %s \n\n", line);
        exit(1);
    }
    if (numFields == 2)
        newE.weight = 0.0;

    return newE;
}

int pushEdges(char * ret, char line[], IntVec adjList[], int n, FILE * fp, int flag){
    int edgeCount = 0;
    char*fgetsRet = ret;

    while (fgetsRet == line)
    {
        Edge e = parseEdge(line, n);
        edgeCount +=1;

        if(flag == 1){
            if (e.from != e.to){
                intVecPush(adjList[e.from], e.to);
                intVecPush(adjList[e.to],e.from);
                edgeCount +=1;
            }
        }else{
            intVecPush(adjList[e.from], e.to);
        }

        fgetsRet = fgets(line, 1024, fp);
    }
    return edgeCount;
}
