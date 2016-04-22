/**
* 析构函数:
* 1.通常是public，函数名前是bitwise-NOT运算符:~;
* 2.不能重载，但可以是虚函数;
* 3.无参数，无返回类型;
* 4.当对象结束其生命周期时(例如对象所在的函数已调用完毕)，
*   系统自动执行析构函数.
**/

#include <iostream>
using namespace std;

class Clock {
	private:
		int hour, min, sec;

	public:
		Clock(int inHour, int inMin, int inSec) {
			hour = inHour;
			min = inMin;
			sec = inSec;

			cout << "Constructor: " << hour << ":" << min << ":" << sec << endl;
		}

		~Clock() {
			cout << "Destructor: " << hour << ":" << min << ":" << sec << endl;
		}
};

Clock C1(1, 0, 0);
Clock C2(2, 0, 0);

int main() {
	Clock C3(3, 0, 0);
	Clock C4(4, 0, 0);

	return 0;
}

/* 堆：先进先出 */
/* 栈：先进后出 */
/* 从输出结果推测，对象位于栈空间 */
