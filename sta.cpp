#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class A {
    public :
    int x;

    void ineX(){
        x = x + 1;
    }
};

int main() {
    // A obj;
    // cout << obj.x << endl;
    // obj.ineX();
    // cout << obj.x << endl;

    A obj1;
    A obj2;

    obj1.x = 100;
    obj2.x = 200;
     cout<<obj1.x<<endl;
    cout << obj2.x << endl;


  
   

    getch();
}
