#include "Graph.h"
#include "PriorityQueue.h"
#include "DisjSet.h"
#define NotAVertex -1

void Kruskal(Graph G, PriorityQueue H);
void setUV(Graph G, Edge edge, Vertex *U, Vertex *V);

void Kruskal(Graph G, PriorityQueue H) {
	int edgeAccepted = 0;
	DisjSet S;
	Vertex U, V;
	Root USet, VSet;
	Edge edge;

	S = initializeSet(G->NumOfVertex);
	U = V = NotAVertex;
	while (edgeAccepted < G->NumOfVertex - 1) {
		edge = deleteMin(H); /* edge = (U, V) */

		setUV(G, edge, &U, &V);
		if (U != NotAVertex && V != NotAVertex) {
			USet = find(S, U);
			VSet = find(S, V);
		}
		
		if (USet != VSet) {
			/* Accept the edge */
			printf_s("edge:%d", edge);
			printf_s("  (V%d,V%d)\n", U, V);

			edgeAccepted++;
			setUnion(S, USet, VSet);
		}
	}
}

void setUV(Graph G, Edge edge, Vertex *U, Vertex *V) {
	List Header, P;
	Vertex tmpV;
	int i;
	boolean flag1;

	for (i = 1, flag1 = true;i <= G->NumOfVertex && flag1;i++) {
		tmpV = G->V[i];
		Header = G->AdjVertex[i];

		P = Header->nextVertex;
		while (P != NULL) {
			if (!P->known && P->Cvw == edge) {
				*U = tmpV;
				*V = P->vertex;
				P->known = true;
				/* 退出for和while */
				flag1 = false;
				break;
			}
			P = P->nextVertex;
		}/* while */
	}/* for */
}

int main() {
	Graph G;
	PriorityQueue H;
	int NumOfEdges = 12;
	int NumOfVertex = 7;
	Edge e[12] = { 2,4,1,3,10,2,7,5,8,4,6,1 };
	int i;

	H = initializeQueue(NumOfEdges);
	for (i = 0;i < NumOfEdges;i++)
		insert(e[i], H);

	G = initializeGraph(NumOfVertex);
	addVertex(G, 1, 2, 2);
	addVertex(G, 1, 4, 1);
	addVertex(G, 1, 3, 4);

	//addVertex(G, 2, 1, 2);
	addVertex(G, 2, 4, 3);
	addVertex(G, 2, 5, 10);

	//addVertex(G, 3, 1, 4);
	addVertex(G, 3, 4, 2);
	addVertex(G, 3, 6, 5);

	//addVertex(G, 4, 1, 1);
	//addVertex(G, 4, 2, 3);
	//addVertex(G, 4, 3, 2);
	addVertex(G, 4, 5, 7);
	addVertex(G, 4, 6, 8);
	addVertex(G, 4, 7, 4);

	//addVertex(G, 5, 2, 10);
	//addVertex(G, 5, 4, 7);
	addVertex(G, 5, 7, 6);

	//addVertex(G, 6, 3, 5);
	//addVertex(G, 6, 4, 8);
	addVertex(G, 6, 7, 1);

	//addVertex(G, 7, 5, 6);
	//addVertex(G, 7, 4, 4);
	//addVertex(G, 7, 6, 1);
	/* 重复的输入在Kruskal算法中会造成Bug */

    Kruskal(G, H);

	return 0;
}