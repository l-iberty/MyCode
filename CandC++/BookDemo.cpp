#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class Book {
private:
	string name, ID, author, edYear;
public:
	Book(string name, string ID, string author, string edYear) {
		this->name = name;
		this->ID = ID;
		this->author = author;
		this->edYear = edYear;
	}

	string getName() {
		return name;
	}
	string getID() {
		return ID;
	}
	string getAuthor() {
		return author;
	}
	string getEdYear() {
		return edYear;
	}
};

class Library {
private:
	vector<Book> booklist;
	char TmpName[3][20], TmpID[3][20], TmpAuthor[3][20], TmpEdYear[3][20];

	void readFile() {
		fstream fp;
		char str[15][30];
		int ch, i, j, offset, strn;
		int namel, IDl, authorl, edYearl;

		fp.open("books.txt", ios_base::in);
		if (!fp.is_open())
			cout << "Error" << endl;

		i = 0;
		while ((ch = fp.get()) != EOF) {
			j = 0;
			while (ch != '\n' && ch != EOF) {
				str[i][j++] = ch;
				ch = fp.get();
			}
			str[i++][j] = '\0';
		}
		fp.close();
		strn = i;

		namel = IDl = authorl = edYearl = 0;
		for (i = 0; i < strn; i++) {
			if (str[i][0] == 'N') {
				offset = 6;
				j = 0;
				while (str[i][offset]) {
					TmpName[namel][j++] = str[i][offset++];
				}
				TmpName[namel][j] = '\0';
				namel++;
			}
			if (str[i][0] == 'I') {
				offset = 4;
				j = 0;
				while (str[i][offset]) {
					TmpID[IDl][j++] = str[i][offset++];
				}
				TmpID[IDl][j] = '\0';
				IDl++;
			}
			if (str[i][0] == 'A') {
				offset = 8;
				j = 0;
				while (str[i][offset]) {
					TmpAuthor[authorl][j++] = str[i][offset++];
				}
				TmpAuthor[authorl][j] = '\0';
				authorl++;
			}
			if (str[i][0] == 'E') {
				offset = 13;
				j = 0;
				while (str[i][offset]) {
					TmpEdYear[edYearl][j++] = str[i][offset++];
				}
				TmpEdYear[edYearl][j] = '\0';
				edYearl++;
			}
		}
	}

	bool equals(const char *str1, const char *str2)
	{
		char *ch1, *ch2;
		ch1 = (char *)str1;
		ch2 = (char *)str2;

		while (*ch1 == *ch2 && *ch1 && *ch2) {
			ch1++;
			ch2++;
		}
		if (!(*ch1) && !(*ch2))
			return true;
		else
			return false;
	}

public:
	Library() {
		readFile();
		for (int i = 0; i < 3; i++) {
			Book book(TmpName[i], TmpID[i], TmpAuthor[i], TmpEdYear[i]);
			booklist.push_back(book);
		}
	}

	void writeFile(){
		vector<Book>::iterator it = booklist.begin();
		fstream fp;
		fp.open("books_s.txt", ios_base::out);
		if (!fp.is_open())
			cout << "Error" << endl;

		while (!fp.eof() && it != booklist.end()) {
			fp << "Name: ";
			fp << it->getName() << endl;
			fp << "ID: ";
			fp << it->getID() << endl;
			fp << "Author: ";
			fp << it->getAuthor() << endl;
			fp << "EditionYear: ";
			fp << it->getEdYear() << endl << endl;
			it++;
		}
		fp.close();
	}

	void addBook(string name, string ID, string author, string edYear) {
		Book book(name, ID, author, edYear);
		booklist.push_back(book);
	}

