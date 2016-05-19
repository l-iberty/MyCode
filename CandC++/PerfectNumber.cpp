#include <iostream>
using namespace std;

int main() {
	int i, k, sum, n;
	cin >> n;

	for (i = 2; i < n; i++) {
		sum = 0;
		for (k = 1;k < i;k++) {
			if (i % k == 0)
				sum += k;
		}
		if (sum == i)
			cout << i << " ";
	}

	return 0;
}