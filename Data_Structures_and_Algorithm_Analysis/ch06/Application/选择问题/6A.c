#include <stdio.h>
#include <stdlib.h>
#define MIN -1

static int SIZE = 15;

int Arrays[15 + 1] = { MIN, 150,80,40,30,10,70,110,100,
									20,90,60,50,120,140,130 };

void buildHeap();
void percolateUp(int index);
int deleteMax();
void display();

void buildHeap() {
	int i;

	for (i = SIZE / 2;i > 0;i--)
		percolateUp(i);
}

void percolateUp(int index) {
	int i, child, temp;

	for (i = index;i / 2 > 0;i /= 2) {
		child = i * 2;
		/* Find the bigger child */
		if (child <= SIZE && Arrays[child + 1] > Arrays[child])
			child++;

		if (Arrays[child] > Arrays[i]) {
			temp = Arrays[child];
			Arrays[child] = Arrays[i];
			Arrays[i] = temp;
		}
	}
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

void display() {
	int i;

	for (i = 1;i <= SIZE;i++)
		printf_s("%d ", Arrays[i]);
}

int main() {
	int i, k;

	buildHeap();
	display();

	k = 15;
	for (i = 1;i <= k;i++) {
		printf_s("\n");
		deleteMax();
		display();
	}

	return 0;
}