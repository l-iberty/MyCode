#include <iostream>
#include <string>
using namespace std;

class Clock {
private:
	int H, M, S;
	string name;
public:
	Clock() {}
	Clock(string inName, int inH, int inM, int inS) {
		name = inName;
		H = inH;
		M = inM;
		S = inS;
		cout << name << " Constructor: " << H << ":" << M << ":" << S << endl;
	}

	Clock(Clock &p) {
		cout << "CopyConstructor, before called: " << H << ":" << M << ":" << S << " name: " << name << endl;
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
	/* 返回Clock对象时, 在堆中建立了一个用于储存返回值的临时对象, 并将形参对象赋给该
	   临时对象, 这将调用该临时对象的copyConstructor,并用形参对象初始化该临时对象 */
	/* 函数调用结束时, 形参对象先消失, 用于储存返回值得临时对象后消失(为什么是这个顺序?) */
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

/* 拷贝构造函数和对象赋值的区别:
   拷贝构造函数是用一个已存在的对象去构造另一个原本不存在的对象;
   对象赋值是两个对象已存在, 用一个对象去覆盖另一个对象 */
/* 注意:
   (1)拷贝构造函数只是在用一个已存在的对象为模板去构造一个新对象时调用,
      在这种构造进行前,"新对象"是不存在的, 这种构造开始时, 尚未被初始化
	  的"新对象"被建立, 立即调用其拷贝构造函数, 并以那个"已存在的对象"
	  为模板对其进行初始化. 因此, 函数调用时将实参对象赋给形参对象, 之所
	  以会调用形参对象的拷贝构造函数正是由于实参对象已存在而形参对象原本
	  并不存在; 同样地, 在处理返回值时, 充当返回值的临时对象原本也不存在,
	  在用已存在的形参对象初始化该临时对象时必调用临时对象的拷贝构造函数.
   (2)如果是在两个已存在的对象之间赋值, 由于两者都已存在, 构造函数和拷贝
      构造函数都不再被调用.
   (3)建立对象时, 构造函数和拷贝构造函数有且仅有一个被调用.
   (4)形如"fun(Clock C("C0", 1, 1, 1))"的函数调用, 只会调用基类的构造函数,
      建立的对象直接就成为形参对象;  形如"return Clock("C0", 2, 2, 2)"的返
	  回语句, 不存在所谓的"临时对象", 建立的对象直接作为返回值.
*/