#include "Graph.h"
#include "Queue.h"

typedef int *TopNum;

int countIndegree(Graph G, Vertex V);
void indegreeCounter(Graph G);
TopNum topSort(Graph G);

int countIndegree(Graph G, Vertex V) {
	int i;
	int count = 0;
	List P;

	for (i = 1;i <= G->NumOfVertex;i++) {
		P = G->AdjVertex[i]->nextVertex;
		while (P != NULL) {
			if (P->vertex == V)
				count++;
			P = P->nextVertex;
		}
	}
	return count;
}

void indegreeCounter(Graph G) {
	int i;

	for (i = 1;i <= G->NumOfVertex;i++)
		G->Indegree[i] = countIndegree(G, G->V[i]);
}

TopNum topSort(Graph G) {
	Queue Q;
	Vertex V, W;
	int i, count = 1;
	TopNum topNum;
	List Header, P;

	Q = createQueue();
	for (i = 1;i <= G->NumOfVertex;i++) {
		if (G->Indegree[i] == 0)
			enqueue(G->V[i], Q);
	}

	topNum = (TopNum)malloc(sizeof(int) * (G->NumOfVertex + 1));
	while (!isEmpty(Q)) {
		V = dequeue(Q);
		topNum[V] = count++;

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
				if (--G->Indegree[W] == 0)
					enqueue(W, Q);

				P = P->nextVertex;
			}
			// while将所有与V邻接的顶点的indegree减1
		}
	}

	if (--count != G->NumOfVertex) {
		printf_s("\nGraph has a circle\n");
		disposeQueue(Q);
		return NULL;
	}
	disposeQueue(Q);
	return topNum;
}

int main() {
	Graph G = initialize(7);
	TopNum A;
	int i;

	addVertex(G, 1, 2);
	addVertex(G, 1, 4);
	addVertex(G, 1, 3);
	addVertex(G, 2, 4);
	addVertex(G, 2, 5);
	addVertex(G, 3, 6);
	addVertex(G, 4, 6);
	addVertex(G, 4, 7);
	addVertex(G, 4, 3);
	addVertex(G, 5, 4);
	addVertex(G, 5, 7);
	addVertex(G, 7, 6);

	/*addVertex(G, 1, 2);
	addVertex(G, 1, 4);
	addVertex(G, 1, 3);
	addVertex(G, 2, 5);
	addVertex(G, 3, 6);
	addVertex(G, 4, 2);
	addVertex(G, 4, 6);
	addVertex(G, 4, 7);
	addVertex(G, 4, 3);
	addVertex(G, 5, 4);
	addVertex(G, 5, 7);
	addVertex(G, 7, 6);*/

	indegreeCounter(G);
	display(G);

	printf_s("\n\nTopSort:\n");
	A = topSort(G);
	for (i = 1;A != NULL && i <= G->NumOfVertex;i++)
		printf_s("V%d ", A[i]);

	makeEmpty(G);
	return 0;
}