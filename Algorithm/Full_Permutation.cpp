#include <iostream>
using namespace std;

void perm(int arr[], int begin, int end);
void swap(int &x, int &y);
bool IsSwap(int arr[], int begin, int current);

int main() {
	int end;
	int begin = 0;
	cout << "end=? ";
	cin >> end;
	int *arr = new int[end + 1];

	cout << "Enter the elements of the sequence:" << endl;
	for (int i = 0; i <= end; i++)
		cin >> arr[i];

	cout << "The full permutation:" << endl;
	perm(arr, begin, end);
	delete[]arr;
	return 0;
}

// "begin" is the index of the first element
// "end" is the index of the last element
void perm(int arr[], int begin, int end) {
	if (begin == end) {
		for (int i = 0; i <= end; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	/*递归出口说明:
	函数调用perm(arr, begin, end)的含义是:对arr序列的
	begin~end的元素进行全排列,因此,若begin==end,
	则直接输出该序列.
	*/
	else {
		for (int j = begin; j <= end; j++) {
			if ( IsSwap(arr, begin, j) ) {
				swap(arr[begin], arr[j]);
				perm(arr, begin + 1, end);
				swap(arr[begin], arr[j]);
			}
			/*递归过程说明:
			 j 标记当前位置.首先将当前位置j的元素置换到全排列的
			 起点begin,然后对起点begin以后的元素进行全排列,排
			 列结束后恢复位置j和位置begin的元素.j指向下一个元素,
			 重复上述过程.
			 */
			/* 重复问题的解决:
			从以上分析可见,将元素j与元素begin进行交换之前,从begin
			到j-1的元素都与begin做过交换(包含begin),如果元素j与这
			部分元素中任何一个相等,那么元素j与begin交换后进行的全
			排列与之前的某一次是完全等价的,所以要除去之.*/
		}
	}
}

void swap(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

bool IsSwap(int arr[], int begin, int current) {
	for (int i = begin; i < current; i++) {
		if (arr[current] == arr[i])
			return false;
	}
	return true;
}