#ifndef DIJISKTRA_H
#define DIJISKTRA_H

typedef struct _List*					List;
typedef struct _List*					Position;
typedef struct _List*					VertexCell;
typedef struct _Graph*				Graph;
typedef struct _TableEntry*		TableEntry;

typedef char Vertex;
typedef int	BOOL;

/* Vertices are numbered from 'A' */
#define NotAVertex	('#')

#define INFINITE	100
#define TRUE		1
#define FALSE		0

struct _List {
	Vertex	V;
	int			Weight;
	List			Next;
};

struct _Graph {
	int		VertexNum;
	List*	Header;			/* Adjacency list */
};

struct _TableEntry {
	int			EntryNum;		/* 有多少个表项? */
	Vertex*	V;
	BOOL*	Known;
	int*			Dist;
	Vertex*	Path;
};

/* Opts for List */
List CreateList();
void List_Add(List L, Vertex V, int Weight);
void List_Disp(List L);
void List_Free(List L);

/* Opts for Graph */
Graph CreateGraph(int VertexNum);
void Graph_Add(Graph G, Vertex V, Vertex AdjToV, int Weight);
void Graph_Disp(Graph G);
void Graph_Free(Graph G);

/* Opts for TableEntry */
TableEntry CreateTblEntry(int VertexNum);
void TableEntry_Init(TableEntry T, Graph G);
void TableEntry_Disp(TableEntry T);
void TableEntry_Free(TableEntry T);

/* Dijikstra */
Vertex FindVertex(TableEntry T);  /* 查找未知的、Dist 最小的点 */
void Dijikstra(TableEntry T, Graph G, Vertex From);
void PrintPath(TableEntry T, Vertex From, Vertex To);

#endif // DIJISKTRA_H