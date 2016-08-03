#include <stdio.h>
#include "Graph.h"
#define true 1
#define false 0
typedef int boolean;

static boolean *visited;

void iniVisited(Graph G);
void Dfs(Graph G, Vertex startV);

void iniVisited(Graph G) {
	int i;

	visited = (boolean *)malloc(sizeof(boolean) * (G->NumOfVertex + 1));
	for (i = 1;i <= G->NumOfVertex;i++)
		visited[i] = false;
}

void Dfs(Graph G, Vertex startV) {
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
				Dfs(G, W);
				printf_s("Forward edge: (V%d,V%d)\n", startV, W);
			}
			else
				printf_s("Back edge: (V%d,V%d)\n", startV, W);

			P = P->nextVertex;
		}
	}
}

int main() {
	Graph G = initializeGraph(7);

	//addVertex(G, 1, 4, 1);
	addVertex(G, 1, 2, 1);
	//addVertex(G, 2, 1, 1);
	addVertex(G, 2, 3, 1);
	//addVertex(G, 3, 2, 1);
	addVertex(G, 3, 7, 1);
	addVertex(G, 3, 4, 1);
	addVertex(G, 4, 1, 1);
	//addVertex(G, 4, 3, 1);
	//addVertex(G, 4, 6, 1);
	addVertex(G, 4, 5, 1);
	//addVertex(G, 5, 4, 1);
	addVertex(G, 5, 6, 1);
	addVertex(G, 6, 4, 1);
	//addVertex(G, 6, 5, 1);
	//addVertex(G, 7, 3, 1);

	iniVisited(G);
	Dfs(G, 1);
	free(visited);

	return 0;
}