#include <iostream>
#include <string>
using namespace std;

class Clock {
private:
	int H, M, S;
	string name;
public:
	Clock(){}
	Clock(string inName, int inH, int inM, int inS) {
		name = inName;
		H = inH;
		M = inM;
		S = inS;
		cout << name << " Constructor: " << H << ":" << M << ":" << S << endl;
	}

	Clock(Clock &p) {
		cout << "CopyConstructor, before called: " << H << ":" << M << ":" << S << " name: "<< name << endl;
		name = p.name;
		H = p.H;
		M = p.M;
		S = p.S;
		cout << "CopyConstructor, after called: " << H << ":" << M << ":" << S << " name: " << name << endl;
	}

	~Clock() {
		cout << name << " Destructor: " << H << ":" << M << ":" << S << endl;
	}

	void showTime() {
		cout << name << " showTime() called: " << H << ":" << M << ":" << S << endl;
	}

	static Clock fun(Clock C) {
		cout << "fun() called." << endl;
		return C;
	}
};

int main() {
	Clock C1("C1", 8, 0, 0);
	Clock C2("C2", 9, 0, 0);
	cout << "**" << endl;
	Clock C3(C1);
	/* 将调用C3的copyConstructor, 用C1各个据成员初始化C3 */
	/* 注意: 在执行该语句前C3并不存在, "用该类的一个对象初始化该类的另一个对象"
	   可以理解为: 用一个已经存在的对象为模版创建一个新对象, 也只有在此情况下
	   创建对象才会调用copyConstructor */
	cout << "C3:";
	C3.showTime();
	cout << "***" << endl;
	Clock::fun(C2);
	/* 将调用临时形参对象(在栈中建立)的copyConstructor, 用实参C2的各个数据成员初始化形参 */
	/* 然后执行函数代码 */
	/* 返回Clock对象时, 建立了一个用于储存返回值的临时对象, 并将形参对象赋给该临时对
	   象, 即用形参对象初始化该临时对象, 这将调用该临时对象的copyConstructor, 并用形
	   参对象初始化该临时对象 */
	/* 按照栈空间后进先出的原则, 由于用于储存返回值的临时对象后于形参对象入栈, 因此
	   该临时对象先于形参对象出栈(生命期结束), 依此顺序调用析构函数 */
	cout << "****" << endl;
	Clock C4;
	C4 = C2; // 若"Clock C4 = C2", 将调用copyConstructor, 如上述
	/* 由于C4已经存在, "C4 = C2"只是简单的赋值 */
	cout << "C4:";
	C4.showTime();
	cout << "*****" << endl;
	return 0;
}
/* 主函数结束后, C4,C3,C2,C1依次出栈 */