# include <stdio.h>

float max, min;
float fun(float msg[], int length);

int main(void)
{
	float average;
	float a1[5] = {100, 78.4, 98.3, 56, 60};
	float a2[9] = {89, 58, 67, 69, 99, 92.5, 77, 82, 93.4};
	
	average = fun(a1, 5);
	printf("<a1> max:%5.1f min:%5.1f ave:%5.2f\n", max, min, average);
	average = fun(a2, 9);
	printf("<a2> max:%5.1f min:%5.1f ave:%.2f", max, min, average);
	
	return 0;
}

float fun(float msg[], int length)
{
	int i;
	float sum = 0, ave;
	max = msg[0];
	min = msg[0];
	
	for(i = 0; i < length; i++)
	{
		if(max < msg[i])
			max = msg[i];
		if(min > msg[i])
			min = msg[i];
			
		sum += msg[i];
	}
	
	ave = sum / length;
	
	return ave;
}
