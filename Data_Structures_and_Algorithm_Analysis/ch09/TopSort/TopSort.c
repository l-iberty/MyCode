#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
typedef struct GraphTable *Graph;
typedef struct ListTable *List;
typedef int *TopNum;

typedef Vertex ElementType;
typedef struct QueueDemo *Queue;

struct GraphTable {
	Vertex *V; // All the vertexes
	int NumOfVertex;
	int *Indegree; // The indegrees of all the vertexes
	List *AdjVertex; // The adjacent vertexes of all the vertexes
};

struct ListTable {
	Vertex vertex;
	List nextVertex;
};

struct QueueDemo {
	ElementType data;
	struct QueueDemo *next;
};

/* Graph */
Graph initialize(int NumOfVertex);
int countIndegree(Graph G, Vertex V);
void indegreeCounter(Graph G);
void addVertex(Graph G, Vertex V, Vertex AdjacentToV);
void display(Graph G);
void makeEmpty(Graph G);
TopNum topSort(Graph G);

/* Queue */
Queue createQueue();
int isEmpty(Queue Q);
void enqueue(ElementType inData, Queue Q);
ElementType dequeue(Queue Q);
void disposeQueue(Queue Q);

/* Graph */
Graph initialize(int NumOfVertex) {
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

void addVertex(Graph G, Vertex V, Vertex AdjacentToV) {
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
		}
	}
}

void display(Graph G) {
	List Header, P;
	int i;

	for (i = 1;i <= G->NumOfVertex;i++) {
		Header = G->AdjVertex[i];
		printf_s("\nV%d(indegree = %d): ", G->V[i], G->Indegree[i]);

		P = Header->nextVertex;
		while (P != NULL) {
			printf_s("%d ", P->vertex);
			P = P->nextVertex;
		}
	}
}

void makeEmpty(Graph G) {
	free(G->AdjVertex);
	free(G->Indegree);
	free(G->V);
	free(G);
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
/* Graph ends */

/* Queue */
Queue createQueue() {
	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueDemo));
	if (Q == NULL)
		return NULL;
	else {
		Q->next = NULL;
		return Q;
	}
}

int isEmpty(Queue Q) {
	return Q->next == NULL;
}

void enqueue(ElementType inData, Queue Q) {
	Queue rear, current;

	rear = (Queue)malloc(sizeof(struct QueueDemo));
	if (rear == NULL)
		printf_s("Enqueue Failed");
	else {
		rear->data = inData;
		rear->next = NULL;
	}

	current = Q;
	while (current->next != NULL)
		current = current->next;

	current->next = rear;
}

ElementType dequeue(Queue Q) {
	Queue Front;
	ElementType Item;
	
	Front = Q->next;
	Item = Front->data;
	Q->next = Q->next->next;
	free(Front);

	return Item;
}

void disposeQueue(Queue Q) {
	Queue P, AfterP;
	
	P = Q;
	while (P != NULL) {
		AfterP = P->next;
		free(P);
		P = AfterP;
	}
}
/* Queue ends */

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
	for (i = 1;A!=NULL && i <= G->NumOfVertex;i++)
		printf_s("V%d ", G->V[i]);
	
	makeEmpty(G);
	return 0;
}