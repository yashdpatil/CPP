############################################## Opertor overload ###################################################
1 +
2 -
3 extraction<<
4 Insertion >>

  
#include<iostream>
#include<string>
using namespace std;
class Full {
private:
	int x;
	int y;
	string name;
public:
	void SetX(int x) {
		this->x = x;
	}
	void SetY(int y) {
		this->y = y;
	}
	void Setname(string name) {
		this->name = name;
	}
	int GetX() {
		return this->x;
	}
	int GetY() {
		return this->y;
	}
	string Getname() {
		return this->name;
	}

	friend istream& operator>>(istream &obj, Full &other) {
		cin >> other.x;
		cin >> other.y;
		return cin;
	}
	friend ostream& operator<<(ostream &obj, Full &other) {
		cout << other.x << endl;
		cout << other.y << endl;
		return cout;

	}
	Full operator+(Full &other) {
		Full result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		return result;
	}
};
int main(void) {
	Full f;
//	Full ff;
//	cin >> f >> ff;
//	Full fff;
//	fff = f + ff;
//	cout << fff;
	f.SetX(10);
	f.SetY(20);
	f.Setname("hello");
	cout << f.GetX();
	cout << f.GetY();
	cout << f.Getname();
	return 0;
}
