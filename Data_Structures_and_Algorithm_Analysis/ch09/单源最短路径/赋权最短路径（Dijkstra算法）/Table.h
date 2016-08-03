#ifndef _TABLE_H
#define _TABLE_H
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define Infinity 100

typedef struct ListTable *List;
typedef struct TableInfo *Table;
typedef int boolean;
typedef int Vertex;

Table initializeTable(int NumOfVertex, Vertex startV);
void displayTable(Table T);
void disposeTable(Table T);

struct TableInfo {
	int NumOfVertex;
	boolean *known;
	int *dist;
	Vertex *path;
};


Table initializeTable(int NumOfVertex, Vertex startV) {
	Table T;
	int i;

	T = (Table)malloc(sizeof(struct TableInfo));
	if (T != NULL) {
		T->NumOfVertex = NumOfVertex;
		T->dist = (int *)malloc(sizeof(int) * (NumOfVertex + 1));
		T->known = (boolean *)malloc(sizeof(boolean) * (NumOfVertex + 1));
		T->path = (int *)malloc(sizeof(int) * (NumOfVertex + 1));

		for (i = 1;i <= NumOfVertex;i++) {
			T->dist[i] = Infinity;
			T->known[i] = false;
			T->path[i] = 0;
		}
		T->dist[startV] = 0;
	}

	return T;
}

void displayTable(Table T) {
	int i;

	printf_s(" v\tknown\tdist\tpath\n");
	for (i = 1;i <= T->NumOfVertex;i++)
		printf_s(" %d\t%d\t%d\t%d\n", i, T->known[i], T->dist[i], T->path[i]);
}

void disposeTable(Table T) {
	free(T->dist);
	free(T->known);
	free(T->path);
	free(T);
}
#endif _TABLE_H