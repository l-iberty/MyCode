#include<iostream>
using   namespace std;

class Automobile {  //汽车类
private:
	int power;   //马力

public:
	Automobile(int power){
		this->power = power;
	}

	void show(){
		cout << "  power:" << power;
	}
};

class Car :  public Automobile {  //小客车类
private:
	int seat;     //座位

public:
	Car(int power, int seat) :Automobile(power){
		this->seat = seat;
	}

	void show(){
		cout << "car:";
		Automobile::show();
		cout << "  seat:" << seat << endl;
	}
};

class Wagon :  public Automobile {  //小货车类
private:
	int load;     //装载量

public:
	Wagon(int power, int load) : Automobile(power){
		this->load = load;
	}
	void show(){
		cout << "wagon:";
		Automobile::show();
		cout << "  load:" << load << endl;
	}
};

class StationWagon :public Car, public Wagon  {  //客货两用车类
public:
	StationWagon(int CPower, int WPower, int seat, int load)
		:Wagon(WPower, load), Car(CPower, seat){}

	void show() {
		cout << "StationWagon:" << endl;
		Car::show();
		Wagon::show();
	}
};


int main() {
	StationWagon SW(105, 108, 3, 8);
	SW.show();
	return 0;
}
// 基类 Automobile 的成员power在内存中有两个不同的拷贝，否则输出结果中两辆车的power为105