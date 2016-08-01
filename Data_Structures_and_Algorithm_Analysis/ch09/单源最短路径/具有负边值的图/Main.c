#include "Graph.h"
#include "Table.h"
#include "Queue.h"

Table weightedNegative(Graph G, Vertex startV);

Table weightedNegative(Graph G, Vertex startV) {
	Table T = initializeTable(G->NumOfVertex, startV);
	Queue Q = createQueue();
	Vertex V, W;
	List Header, P;
	int i;

	enqueue(startV, Q);
	T->isInTheQueue[startV] = true;

	while (!isQueueEmpty(Q)) {
		V = dequeue(Q);
		T->isInTheQueue[V] = false;
		T->dequeueCounter[V]++;

		/* 处理负值圈 */
		if (T->dequeueCounter[V] == G->NumOfVertex + 1)
			break;

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
				if (T->dist[V] + P->Cvw < T->dist[W]) {
					T->dist[W] = T->dist[V] + P->Cvw;
					T->path[W] = V;
					if (!T->isInTheQueue[W]) {
						/* W is not in the queue */
						enqueue(W, Q);
						T->isInTheQueue[W] = true;
					}
				}
				P = P->nextVertex;
			}/* while P != NULL */
		}
	}/*while queue is not empty */

	disposeQueue(Q);
	return T;
}

int main() {
	Graph G = initializeGraph(7);
	Table T;

	addVertex(G, 1, 2, 2);
	addVertex(G, 1, 4, 1);
	addVertex(G, 2, 5, -10);
	addVertex(G, 3, 1, 4);
	addVertex(G, 3, 6, 5);
	addVertex(G, 4, 2, 3);
	addVertex(G, 4, 3, 2);
	addVertex(G, 4, 6, 8);
	addVertex(G, 4, 7, 4);
	addVertex(G, 5, 4, 2);
	addVertex(G, 5, 7, 6);
	addVertex(G, 7, 6, 1);

	T = weightedNegative(G, 1);
	displayTable(T);

	makeEmpty(G);
	disposeTable(T);

	return 0;
}