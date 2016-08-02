#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
typedef struct GraphTable *Graph;
typedef struct ListTable *List;

Graph initializeGraph(int NumOfVertex);
void addVertex(Graph G, Vertex V, Vertex AdjacentToV, int Cvw);
/* Cvw is the weight of the path from V to AdjacentToV */
void makeEmpty(Graph G);

struct GraphTable {
	Vertex *V; // All the vertexes
	int NumOfVertex;
	int *Indegree; // The indegrees of all the vertexes
	List *AdjVertex; // The adjacent vertexes of all the vertexes
};

struct ListTable {
	Vertex vertex;
	int Cvw;
	List nextVertex;
};


Graph initializeGraph(int NumOfVertex) {
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

void addVertex(Graph G, Vertex V, Vertex AdjacentToV, int Cvw) {
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
			NewVertex->Cvw = Cvw;
		}
	}
}

void makeEmpty(Graph G) {
	free(G->AdjVertex);
	free(G->Indegree);
	free(G->V);
	free(G);
}