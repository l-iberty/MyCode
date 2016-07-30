#include "Stack.h"
#include "Queue.h"
#include "Graph.h"
#include "Table.h"

Table unweightedPathLength(Graph G, Vertex startV);
void showPath(Table T, Vertex start, Vertex end);

Table unweightedPathLength(Graph G, Vertex startV) {
	Table T;
	Queue Q;
	Vertex V, W;
	List Header, P;
	int i;

	Q = createQueue();
	T = initializeTable(G->NumOfVertex, startV);
	enqueue(startV, Q);

	while (!isQueueEmpty(Q)) {
		V = dequeue(Q);
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
				if (T->dist[W] == Infinity) {
					T->dist[W] = T->dist[V] + 1;
					T->path[W] = V;
					enqueue(W, Q);
				}
				P = P->nextVertex;
			}
		}
	}

	disposeQueue(Q);
	return T;
}

void showPath(Table T, Vertex start, Vertex end) {
	Stack S;
	Vertex V;

	S = createStack();
	V = end;
	while (V != start) {
		push(V, S);
		V = T->path[V];
	}
	push(V, S);

	while (!isStackEmpty(S)) {
		printf_s("V%d ", top(S));
		pop(S);
	}
	disposeStack(S);
}


int main() {
	Graph G = initializeGraph(7);
	Table T;

	addVertex(G, 3, 1);
	addVertex(G, 3, 6);
	addVertex(G, 1, 2);
	addVertex(G, 1, 4);
	addVertex(G, 2, 4);
	addVertex(G, 2, 5);
	addVertex(G, 4, 3);
	addVertex(G, 4, 6);
	addVertex(G, 4, 7);
	addVertex(G, 4, 5);
	addVertex(G, 5, 7);
	addVertex(G, 7, 6);

	T = unweightedPathLength(G, 3);
	displayTable(T);
	printf_s("\n");
	printf_s("V3->V7:\n");
	showPath(T, 3, 7);

	makeEmpty(G);
	disposeTable(T);

	return 0;
}