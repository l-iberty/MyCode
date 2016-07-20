#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define MIN -1

int Arrays[SIZE + 1] = { MIN, 150,80,40,30,10,70,110,100,
									20,90,60,50,120,140,130 };

void buildHeap();
void percolateDown(int index);
void display();

void buildHeap() {
	int i;

	for (i = SIZE / 2;i > 0;i--)
		percolateDown(i);
}

void percolateDown(int index) {
	int i, child, temp;

	for (i = index;i * 2 <= SIZE;i = child) {
		child = i * 2;
		if (child <= SIZE && Arrays[child + 1] < Arrays[child])
			child++;

		if (child <= SIZE && Arrays[i] > Arrays[child]) {
			temp = Arrays[i];
			Arrays[i] = Arrays[child];
			Arrays[child] = temp; 
		}
	}
}

void display() {
	int i;

	for (i = 1;i <= SIZE;i++)
		printf_s("%d ", Arrays[i]);
}

int main() {
	buildHeap(Arrays);
	display(Arrays);

	return 0;
}