/* *************************** Code to demonstriate Runtime Polymorphism *****************************************
  used:
  micro
  rtti
virtual
inheritance*/

#include<iostream>
#include<string>
using namespace std;
#define PI 3.14
class Shape{
protected:
	float area;
public:
	Shape(){
		this->area =0;
	}
	virtual void Accept()=0;
	void Area(){
		cout<<area<<endl;
	}
	virtual ~Shape(){
		cout<<endl;
	}


};
class Rect : public Shape{
private:
	int len;
	int bre;
public:
	Rect(){
		this->len=0;
		this->bre=0;
	}
	void Accept(){
		cin>>this->len;
		cin>>this->bre;
		area=len*bre;
	}
	void Display(){
		cout<<area<<endl;
	}
};
class Cir : public Shape{
private:
	int rad;
public:
	Cir(){
		this->rad=0;
	}
	void Accept(){
		cin>>this->rad;
		area = static_cast<float>( PI * rad * rad);
	}
	void Display(){
	cout<<area<<"/n";
	}
};
int Menulist(){
	int choice;
	cout<<"0 Exit"<<endl;
	cout<<"1 Rectangle"<<endl;
	cout<<"2 Circle"<<endl;
	cin>>choice;
	return choice;
}
int main( void ){
	int choice;
	while((choice=::Menulist())!=0)
	{
		Shape *ptr= nullptr;
		switch(choice)
		{
		case 1:
			ptr = new Rect();
			break;
		case 2:
			ptr= new Cir();
			break;
		}
	if(ptr!=0){
		ptr->Accept();
		ptr->Area();
		delete ptr;
		ptr= nullptr;

	}
	}
	return 0;
}
