#include <iostream>
#include <vector>
using namespace std;

void delElement(int index, vector<int>& vec);

int main() {
	vector <int> Integer;

	for (int i = 0; i < 10; i++) 
		Integer.push_back(i + 1);

	for (int j = 0; j < Integer.size(); j++)
		cout << Integer[j] << " ";

	cout << endl;
	// using iterator
	vector<int>::iterator it = Integer.begin();
	// member function begin() returns an iterator
	while (it != Integer.end()) {
		size_t index = distance(Integer.begin(), it);
		// std::distance() calculates the offset of the element via begin() and an interator
		cout << "Index " << index << ": " << *it++ << endl;
	}

	delElement(4, Integer);
	cout << "size:" << Integer.size() << endl;
	for (int j = 0; j < Integer.size(); j++)
		cout << Integer[j] << " ";

	return 0;
}

void delElement(int index, vector<int>& vec) {
	vector<int>::iterator it = vec.begin();
	int i = 1;
	if (index == 1) 
		vec.erase(it);
	else if (index == vec.size())
		vec.pop_back();
	else {
		while (it++ != vec.end() && (i++) != index);
		vec.erase(--it);
	}
}