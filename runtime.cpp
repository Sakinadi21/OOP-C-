#include<iostream>
#include<string>
using namespace std;

class Parent {
public:
    virtual void getInfo() {  // Marked virtual for dynamic binding
        cout << "parent class\n";
    }

    virtual void hello() {  // Virtual function for polymorphism
        cout << "hello from parent\n";
    }
};

class Child : public Parent {
public:
    void getInfo() override {  // Override to specify that it's overriding the base class function
        cout << "child class\n";
    }

    void hello() override {  // Override the virtual function
        cout << "hello from child\n";
    }
};

int main() {
    Parent p1;
    p1.getInfo();  // Calls Parent's getInfo()
    cout << "---------\n";

    Child c1;
    c1.hello();  // Calls Child's hello()

    // Demonstrating polymorphism using a base class pointer
    Parent* p2 = &c1;
    p2->getInfo();  // Calls Child's getInfo() due to dynamic binding

    return 0;
}

/*
Virtual functions are Dynamic in nature.
Defined by the keyword "virtual" inside a base class and are always declared with a base class and overridden in a child class.
A virtual function is called during Runtime.
*/
