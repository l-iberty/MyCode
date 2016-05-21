#include <iostream>
using namespace std;
class Integer{
private:
	int *p;

	void expand(int offset) {
		int *pi = new int[length + offset];
		for (int i = 0; i < length + offset; i++)
			pi[i] = 0;
		for (int i = 0; i < length; i++)
			pi[i] = p[i];

		delete[]p;
		p = pi;
		length += offset;
	}

public:
	int length;

	Integer(int length) {
		this->length = length;
		p = new int[length];
		for (int i = 0; i < length; i++)
			p[i] = 0;
	}
	~Integer() {
		delete[]p;
	}

	int& operator [](int index) {
		if (index < length)
			return p[index];
		else {
			expand(index - length + 1);
			return p[index];
		}
	}
};

int main() {
	Integer array(6);
	int length = array.length;
	for (int i = 0; i < array.length; i++)
		array[i] = i + 1;
	for (int i = 0; i < length+4; i++)
		cout << array[i] << endl;

	return 0;
}