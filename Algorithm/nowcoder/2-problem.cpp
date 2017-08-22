// 基于左老师的讲解
// https://www.nowcoder.com/live/11/1/1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) ((a > b) ? b : a)
#define max(a,b) ((a > b) ? a : b)

#define LEN 12

int arr[LEN] = { 0,1,0,2,1,0,1,3,2,1,2,1 };

void print_arr(int *arr, int len)
{
	for (int i = 0;i < len;i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// 使用辅助数组 L[LEN], R[LEN]
void solve_1()
{
	int L[LEN], R[LEN];
	int i, _max = 0;

	for (i = 0;i < LEN;i++)
	{
		_max = max(_max, arr[i]);
		L[i] = _max;
	}

	_max = 0;
	for (i = LEN - 1;i >= 0;i--)
	{
		_max = max(_max, arr[i]);
		R[i] = _max;
	}

	print_arr(arr, LEN);
	print_arr(L, LEN);
	print_arr(R, LEN);

	int water_tol = 0;

	for (i = 1;i < LEN - 1;i++)
	{
		water_tol += max(0, (min(L[i - 1], R[i + 1]) - arr[i]));
	}
	printf("water_tol: %d\n", water_tol);
}

// 仅使用辅助数组 R[LEN]
void solve_2()
{
	int R[LEN];
	int i, _max = 0;

	for (i = LEN - 1;i >= 0;i--)
	{
		_max = max(_max, arr[i]);
		R[i] = _max;
	}

	int water_tol = 0;
	int left_max = 0;
	for (i = 1;i < LEN - 1;i++)
	{
		left_max = max(left_max, arr[i - 1]);
		water_tol += max(0, (min(left_max, R[i + 1]) - arr[i]));
	}
	printf("water_tol: %d\n", water_tol);
}

int main()
{
	// solve_1();
	solve_2();
}