#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
static ElementType A[16] = { 1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16 };

void merge(ElementType A[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd);
void mSort(ElementType A[], ElementType tmpArray[], int Left, int Right);
void mergeSort(ElementType A[], int N);

void merge(ElementType A[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd) {
	int i, LeftEnd, numElements, tmpPos;

	LeftEnd = Rpos - 1;
	tmpPos = Lpos;
	numElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd) {
		if (A[Lpos] <= A[Rpos])
			tmpArray[tmpPos++] = A[Lpos++];
		else
			tmpArray[tmpPos++] = A[Rpos++];
	}

	while (Lpos <= LeftEnd)
		tmpArray[tmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		tmpArray[tmpPos++] = A[Rpos++];

	/* Copy tmpArray back */
	for (i = 0;i < numElements;i++, RightEnd--)
		A[RightEnd] = tmpArray[RightEnd];
}

void mSort(ElementType A[], ElementType tmpArray[], int Left, int Right) {
	int Center;

	if (Left < Right) {
		Center = (Left + Right) / 2;
		mSort(A, tmpArray, Left, Center);
		mSort(A, tmpArray, Center + 1, Right);
		merge(A, tmpArray, Left, Center + 1, Right);
	}
}

void mergeSort(ElementType A[], int N) {
	ElementType *tmpArray;

	tmpArray = (ElementType *)malloc(sizeof(ElementType) * N);
	if (tmpArray != NULL) {
		mSort(A, tmpArray, 0, N - 1);
		free(tmpArray);
	}
}

int main() {
	int i;

	mergeSort(A, 16);
	for (i = 0;i < 16;i++)
		printf_s("%d ", A[i]);

	return 0;
}