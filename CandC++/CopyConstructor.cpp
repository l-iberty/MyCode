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
	/* ������C3��copyConstructor, ��C1�����ݳ�Ա��ʼ��C3 */
	/* ע��: ��ִ�и����ǰC3��������, "�ø����һ�������ʼ���������һ������"
	   �������Ϊ: ��һ���Ѿ����ڵĶ���Ϊģ�洴��һ���¶���, Ҳֻ���ڴ������
	   ��������Ż����copyConstructor */
	cout << "C3:";
	C3.showTime();
	cout << "***" << endl;
	Clock::fun(C2);
	/* ��������ʱ�βζ���(��ջ�н���)��copyConstructor, ��ʵ��C2�ĸ������ݳ�Ա��ʼ���β� */
	/* Ȼ��ִ�к������� */
	/* ����Clock����ʱ, ������һ�����ڴ��淵��ֵ����ʱ����, �����βζ��󸳸�����ʱ��
	   ��, �����βζ����ʼ������ʱ����, �⽫���ø���ʱ�����copyConstructor, ������
	   �ζ����ʼ������ʱ���� */
	/* ����ջ�ռ����ȳ���ԭ��, �������ڴ��淵��ֵ����ʱ��������βζ�����ջ, ���
	   ����ʱ���������βζ����ջ(�����ڽ���), ����˳������������� */
	cout << "****" << endl;
	Clock C4;
	C4 = C2; // ��"Clock C4 = C2", ������copyConstructor, ������
	/* ����C4�Ѿ�����, "C4 = C2"ֻ�Ǽ򵥵ĸ�ֵ */
	cout << "C4:";
	C4.showTime();
	cout << "*****" << endl;
	return 0;
}
/* ������������, C4,C3,C2,C1���γ�ջ */