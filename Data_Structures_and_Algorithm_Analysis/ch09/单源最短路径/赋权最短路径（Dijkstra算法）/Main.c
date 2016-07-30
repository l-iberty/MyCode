#include "Graph.h"
#include "Table.h"
#define NotAVertex -1

Table Dijkstra(Graph G);
Vertex FindSmallestDistVertex(Table T);

Table Dijkstra(Graph G) {
	Table T = initializeTable(G->NumOfVertex, 1);
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
					if (T->dist[V] + P->Cvw < T->dist[W]) {
						T->dist[W] = T->dist[V] + P->Cvw;
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

int main() {
	Graph G = initializeGraph(7);
	Table T;

	addVertex(G, 1, 2, 2);
	addVertex(G, 1, 4, 1);
	addVertex(G, 2, 4, 3);
	addVertex(G, 2, 5, 10);
	addVertex(G, 3, 1, 4);
	addVertex(G, 3, 6, 5);
	addVertex(G, 4, 3, 2);
	addVertex(G, 4, 5, 2);
	addVertex(G, 4, 6, 8);
	addVertex(G, 4, 7, 4);
	addVertex(G, 5, 7, 6);
	addVertex(G, 7, 6, 1);

	T = Dijkstra(G);
	displayTable(T);

	makeEmpty(G);
	disposeTable(T);

	return 0;
}