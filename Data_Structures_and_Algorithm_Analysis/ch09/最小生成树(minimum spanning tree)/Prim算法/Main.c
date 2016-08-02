#include "Graph.h"
#include "Table.h"
#define NotAVertex -1

Table Prim(Graph G, Vertex startV);
Vertex FindSmallestDistVertex(Table T);
void showEdgeAndValue(Table T);

Table Prim(Graph G, Vertex startV) {
	Table T = initializeTable(G->NumOfVertex, startV);
	Vertex V, W;
	List Header, P;
	int i;

	for (;;) {
		V = FindSmallestDistVertex(T);
		if (V == NotAVertex)
			break;

		T->known[V] = true;
		for (i = 1, Header = NULL;i <= G->NumOfVertex;i++) {
			W = G->V[i];
			if (W == V) {
				Header = G->AdjVertex[i];
				break;
			}
		}

		if (Header != NULL) {
			P = Header->nextVertex;
			while (P != NULL) {
				W = P->vertex;
				if (!T->known[W])
					if (T->dist[W] > P->Cvw) {
						T->dist[W] = P->Cvw;
						T->path[W] = V;
					}
				P = P->nextVertex;
			}
		}
	}

	return T;
}

Vertex FindSmallestDistVertex(Table T) {
	Vertex V = NotAVertex;
	int i, dist; // dist is the distance of unknown vertex

	for (dist = Infinity, i = 1;i <= T->NumOfVertex;i++)
		if (!T->known[i] && T->dist[i] < dist) {
			dist = T->dist[i];
			V = i;
		}

	return V;
}

void showEdgeAndValue(Table T) {
	int i, value;

	for (i = 1, value = 0;i <= T->NumOfVertex;i++)
		if (T->path[i] != 0) {
			printf_s("(V%d,V%d)\n", i, T->path[i]);
			value += T->dist[i];
		}
	printf_s("Value: %d\n", value);
}

int main() {
	Graph G = initializeGraph(7);
	Table T;

	addVertex(G, 1, 2, 2);
	addVertex(G, 1, 4, 1);
	addVertex(G, 1, 3, 4);

	addVertex(G, 2, 1, 2);
	addVertex(G, 2, 4, 3);
	addVertex(G, 2, 5, 10);

	addVertex(G, 3, 1, 4);
	addVertex(G, 3, 4, 2);
	addVertex(G, 3, 6, 5);

	addVertex(G, 4, 1, 1);
	addVertex(G, 4, 2, 3);
	addVertex(G, 4, 3, 2);
	addVertex(G, 4, 5, 7);
	addVertex(G, 4, 6, 8);
	addVertex(G, 4, 7, 4);

	addVertex(G, 5, 2, 10);
	addVertex(G, 5, 4, 7);
	addVertex(G, 5, 7, 6);

	addVertex(G, 6, 3, 5);
	addVertex(G, 6, 4, 8);
	addVertex(G, 6, 7, 1);

	addVertex(G, 7, 5, 6);
	addVertex(G, 7, 4, 4);
	addVertex(G, 7, 6, 1);

	T = Prim(G, 1);
	displayTable(T);
	showEdgeAndValue(T);

	makeEmpty(G);
	return 0;
}