#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream rfile, wfile;
	char ch;
	rfile.open("demo.cpp", ios_base::in);
	wfile.open("msg.txt", ios_base::out);

	if (rfile.is_open() && wfile.is_open()) {
		while (!rfile.eof()) {
			ch = rfile.get();
			//rfile >> ch; 这回自动跳过换行符
			cout << ch;
			//wfile.put(ch);
			wfile << ch;
		}
		rfile.close();
		wfile.close();
	}

	return 0;
}