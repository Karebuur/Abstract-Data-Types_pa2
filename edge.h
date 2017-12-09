/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/

/** edge.h
* The purpose of this header file is to contain additional function declarations
* that are to be used amongst multiple files, which are not already declared in
* intVec.h This is so that the original intVec.h is not changed.
*/

#include "intVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED


typedef struct {
    int from;
    int to;
    double weight;
} Edge;

/** precondition: A file must have been opened
*   postcondition: The file input is being stored onto the Edge struct as
*                  /to/ , /from/ , /weight/
*/
Edge parseEdge(char line [], int nodes);

/** precondition: File must have been opened with proper data
*   postcondition: Calls parse edge to store data into the struct
*                Then returns the edge count
*                if (flag == 0)
*                   intVecPush(adjList[e.from], e.to)
*                else
*                    intVecPush(adjList[e.from], e.to)
*                    intVecPush(adjList[e.to, e.from)
*
*/
int pushEdges(char * ret, char line[], IntVec adjList[], int n, FILE * fp, int flag);



/*Additional Functions in intVec.c */

/**
* precondition: myVec has been constructed
* postcondition:
*       The contents of each individual vector is printed
*/
void printVector(IntVec myVec);

/**precondition: none
*  postconditions; Rids program of memory leaks
*       1.data in the current vector is freed
*           free(myVec->data
*       2.the vector itself is freed
*           free(myVec)
*/
void freeVector(IntVec myVec);

/**preconditions:none
* postconditions: Calls freeVector in the for loop to clear memory
*           Then free's the adjacency list
*/
void freeAdjList(IntVec * adjList, int n);


void printAdjList ( IntVec * adjList, int n);

#endif
