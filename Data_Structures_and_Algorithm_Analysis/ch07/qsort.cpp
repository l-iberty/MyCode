#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 10
typedef int ElementType;

ElementType median3(ElementType A[], int Left, int Right);
void inline swap(ElementType &a, ElementType &b);
void qsort(ElementType A[], int Left, int Right);
void quicksort(ElementType A[], int N);
void insertsort(ElementType A[], int N);
void bubblesort(ElementType A[], int N);
void setArray(ElementType A[], int N);
void printArray(ElementType A[], int N);


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

void inline swap(ElementType &a, ElementType &b) {
	ElementType t;
	t = a;
	a = b;
	b = t;
}

void qsort(ElementType A[], int Left, int Right) {
	int i, j;
	ElementType pivot;
#define CutOff (3)
	if (Left + CutOff <= Right)
	{
		pivot = median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;)
		{
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}
			if (i < j)
				swap(A[i], A[j]);
			else
				break;
		}
		swap(A[i], A[Right - 1]);

		qsort(A, Left, i - 1);
		qsort(A, i + 1, Right);
	}
	else
		insertsort(A + Left, Right - Left + 1);
}

void quicksort(ElementType A[], int N) {
	qsort(A, 0, N - 1);
}

void insertsort(ElementType A[], int N)
{
	int i, j;
	ElementType tmp;
	for (i = 1;i < N;i++)
	{
		tmp = A[i];
		for (j = i;j > 0 && A[j - 1]>tmp;j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}

void bubblesort(ElementType A[], int N)
{
	int i, j;
	for (i = 1;i < N;i++)
	{
		for (j = 0;j < N - i;j++)
		{
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
}

void setArray(ElementType A[], int N) {
	srand(100);
	for (int i = 0;i < SIZE;i++)
		A[i] = rand();
}

void printArray(ElementType A[], int N)
{
	for (int i = 0;i < N;i++)
		cout << A[i] << " ";
	cout << endl;
}

int main() {
	ElementType A[SIZE];
	setArray(A, SIZE);
	printArray(A, SIZE);
	quicksort(A, SIZE);
	//bubblesort(A, SIZE);
	//insertsort(A, SIZE);
	printArray(A, SIZE);
}