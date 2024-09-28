#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    Person() {
        cout << "Parent constructor...\n";
    }
};

class Classmate {
public:
    string name;
    int rollno;
};

class Teacher {
public:
    string subject;
    double salary;
};

class TA : public Classmate, public Teacher {
    // You can initialize members here if necessary
};

class Student : public Person {
    // name, age, rollno
public:
    double rollno;

    Student(string name, double age, int rollno) : Person(name, age) {  // Corrected
        this->rollno = rollno;
    }

    Student() {  // Un-commented default constructor
        cout << "Child constructor...\n";
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollno << endl;
    }
};

int main() {
    Student s1;
    s1.name = "Mashrafi Uddin";
    s1.age = 21;
    s1.rollno = 2;

    Student s2("Sakiba Belal", 20, 1234);  // Corrected constructor call

    s1.getInfo();

    cout << "-------------" << endl;

    TA t1;
    t1.name = "Mili";  // Inherits name from Classmate
    t1.subject = "Math";  // Inherits subject from Teacher

    cout << "TA Name: " << t1.name << endl;
    cout << "TA Subject: " << t1.subject << endl;

    return 0;
}
