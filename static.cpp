#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
void fun(){
    static int x = 0;
    cout << "x : " << x << endl;
    x++;
};


int main() {
  
   
fun();
fun();
fun();
    getch();
}
