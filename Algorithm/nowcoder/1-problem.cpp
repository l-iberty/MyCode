// 最长递增子序列
// https://www.nowcoder.com/live/11/1/1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

#define LEN 8
int arr[LEN] = { 2,1,6,4,5,2,7,4 };

void print_arr(int *arr, int len)
{
	printf("\nprint_arr: ");
	for (int i = 0;i < len;i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// 在数组 arr 中寻找第一个大于 x 的元素, 返回其下标
// @return len if not found
int find(int x, int *arr, int len)
{
	int left, right, mid;

	left = 0;
	right = len - 1;
	while (right >= left)
	{
		mid = (left + right) / 2;
		if (arr[mid] > x)
			right = mid - 1;
		else if (arr[mid] <= x)
			left = mid + 1;
	}
	return left;
}

// O(N^2) 使用辅助数组 H[LEN]
void solve_1()
{
	int H[LEN];
	int i, k, max_val, max_idx;

// H[i] = arr 从 0 -> i 范围内的最长递增子序列的长度
// 显然, H[LEN - 1] = arr 的最长递增子序列的长度

//	loop i: 1 -> N-1
//		find max value in H[0...(i-1)], assume as H[k]
//		if arr[k] < arr[i]
//			H[i] = H[k] + 1
//		else
//			H[i] = H[k]
// end loop

	H[0] = 1;
	max_val = 1;
	for (i = 1;i < LEN;i++)
	{
		for (k = 0;k < i;k++)
		{
			if (H[k] >= max_val)
			{
				max_val = H[k];
				max_idx = k;
			}
		}

		H[i] = H[max_idx];
		if (arr[i] > arr[max_idx])
			H[i]++;
	}
	print_arr(H, LEN);
}

// O(N*logN)
// H[i] = 遍历到数组 arr 的位置 i 时, 长度为 (i+1) 的最长递增子序列的最小末尾
void solve_2()
{
	int H[LEN];
	int i, k; // k = 有效区的末尾元素下标
	int max_seq_len = 1;

// loop i: 1 -> LEN-1
//		idx = find(arr[i], H, k+1) /* (k+1) = 有效区的长度 */
//		if idx == FOUND
//			H[idx] = arr[i]
//			max_seq_len = max(max_seq_len, idx + 1)
//		if idx == NOT_FOUND
//			H[++k] = arr[i]
//			max_seq_len = max(max_seq_len, k + 1) /* (k+1) = 有效区的长度 */
// end loop
// return max_seq_len;

	H[0] = arr[0];
	k = 0;
	for (i = 1;i < LEN;i++)
	{
		int idx = find(arr[i], H, k + 1);
		if (idx != k + 1)
		{
			H[idx] = arr[i];
			max_seq_len = max(max_seq_len, idx + 1);
		}
		else
		{
			H[++k] = arr[i];
			max_seq_len = max(max_seq_len, k + 1);
		}
	}
	printf("max_seq_len = %d\n", max_seq_len);
	print_arr(H, LEN);
}

int main()
{
	//solve_1();
	solve_2();
}