#include <iostream>
#include <string>
using namespace std;

class People {
private:
	string name;
public:
	People(string inName) {
		cout << "Construct People" << endl;
		name = inName;
	}
	void show() {
		cout << name << endl;
	}
};

class Student {
private:
	string ID;
public:
	Student(string inID) {
		cout << "Construct Student" << endl;
		ID = inID;
	}
	void show() {
		cout << ID << endl;
	}
};

class Monitor :public People, public Student {
private:
	int group;
public:
	Monitor(string name, string ID, int inGroup) :People(name), Student(ID) {
		cout << "Constructor Monitor" << endl;
		group = inGroup;
	}
	void showMonitor() {
		People::show();
		Student::show();
		cout << group << endl;
	}
};

int main() {
	Monitor MT("Jack", "200302149", 3);
	// MT.show(); 二义性问题
	MT.showMonitor();

	return 0;
}