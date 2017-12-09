#Karen Cariaga
#CruzID: kccariag
#pa2 makefile


CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE


graph02:	graph02.o  intVec.o  loadGraph.o  edge.o
	${CC}  -o graph02  ${CFLAGS} graph02.o  intVec.o  loadGraph.o  edge.o

edge:	edge.o  graph02.o
	${CC}  -o edge  ${CFLAGS} graph02.o  intVec.o

loadGraph:	loadGraph.o  graph02.o
	${CC}  -o loadGraph  ${CFLAGS} graph02.o  intVec.o

graph02.o:	graph02.c  intVec.h  edge.h loadGraph.h
	${CC}  -c ${CFLAGS} graph02.c

edge.o:	edge.c  intVec.h  edge.h loadGraph.h
	${CC}  -c ${CFLAGS} edge.c

intVec.o:	intVec.c  intVec.h  edge.h loadGraph.h
	${CC}  -c  ${CFLAGS}  intVec.c

loadGraph.o:	loadGraph.c  intVec.h  edge.h  loadGraph.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

clean:
	rm -f *.o
	rm -f "graph02"

