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

		// �ƶ�����ָ���ԭ��:
		// s �� distance �� height ��ͬ����, �� left_idx ���� 1 ����λ�� right_idx ���� 1 ����λ
		// �� distance ��Ӱ������ͬ��, ���Ӧ���ƶ� left_idx �� right_idx ��Ӧ��ʹ��ԭ���� arr[left_idx]
		// �� arr[right_idx] �еĽ�С�߱���̭.
		if (arr[left_idx] < arr[right_idx])
			left_idx++;
		else
			right_idx--;
	}
	printf("(%d, %d), max_s: %d\n", idx_1, idx_2, max_s);
}