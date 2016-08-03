#include <stdio.h>
#include "Graph.h"
#define true 1
#define false 0
#define NotAVertex -1
typedef int boolean;

static int count = 1;
static boolean *visited;
static int *num;
static int *low;
static Vertex *parent;

void assignNum(Graph G, Vertex startV);
void assignLow(Graph G, Vertex startV);
void findArt(Graph G, Vertex startV);
void initialize(Graph G);
void iniVisited(Graph G);
void dispose();

void assignNum(Graph G, Vertex startV) {
	Vertex W;
	List Header, P;
	int i;

	num[startV] = count++;
	visited[startV] = true;

	for (i = 1, Header = NULL;i <= G->NumOfVertex;i++) {
		W = G->V[i];
		if (W == startV) {
			Header = G->AdjVertex[i];
			break;
		}
	}
	if (Header != NULL) {
		P = Header->nextVertex;
		while (P != NULL) {
			W = P->vertex;
			if (!visited[W]) {
				parent[W] = startV;
				assignNum(G, W);
			}
			P = P->nextVertex;
		}
	}
}

void assignLow(Graph G, Vertex startV) {
	Vertex W;
	List Header, P;
	int i;

	low[startV] = num[startV]; /* initialization */

	for (i = 1, Header = NULL;i <= G->NumOfVertex;i++) {
		W = G->V[i];
		if (W == startV) {
			Header = G->AdjVertex[i];
			break;
		}
	}
	if (Header != NULL) {
		P = Header->nextVertex;
		while (P != NULL) {
			W = P->vertex;
			if (num[W] > num[startV]) { /* forwards edge */
				assignLow(G, W);
				low[startV] = min(low[startV], low[W]);
			}
			else /* back edge */
				low[startV] = min(low[startV], num[W]);

			P = P->nextVertex;
		}
	}
}

void findArt(Graph G, Vertex startV) {
	Vertex W;
	List Header, P;
	int i;

	visited[startV] = true;

	for (i = 1, Header = NULL;i <= G->NumOfVertex;i++) {
		W = G->V[i];
		if (W == startV) {
			Header = G->AdjVertex[i];
			break;
		}
	}
	if (Header != NULL) {
		P = Header->nextVertex;
		while (P != NULL) {
			W = P->vertex;
			if (!visited[W]) {
				if (low[W] >= num[startV] && num[startV] != 1)
					printf_s("\nArticulation point found: %d\n", startV);

				findArt(G, W);
			}
			P = P->nextVertex;
		}
	}
}

void initialize(Graph G) {
	int i;

	visited = (boolean *)malloc(sizeof(boolean) * (G->NumOfVertex + 1));
	num = (int *)malloc(sizeof(int) * (G->NumOfVertex + 1));
	low = (int *)malloc(sizeof(int) * (G->NumOfVertex + 1));
	parent = (Vertex *)malloc(sizeof(Vertex) * (G->NumOfVertex + 1));

	for (i = 1;i <= G->NumOfVertex;i++) {
		visited[i] = false;
		parent[i] = NotAVertex;
	}
}

void iniVisited(Graph G) {
	int i;

	for (i = 1;i <= G->NumOfVertex;i++)
		visited[i] = false;
}

void dispose() {
	free(visited);
	free(num);
	free(low);
	free(parent);
}

int main() {
	Graph G;
	int i;
	G = initializeGraph(7);
	initialize(G);

	addVertex(G, 1, 2, 1);
	addVertex(G, 2, 3, 1);
	addVertex(G, 3, 7, 1);
	addVertex(G, 3, 4, 1);
	//addVertex(G, 3, 7, 1); 顺序不同编号也不同
	addVertex(G, 4, 5, 1);
	addVertex(G, 5, 6, 1);

	// Add back-edges
	addVertex(G, 4, 1, 1);
	addVertex(G, 6, 4, 1);

	assignNum(G, 1);
	assignLow(G, 1);

	printf_s("Num:\n");
	for (i = 1;i <= G->NumOfVertex;i++)
		printf_s("%d ", num[i]);

	printf_s("\nParent:\n");
	for (i = 1;i <= G->NumOfVertex;i++)
		printf_s("%d ", parent[i]);

	printf_s("\nLow:\n");
	for (i = 1;i <= G->NumOfVertex;i++)
		printf_s("%d ", low[i]);

	iniVisited(G);
	findArt(G, 1);

	dispose();
	return 0;
}