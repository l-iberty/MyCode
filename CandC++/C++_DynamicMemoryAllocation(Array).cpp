#include <iostream>
using namespace std;

int main()
{
	int len, i;
	cout << "len=? ";
	cin >> len;
	int *p = new int[len];

	if (p == NULL)
		cout << "Memory allocation error!" << endl;
	else {
		for (i = 0;i < len;i++)
			p[i] = i + 2;

		for (i = 0;i < len;i++)
			cout << p[i] << " ";
	}
	delete  []p;
	return 0;
}