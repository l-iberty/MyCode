#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 100000
typedef int ElementType;

ElementType median3(ElementType A[], int Left, int Right);
void qsort(ElementType A[], int Left, int Right);
void quicksort(ElementType A[], int N);
void swap(ElementType &a, ElementType &b);
void setArray(ElementType A[], int N);

ElementType median3(ElementType A[], int Left, int Right) {
	int Center = (Left + Right) / 2;

	if (A[Left] > A[Center])
		swap(A[Left], A[Center]);
	if (A[Left] > A[Right])
		swap(A[Left], A[Right]);
	if (A[Center] > A[Right])
		swap(A[Center], A[Right]);

	swap(A[Center], A[Right - 1]);
	return A[Right - 1];
}

void qsort(ElementType A[], int Left, int Right) {
	int i, j;
	ElementType pivot;

	if ((Right - Left + 1) > 1) {
		pivot = median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;) {
			while (A[++i]<pivot) {}
			while (A[--j]>pivot) {}
			if (i < j)
				swap(A[i], A[j]);
			else
				break;
		}
		swap(A[i], A[Right - 1]);

		qsort(A, Left, i - 1);
		qsort(A, i + 1, Right);
	}
}

void quicksort(ElementType A[], int N) {
	qsort(A, 0, N - 1);
}

void swap(ElementType &a, ElementType &b) {
	ElementType t;
	t = a;
	a = b;
	b = t;
}

void setArray(ElementType A[], int N) {
	int i;

	srand(100);
	for (i = 0;i < SIZE;i++)
		A[i] = rand();
}

int main() {
	time_t start, end;
	ElementType A[SIZE];

	setArray(A, SIZE);
	start = time(0);
	quicksort(A, SIZE);
	end = time(0);
	cout << "quick sort: " << end - start << endl;

	return 0;
}