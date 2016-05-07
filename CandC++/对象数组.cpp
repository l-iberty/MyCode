#include <iostream>
using namespace std;

class Score {
private:
	float Chinese, math, physics, ave;
public:
	Score(float inChinese, float inMath, float inPhy) {
		Chinese = inChinese;
		math = inMath;
		physics = inPhy;
	}
	Score() {}

	float average() {
		return (Chinese + math + physics) / 3;
	}
};

int main() {
	// Score score[] = { Score(67.5,89,77.6),Score(89,99.4,55.7),Score(66,57,85) };
	// 其实C++对象数组的初始化只能这样
	
	Score score[3]; // 已经创建了3个对象
	// C++的对象名字和java一样,是一种隐式指针
	score[0] = Score(67.5, 89, 77.6);
	score[1] = Score(89, 99.4, 55.7);
	score[2] = Score(66, 57, 85);
	// Java: Score[] score = new Score[3];
	//       score[0] = new Score(67.5, 89, 77.6);
 
	for (int i = 0;i < 3;i++)
		cout << score[i].average() << endl;

	return 0;
}