	int queryBook() {
		vector<Book>::iterator it = booklist.begin();
		int index = 0;
		bool flag = true;
		char name[20], ID[20], author[20], edYear[20], type;

		if (booklist.size()==0) {
			cout << "\nNo records!" << endl;
			return 0;
		}

		cout << "1.Query by name" << endl;
		cout << "2.Query by ID" << endl;
		cout << "3.Query by author" << endl;
		cout << "4.Query by editionYear" << endl;
		type = _getch();

		if (type == '1') {
			cout << "\nPlease enter the name: ";
			cin >> name;
			while (it != booklist.end()) {
				index++;
				if (equals(name, it->getName().data()))// string的data()将上string转换为char*
					return index;
				else
					it++;
			}
		}
		else if (type == '2') {
			cout << "\nPlease enter the ID: ";
			cin >> ID;
			while (it != booklist.end()) {
				index++;
				if (equals(ID, it->getID().data()))
					return index;
				else
					it++;
			}
		}
		else if (type == '3') {
			cout << "\nPlease enter the author: ";
			cin >> author;
			while (it != booklist.end()) {
				index++;
				if (equals(author, it->getAuthor().data()))
					return index;
				else
					it++;
			}
		}
		else if (type == '4') {
			cout << "\nPlease enter the edtionYear: ";
			cin >> edYear;
			while (it != booklist.end()) {
				index++;
				if (equals(edYear, it->getEdYear().data()))
					return index;
				else
					it++;
			}
		}
		else {
			cout << "\nInvalid Input!" << endl;
			return 0;
		}
			

		if (it == booklist.end())
			return -1;
	}

	void deleteBook() {
		vector<Book>::iterator it = booklist.begin();
		char index;
		int d, i = 1;
		if (booklist.size()==0) {
			cout << "\nNo records!" << endl;
			return;
		}
		displayBook();
		cout << "Please enter the matching order to delete. ";
		index = _getch();
		d = index - '0';

		if (d == 1)
			booklist.erase(it);
		else if (d == booklist.size())
			booklist.pop_back();
		else if (d > 1 && d < booklist.size()) {
			while (it++ != booklist.end() && (i++) != d);
			booklist.erase(--it);
		}
		else
			cout << "\nInvalid Input!" << endl;
	}

	void displayBook() {
		vector<Book>::iterator it = booklist.begin();
		int i = 1, sum = 0;
		sum = booklist.size();

		if (sum == 0) {
			cout << "\nNo records!" << endl;
			return;
		}

		cout << "\n" << sum << " books in total" << endl;
		while (it != booklist.end()) {
			cout << "\nBook " << i++;
			cout << "\nName: " << it->getName() << endl;
			cout << "ID: " << it->getID() << endl;
			cout << "Author: " << it->getAuthor() << endl;
			cout << "EdtionYear: " << it->getEdYear() << endl;
			it++;
		}
	}

	void show(int index) {
		vector<Book>::iterator it = booklist.begin();
		if (index < 0) {
			cout << "\nNot Found!" << endl;
			return;
		}
		else if (!index)
			return;

		for (int i = 1; i < index && it != booklist.end(); i++,it++);
		cout << "\nName: " << it->getName() << endl;
		cout << "ID: " << it->getID() << endl;
		cout << "Author: " << it->getAuthor() << endl;
		cout << "EditionYear: " << it->getEdYear() << endl;
		cout << "Press any key to continue...";
		_getch();
	}

};

int main() {
	Library library;
	char inName[20], inID[20], inAuthor[20], inEdYear[20];
	bool flag, flag1, flag2;
	int index;
	char choice;

	flag = true;
	while (flag) {
		cout << "\n\n------------Book Management System------------" << endl;
		cout << "1.Add Books" << endl;
		cout << "2.Delete Books" << endl;
		cout << "3.Query Books" << endl;
		cout << "4.Display Books" << endl;
		cout << "5.Exit" << endl;
		cout << "Please enter the matching number to choose the operation." << endl;
		choice = _getch();

		switch (choice) {
		case '1':
			flag1 = true;
			do {
				cout << "\nPlease enter the name: ";
				cin >> inName;
				cout << "Please enter the ID: ";
				cin >> inID;
				cout << "Please enter the author: ";
				cin >> inAuthor;
				cout << "Please enter the edtion-year: ";
				cin >> inEdYear;
				library.addBook(inName, inID, inAuthor, inEdYear);

				flag2 = true;
				while (flag2) {
					cout << "\nContinue to add record? Y\\N ";
					choice = _getch();
					if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
						flag2 = false;
					else
						cout << "Invailid Input!" << endl;
				}
				if (choice == 'N' || choice == 'n')
					flag1 = false;
			} while (flag1);

			break;
		case '2':
			library.deleteBook();
			break;
		case '3':
			index = library.queryBook();
			library.show(index);
			break;
		case '4':
			library.displayBook();
			cout << "Press any key to continue...";
			_getch();
			break;
		case '5':
			library.writeFile();
			flag = false;
			break;
		default:
			cout << "\nInvalid Input" << endl;
		}
	}

	return 0;
}