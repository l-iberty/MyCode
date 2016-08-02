typedef int Vertex;
typedef Vertex ElementType;
typedef int Root;
typedef int *DisjSet;

DisjSet initializeSet(int NumOfElements);
Root find(DisjSet S, ElementType key);
void setUnion(DisjSet S, Root root1,Root root2);
void disposeSet(DisjSet S);

DisjSet initializeSet(int NumOfElements){
	DisjSet S;
	int i;

	S = (int *)malloc(sizeof(int) * (NumOfElements + 1));
	if (S != NULL)
		for (i = 1;i <= NumOfElements;i++)
			S[i] = 0;

	return S;
}

Root find(DisjSet S, ElementType key){
	if (S[key] == 0)
		return key;/* key is the root */
	else
		return find(S, S[key]);
}

void setUnion(DisjSet S, Root root1,Root root2){
	S[root2] = root1;
}

void disposeSet(DisjSet S){
	free(S);
}