#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) ((a > b) ? b : a)

#define LEN 4

int main()
{
	//int arr[LEN] = { 1,2,3,6,5,3,4,1 };
	int arr[LEN] = { 3,4,2,5 };
	int left_idx = 0, right_idx = LEN - 1;
	int max_s = 0;
	int idx_1, idx_2;

	while (left_idx != right_idx)
	{
		int distance = right_idx - left_idx - 1;
		int height = min(arr[left_idx], arr[right_idx]);
		int s = distance*height;
		if (s > max_s)
		{
			max_s = s;
			idx_1 = left_idx;
			idx_2 = right_idx;
		}

		// 移动左右指针的原则:
		// s 由 distance 和 height 共同决定, 而 left_idx 右移 1 个单位和 right_idx 左移 1 个单位
		// 对 distance 的影响是相同的, 因此应该移动 left_idx 或 right_idx 后应该使得原本的 arr[left_idx]
		// 和 arr[right_idx] 中的较小者被淘汰.
		if (arr[left_idx] < arr[right_idx])
			left_idx++;
		else
			right_idx--;
	}
	printf("(%d, %d), max_s: %d\n", idx_1, idx_2, max_s);
}