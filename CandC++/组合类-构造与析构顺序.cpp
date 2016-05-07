#include <iostream>
using namespace std;

class Demo {
public:
	Demo(){
		cout << "Demo's Constructor" << endl;
	}
	~Demo() {
		cout << "Demo's Destructor" << endl;
	}
};

class TestDemo {
private:
	Demo demo = Demo();
	//Demo demo;
public:
	TestDemo(){
		cout << "TestDemo's Constructor" << endl;
	}
	~TestDemo() {
		cout << "TestDemo's Destructor" << endl;
	}
};

int main() {
	TestDemo TD;
	return 0;
}

