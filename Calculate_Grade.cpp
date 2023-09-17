/* ************ Problem Statement ////////////////////
		In cpp: -
		 Create a class called Student with the following private data members:
 name (string): to store the name of the student.
rollNumber (int): to store the roll number of the student.
marks (float): to store the marks obtained by the student.
grade (char): to store the grade calculated based on the marks.
Implement getter and setter member functions for each data member
Create a member function calculateGrade() that calculates the grade based on the following
grading scale:
 A: 90-100
 B: 80-89
 C: 70-79
 D: 60-69
 F: Below 60
Implement a menu-driven program in the main() function with the following options:
Accept Information
Display information
Calculate Grade
Exit the program.
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;
    char grade;

public:

    Student() : name(""), rollNumber(0), marks(0.0), grade(' ') {}


    void setName(string n) {
        name = n;
    }

    string getName()  {
        return name;
    }

    void setRollNumber(int r) {
        rollNumber = r;
    }

    int getRollNumber()  {
        return rollNumber;
    }


    void setMarks(float m) {
        marks = m;
    }

    float getMarks()  {
        return marks;
    }

    void setGrade(char g) {
        grade = g;
    }

    char getGrade()  {
        return grade;
    }


    void calculateGrade() {
        if (marks >= 90) {
            grade = 'A';
        } else if (marks >= 80) {
            grade = 'B';
        } else if (marks >= 70) {
            grade = 'C';
        } else if (marks >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }
};

int main() {
    Student student;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Accept Information\n";
        cout << "2. Display Information\n";
        cout << "3. Calculate Grade\n";
        cout << "4. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                {
                   string name;
                    int rollNumber;
                    float marks;

                 cout << "Enter name: ";
                 cin.ignore();
                 cin>>name;
                 student.setName(name);

                 cout << "Enter roll number: ";
                 cin >> rollNumber;
                    student.setRollNumber(rollNumber);

                 cout << "Enter marks: ";
                 cin >> marks;
                    student.setMarks(marks);
                }
                break;

            case 2:
                cout << "Student Information:\n";
                cout << "Name: " << student.getName() << "\n";
                cout << "Roll Number: " << student.getRollNumber() << "\n";
                cout << "Marks: " << student.getMarks() << "\n";
                break;

            case 3:
                student.calculateGrade();
                cout << "Calculated Grade: " << student.getGrade() << "\n";
                break;

            case 4:
                cout << "Exiting the program.\n";


                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

