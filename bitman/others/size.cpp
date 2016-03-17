# include <stdio.h>

int main(void)
{
	char charArray[2] = {0};
	short shortArray[2] = {0};
	int intArray[2] = {0};
	long longArray[2] = {0};
	long long longlongArray[2] = {0};
	float floatArray[2] = {0};
	double doubleArray[2] = {0};
	
	puts("Method 1, using \"sizeof()\":\n");
	printf("The size of \"char\" is %d Bytes\n", sizeof(char));
	printf("The size of \"short\" is %d Bytes\n", sizeof(short));
	printf("The size of \"int\" is %d Bytes\n", sizeof(int));
	printf("The size of \"long\" is %d Bytes\n", sizeof(long));
	printf("The size of \"long long\" is %d Bytes\n", sizeof(long long));
	printf("The size of \"float\" is %d Bytes\n", sizeof(float));
	printf("The size of \"double\" is %d Bytes\n", sizeof(double));
	
	puts("----------------------------------------------------------");
	puts("\nMethod 2, using pointer and array:");
	printf("\n(1) <char> The address of the first element and the second element is\n");
	printf("%d\t%d", charArray, charArray+1);
	
	printf("\n\n(2) <short> The address of the first element and the second element is\n");
	printf("%d\t%d", shortArray, shortArray+1);
	
	printf("\n\n(3) <int> The address of the first element and the second element is\n");
	printf("%d\t%d", intArray, intArray+1);
	
	printf("\n\n(4) <long> The address of the first element and the second element is\n");
	printf("%d\t%d", longArray, longArray+1);
	
	printf("\n\n(5) <long long> The address of the first element and the second element is\n");
	printf("%d\t%d", longlongArray, longlongArray+1);
	
	printf("\n\n(6) <float> The address of the first element and the second element is\n");
	printf("%d\t%d", floatArray, floatArray+1);
	
	printf("\n\n(7) <double> The address of the first element and the second element is\n");
	printf("%d\t%d", doubleArray, doubleArray+1);	
}
