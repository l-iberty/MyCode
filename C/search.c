# include <stdio.h>

void sort(int array[], int length); // 如果 const int array[], 表示函数无法修改它，它具有只读性质 
int search(int key, int array[], int length);

int main(void)
{
	int s[10] = {2,5,1,7,4,9,8,10,0,13};
	int k;
	
	sort(s, 10);
	
	for(k = 0; k < 10; k++)
		printf("%d ", s[k]);
		
	int e = search(7, s, 10);
	
	printf("\nIndex: %d", e);
}

void sort(int array[], int length)
{
	int i,j,tmp;
	
	for(i = 1; i < length; i++)
		for(j = 0; j < length - 1; j++)
			if(array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}

int search(int key, int array[], int length)
{
	int low = 0;
	int	high = length - 1;
	int mid;
			
	while(low <= high)
	{
		mid = (low + high) / 2;
		
		if(key == array[mid])
			break;
		else if(key > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	if(key == array[mid])
		return mid;
	else
		return -1; 
}
