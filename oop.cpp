#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class Teacher {
    private :
    double salary;

    public :
    string name;
    string dept;
    string subject;


    void changeDept(string newDept){
        dept = newDept;
    }

    //setter 
    void setSalary(double s ){
        salary = s;
    }
    //getter 
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name = "Mashrafi";
    t1.subject = "C++";
    t1.dept = "Applied Mathematics";
    t1.setSalary(5000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
   // return 0;

getch();

}