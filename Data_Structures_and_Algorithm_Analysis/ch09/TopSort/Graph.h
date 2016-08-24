#ifndef _GRAPH_H
#define _GRAPH_H
#include <stdlib.h>
#include <stdio.h>

typedef int Vertex;
typedef struct GraphTable *Graph;
typedef struct ListTable *List;

Graph initialize(int NumOfVertex);
void addVertex(Graph G, Vertex V, Vertex AdjacentToV);
void display(Graph G);
void makeEmpty(Graph G);

struct GraphTable {
	Vertex *V; // All the vertexes
	int NumOfVertex;
	int *Indegree; // The indegrees of all the vertexes
	List *AdjVertex; // The adjacent vertexes of all the vertexes
};

struct ListTable {
	Vertex vertex;
	List nextVertex;
};

Graph initialize(int NumOfVertex) {
	Graph G;
	int SIZE = NumOfVertex + 1;
	int i;

	G = (Graph)malloc(sizeof(struct GraphTable));
	if (G != NULL) {
		G->V = (Vertex *)malloc(sizeof(Vertex) * SIZE);
		G->NumOfVertex = NumOfVertex;
		G->Indegree = (int *)malloc(sizeof(int) * SIZE);
		for (i = 1;i <= NumOfVertex;i++) {
			G->V[i] = i;
			G->Indegree[i] = -1;
		}

		G->AdjVertex = (List *)malloc(sizeof(List) * SIZE);
		for (i = 1;i <= NumOfVertex;i++) {
			G->AdjVertex[i] = (List)malloc(sizeof(struct ListTable));
			if (G->AdjVertex[i] != NULL)
				G->AdjVertex[i]->nextVertex = NULL;
		}
	}

	return G;
}

void addVertex(Graph G, Vertex V, Vertex AdjacentToV) {
	List NewVertex, Header;
	Vertex W;
	int i;

	for (i = 1, Header = NULL;i <= G->NumOfVertex;i++) {
		W = G->V[i];
		if (W == V) {
			Header = G->AdjVertex[i];
			break;
		}
	}

	if (Header != NULL) {
		NewVertex = (List)malloc(sizeof(struct ListTable));
		if (NewVertex != NULL) {
			NewVertex->nextVertex = Header->nextVertex;
			Header->nextVertex = NewVertex;
			NewVertex->vertex = AdjacentToV;
		}
	}
}

void display(Graph G) {
	List Header, P;
	int i;

	for (i = 1;i <= G->NumOfVertex;i++) {
		Header = G->AdjVertex[i];
		printf_s("\nV%d(indegree = %d): ", G->V[i], G->Indegree[i]);

		P = Header->nextVertex;
		while (P != NULL) {
			printf_s("%d ", P->vertex);
			P = P->nextVertex;
		}
	}
}

void makeEmpty(Graph G) {
	free(G->AdjVertex);
	free(G->Indegree);
	free(G->V);
	free(G);
}
#endif // _GRAPH_H