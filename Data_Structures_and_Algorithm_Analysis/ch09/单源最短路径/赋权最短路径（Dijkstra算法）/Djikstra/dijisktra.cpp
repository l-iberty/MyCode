#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dijikstra.h"

#define min(a,b) ((a<b)?a:b)

/* Opts for List */
List CreateList() {
	List L = NULL;

	L = (List)malloc(sizeof(struct _List));
	if (L != NULL)
		L->Next = NULL;
	else
		printf("CreateList error\n");

	return L;
}

void List_Add(List L, Vertex V, int Weight) {
	List New_Cell = NULL;

	New_Cell = (List)malloc(sizeof(struct _List));
	if (New_Cell != NULL) {
		New_Cell->V = V;
		New_Cell->Weight = Weight;
		New_Cell->Next = L->Next;
		L->Next = New_Cell;
	}
	else {
		printf("List_Add error\n");
	}
}

void List_Disp(List L) {
	for (Position P = L->Next;P;P = P->Next)
		printf("%c(%d) ", P->V, P->Weight);
	printf("\n");
}

void List_Free(List L) {
	Position P, AfterP;

	P = L;
	while (P != NULL) {
		AfterP = P->Next;
		free(P);
		P = AfterP;
	}
}

/* Opts for Graph */
Graph CreateGraph(int VertexNum) {
	Graph G = NULL;

	G = (Graph)malloc(sizeof(struct _Graph));
	if (G != NULL) {
		G->VertexNum = VertexNum;
		G->Header = (List*)malloc(sizeof(List) * VertexNum);
		if (G->Header != NULL) {
			for (int i = 0;i < VertexNum;i++)
				G->Header[i] = CreateList();
		}
	}
	else
		printf("CreateGraph error\n");

	return G;
}

void Graph_Add(Graph G, Vertex V, Vertex AdjToV, int Weight) {
	int VertexNo = V - 'A';
	G->Header[VertexNo]->V = V;
	List_Add(G->Header[VertexNo], AdjToV, Weight);
}

void Graph_Disp(Graph G) {
	printf("---------- Graph ---------\n");
	for (int i = 0;i < G->VertexNum;i++) {
		printf("%c -> ", G->Header[i]->V);
		List_Disp(G->Header[i]);
	}
}

void Graph_Free(Graph G) {
	for (int i = 0;i < G->VertexNum;i++)
		List_Free(G->Header[i]);
	free(G->Header);
}

/* Opts for TableEntry */
TableEntry CreateTblEntry(int VertexNum) {
	TableEntry T = NULL;

	T = (TableEntry)malloc(sizeof(struct _TableEntry));
	if (T != NULL) {
		T->EntryNum = VertexNum;
		T->V = (Vertex*)malloc(sizeof(Vertex) * VertexNum);
		T->Known = (BOOL*)malloc(sizeof(BOOL) * VertexNum);
		T->Dist = (int*)malloc(sizeof(int) * VertexNum);
		T->Path = (Vertex*)malloc(sizeof(Vertex) * VertexNum);
	}
	else
		printf("CreateTblEntry error\n");

	return T;
}

void TableEntry_Init(TableEntry T, Graph G) {
	for (int i = 0;i < T->EntryNum;i++) {
		T->V[i] = G->Header[i]->V;
		T->Known[i] = FALSE;
		T->Dist[i] = INFINITE;
		T->Path[i] = NotAVertex;
	}
}

void TableEntry_Disp(TableEntry T) {
	printf("--------- TableEntry ---------\n");
	printf("V\tKnown\tDist\tPath\n");

	for (int i = 0;i < T->EntryNum;i++) {
		printf("%c\t%d\t%d\t%c\n",
			T->V[i], T->Known[i], T->Dist[i], T->Path[i]);
	}
}

void TableEntry_Free(TableEntry T) {
	free(T->V);
	free(T->Known);
	free(T->Dist);
	free(T->Path);
	free(T);
}

/* Dijikstra */
Vertex FindVertex(TableEntry T) {
	int i, temp;
	Vertex V = NotAVertex;

	temp = INFINITE;
	for (i = 0;i < T->EntryNum;i++) {
		if (!T->Known[i] && T->Dist[i] <= temp) {
			temp = T->Dist[i];
			V = T->V[i];
		}
	}
	return V;
}

void Dijikstra(TableEntry T, Graph G, Vertex From) {
	int FromNo = From - 'A';
	T->Dist[FromNo] = 0;

	Vertex V, W;
	for (int i=0;;i++) {
		/* Display table */
		printf("\n---------- Step %d ----------\n", i);
		TableEntry_Disp(T);

		V = FindVertex(T); /* V = smallest unknown distance vertex */
		if (V == NotAVertex)
			break;
		T->Known[V - 'A'] = TRUE;  /* 标记为'已知' */

		/* for all W adjacent to V */
		List Header = G->Header[V - 'A']; /* 定位到 V 的邻接表 */
		for (Position P = Header->Next;P;P = P->Next) {
			W = P->V;																					/* w is adjacent to v */
			if (!T->Known[W - 'A']) {															/* if w is unknown */	
				if (T->Dist[V - 'A'] + P->Weight < T->Dist[W - 'A']) {	/* then if D(v)+C(v,w)<D(w) */
					T->Dist[W - 'A'] = T->Dist[V - 'A'] + P->Weight;		/*			 then update: D(w)=D(v)+C(v,w) */
					T->Path[W - 'A'] = V;														/*									 P(w)=v */
				}
			}
		}
	}
}

void PrintPath(TableEntry T, Vertex From, Vertex To) {
	if (From != To) {
		PrintPath(T, From, T->Path[To - 'A']);
		printf(" -> ");
	}
	printf("%c", To);
}

int main() {
	Graph G = CreateGraph(7);

	Graph_Add(G, 'A', 'B', 8);
	Graph_Add(G, 'A', 'C', 12);

	Graph_Add(G, 'B', 'A', 8);
	Graph_Add(G, 'B', 'C', 6);
	//Graph_Add(G, 'B', 'E', 3);
	Graph_Add(G, 'B', 'F', 6);

	Graph_Add(G, 'C', 'A', 12);
	Graph_Add(G, 'C', 'B', 6);
	Graph_Add(G, 'C', 'D', 7);
	Graph_Add(G, 'C', 'E', 8);

	Graph_Add(G, 'D', 'C', 7);
	Graph_Add(G, 'D', 'E', 4);
	Graph_Add(G, 'D', 'G', 2);

	//Graph_Add(G, 'E', 'B', 3);
	Graph_Add(G, 'E', 'C', 8);
	Graph_Add(G, 'E', 'D', 4);
	Graph_Add(G, 'E', 'F', 4);
	Graph_Add(G, 'E', 'G', 3);

	Graph_Add(G, 'F', 'B', 6);
	Graph_Add(G, 'F', 'E', 4);
	Graph_Add(G, 'F', 'G', 3);

	Graph_Add(G, 'G', 'D', 2);
	Graph_Add(G, 'G', 'E', 3);
	Graph_Add(G, 'G', 'F', 3);

	Graph_Disp(G);

	TableEntry T = CreateTblEntry(G->VertexNum);
	TableEntry_Init(T, G);
	//TableEntry_Disp(T);

	Dijikstra(T, G, 'B');
	PrintPath(T, 'B', 'E');

	TableEntry_Free(T);
	Graph_Free(G);

	return 0;
}