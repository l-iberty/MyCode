#include <stdio.h>
#include <stdlib.h>
#define MIN -1

static int SIZE = 15;

int Arrays[15 + 1] = { MIN, 150,80,40,30,10,70,110,100,
20,90,60,50,120,140,130 };

void percolateUp(int index);
int deleteMax();
void heapSort();

void percolateUp(int index) {
	int i, child, temp;

	temp = Arrays[index];
	for (i = index;i * 2 <= SIZE;i = child) {
		child = i * 2;
		/* Find the bigger child */
		if (child <= SIZE && Arrays[child + 1] > Arrays[child])
			child++;

		if (child <= SIZE && temp < Arrays[child])
			Arrays[i] = Arrays[child];
		else
			break;
	}
	Arrays[i] = temp;
}

int deleteMax() {
	int max, last, i, child;

	max = Arrays[1];
	last = Arrays[SIZE--];
	for (i = 1;i * 2 <= SIZE;i = child) {
		child = i * 2;
		/* Find the bigger child */
		if (child <= SIZE && Arrays[child + 1] > Arrays[child])
			child++;

		if (child <= SIZE && last < Arrays[child])
			Arrays[i] = Arrays[child];
		else
			break;
	}
	Arrays[i] = last;

	return max;
}

void heapSort() {
	int i;

	for (i = SIZE / 2;i > 0;i--)
		percolateUp(i); /* Build heap */

	for (i = SIZE;i > 0;i--)
		Arrays[i] = deleteMax();
}

int main() {
	int i;

	heapSort();
	for (i = 1;i <= 15;i++)
		printf_s("%d ", Arrays[i]);

	return 0;
}