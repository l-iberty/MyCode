/*�麯����virtual function�������������뺯����֮�����ϵ������ʱ�Ž�������ʵ�ֶ�̬����Ļ�����
�麯����������֮�󣬿�����������ʵ������ʱ�Ķ�̬��
��̬�����ڳ������еĹ����У�����ָ��������ʵ��ָ���Ŀ����ö�Ӧ�ĺ�����Ҳ�����ڳ�������ʱ�ž�����ζ�����
*/
#include <iostream>
#include <string>
using namespace std;

class A {
public:
	virtual string toString() {
		return "Class A";
	}
};

class B :public A {
public:
	string toString() {
		return "Class B";
	}
};

class C :public B {
public:
	string toString() {
		return "Class C";
	}
};

void displayObject(A *p) {
	cout << p->toString() << endl;
}

void displayObject(A &p) {
	cout << p.toString() << endl;
}
/*void displayObject(A p) {
cout << p.toString() << endl;
}*/

int main() {
	A a;
	B b;
	C c;
	displayObject(a); // Class A
	displayObject(b); // Class B
	displayObject(c); // Class C
	/*������37�еĺ����������Class A*/

	displayObject(&a); // Class A
	displayObject(&b); // Class B
	displayObject(&c); // Class C
	/*ͨ���麯��ʵ�ֶ�̬������Ҫ��������������
       1.Ӧ�������ͼ��ݹ��򣨹��м̳У�
       2.�ڻ����ж����麯���������������������¶����麯��
       3.Ҫͨ��ָ�롢���÷����麯��
    */

	return 0;
}

/*Tips:
��B��C��toString()ǰ�Ӳ���virtual��һ������������A��toString()Ҫ����Ϊvitual
��Ϊ������麯��������̳к����麯��������ֻ������д�麯����������಻��
д������麯�������޷�ʵ�ֶ�̬����*/