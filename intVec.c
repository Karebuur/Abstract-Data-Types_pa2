/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "intVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct IntVecNode
{
    int * data;
    int sz;
    int capacity;
}IntVecNode;

/*constructor*/
IntVec intMakeEmptyVec(void){
    IntVec newVec;
    newVec = calloc(1, sizeof(struct IntVecNode));
    newVec->data = calloc(intInitCap, sizeof(int));
    newVec->sz = 0;
    newVec->capacity = intInitCap;
    return newVec;
}

/*Access Functions*/
int intTop(IntVec myVec){
    int ret = 0; /*set the top = 0 as a default unless the sz > 0*/
    if (myVec->sz > 0)
    {
        ret = myVec->data[myVec->sz];
    }

    return ret;
}

int intData(IntVec myVec, int i){
    return myVec->data[i];
}

int intSize(IntVec myVec){
    return myVec->sz;
}

int intCapacity(IntVec myVec){
    return myVec->capacity;
}

/*Manipulation Procedures*/

void intVecPush(IntVec myVec, int newE){
    /* if the capacity is full, then implement array doubling */
    int newSz = intSize(myVec) + 1;
    int cap = intCapacity(myVec);
    int * newData;
    myVec->sz = newSz;

    /* if (sz + 1) > cap then double array capacity*/
    if(newSz >= cap){
        myVec->capacity = 2 * myVec->capacity;
        newData = realloc(myVec->data, myVec->capacity * sizeof(int));

	if( newData !=  myVec->data){
            myVec->data = newData;
        }
    }
    /*append new value onto the vector*/
    myVec->data[myVec->sz] = newE;
}

void intVecPop(IntVec myVec){
    int sz = intSize(myVec) - 1;
    int newTop;

    myVec->sz = sz;

    newTop = myVec->data[myVec->sz];
    intData(myVec, newTop);
}


void freeVector(IntVec myVec){
    free(myVec->data);
    free(myVec);
}


void freeAdjList (IntVec * adjList, int n){
    for(int i = 1; i <= n; i++){
        freeVector(adjList[i]);
    }
    free(adjList);
}



