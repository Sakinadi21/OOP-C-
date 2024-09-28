#include<iostream>
#include<string>
using namespace std;

class Student {
    public :
    string name;
    
    
    Student(){
        cout << "non - parameterized ";
    }
    Student(string name){
        this -> name = name;
        cout << "parameterized \n";
    }
};

int main() {
   Student s1("Mashu");
   

    return 0;
}
