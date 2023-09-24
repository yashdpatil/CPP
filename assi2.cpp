************ MENU DRIVEN CODE ******************


#include<iostream>
#include<string>
using namespace std;
class Book {
private:
	string book_name;
	float price;
	int pagecount;
public:
	Book() {
		this->book_name = "";
		this->pagecount = 0;
		this->price = 0;
	}
	void Inputrecord() {
		cout << " enter the book name" << endl;

		getline(cin, book_name);
		cout << " enter the book page count" << endl;
		cin >> pagecount;
		cout << " enter the book price" << endl;
		cin >> price;
	}

	void printRecord() {
		cout << " the book name" << book_name << endl;

		cout << "  the Page Count" << pagecount << endl;

		cout << "  the book price" << price << endl;

	}

};
class Tape: public Book {
private:
	string Tape_name;
	float price;
	int playcount;
public:
	Tape() {
		this->Tape_name = "";
		this->playcount = 0;
		this->price = 0;
	}
	void Inputrecord() {
		cout << " enter the tape name    ";

		getline(cin, Tape_name);
		cout << " enter the playcount      ";
		cin >> playcount;
		cout << " enter the tape price     ";
		cin >> price;
	}

	void printRecord() {
		cout << "  the tape name      " << Tape_name << endl;
		;

		cout << "  the playcount     " << playcount << endl;

		cout << "  the tape price    " << price << endl;

	}

};
int Menulist(void) {
	int choice;
	cout << "0. Exit" << endl;
	cout << "1. Book" << endl;
	cout << "2. tape" << endl;
	cin >> choice;
	cin.ignore();
	return choice;
}
int main(void) {
	int choice;

	while ((choice = ::Menulist()) != 0) {
		Book b;
		Tape t;
//		cin.ignore();
		switch (choice) {
		case 1:
			b.Inputrecord();
			b.printRecord();
			break;

		case 2:
			t.Inputrecord();
			t.printRecord();
			break;
		}

	}
	return 0;
}

