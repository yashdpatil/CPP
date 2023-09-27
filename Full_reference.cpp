######### Call by value###########
#include<iostream>
void swap_number( int x, int y ){
 int temp = x;
 x = y;
 y = temp;
 }
 int main( void ){
 int a = 10;
 int b = 20;
 swap_number( a, b ); //a , b are arguments; we are passing
passing it by value to the function
 cout << "a : " << a << endl;
 cout << "b : " << b << endl;
 return 0;
 }
######### Call by Adresss###########
#include<iostream>
void swap_number( int *const x, int *const y ){
 int temp = *x;
 *x = *y;
 *y = temp;
}
int main( void ){
 int a = 10;
 int b = 20;
 swap_number( &a, &b ); //adress of a , b are arguments; we are
passing passing it by address to the function
 cout << "a : " << a << endl; //20
 cout << "b : " << b << endl; //10
 return 0;
}

######### Call by Reference###########
#include<iostream>
//int &x = a; //int *const x = &a;
//int &y = b; //int *const y = &b;
void swap_number( int &x, int &y ){
 int temp = x; //int temp = *x;
 x = y; //*x = *y;
 y = temp; //*y = temp;
}
int main( void ){
 int a = 10;
 int b = 20;
 swap_number( a, b ); //Function call by reference
 cout << "a : " << a << endl; //20
 cout << "b : " << b << endl; //10
 return 0;
}

