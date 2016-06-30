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
	/*�ݹ����˵��:
	��������perm(arr, begin, end)�ĺ�����:��arr���е�
	begin~end��Ԫ�ؽ���ȫ����,���,��begin==end,
	��ֱ�����������.
	*/
	else {
		for (int j = begin; j <= end; j++) {
			if ( IsSwap(arr, begin, j) ) {
				swap(arr[begin], arr[j]);
				perm(arr, begin + 1, end);
				swap(arr[begin], arr[j]);
			}
			/*�ݹ����˵��:
			 j ��ǵ�ǰλ��.���Ƚ���ǰλ��j��Ԫ���û���ȫ���е�
			 ���begin,Ȼ������begin�Ժ��Ԫ�ؽ���ȫ����,��
			 �н�����ָ�λ��j��λ��begin��Ԫ��.jָ����һ��Ԫ��,
			 �ظ���������.
			 */
			/* �ظ�����Ľ��:
			�����Ϸ����ɼ�,��Ԫ��j��Ԫ��begin���н���֮ǰ,��begin
			��j-1��Ԫ�ض���begin��������(����begin),���Ԫ��j����
			����Ԫ�����κ�һ�����,��ôԪ��j��begin��������е�ȫ
			������֮ǰ��ĳһ������ȫ�ȼ۵�,����Ҫ��ȥ֮.*/
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