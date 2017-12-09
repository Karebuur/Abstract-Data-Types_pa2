/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "intVec.h"
#include "edge.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef LOADGRAPH_H_INCLUDED
#define LOADGRAPH_H_INCLUDED

/** precondition: Adjacency List must have been created
*   postcondition: Takes in the values from the original adjacency list
*                   then pushes the value into a temporary vector
*                   returns back the transposed data
*                   intVecPush(intData(origGraph[k], i));
*/
IntVec* transposeGraph(IntVec* origGraph, int n);

/** precondition: Adjacency list must have been created
*   postcondition: Takes in values from the adjacency list being passed
*                   Then it stores them into a 2D array.
*/
int** makeAdjMatrix(IntVec* adjList, int n);

/* precondition: Adjacency Matrix has been created
*  postcondition: prints out the adjacency matrix
*/
void printAdjMatrix(int** A, int n);

/* precondition: Adjacency matrix is created
*  postcondition: Prints out the adjacency list
*/
void printAdjVerts(IntVec* adjList, int n);




#endif
