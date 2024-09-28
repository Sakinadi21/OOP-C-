#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class ABC {

    public :
    ABC(){
      cout << "constructor \n";
    }

    ~ABC() {
        cout << "destructor \n";
    }
    
};

int main() {
  
   if(true){
    //ABC(){
        ABC obj;
        //cout<< " constructor \n";
   // }
    
   }
   cout<<"end of main function";

    getch();
}
