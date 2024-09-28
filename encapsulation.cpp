#include<iostream>
#include<string>
using namespace std;

// Teacher class definition
class Teacher {
    string name;
    string dept;
    string subject;
    private:
    double salary;

    public:
    // Non-parameterized constructor
    Teacher() {
        dept = "Computer science";  // Default value for department
    }

    // Parameterized constructor
    Teacher(string n, string d, string s, double sal) {
        name = n;           // Initialize name
        dept = d;           // Initialize department
        subject = s;        // Initialize subject
        salary = sal;       // Initialize salary
    }

    // Overloaded constructor without subject
    Teacher(string name, string dept, double salary) {
        this->name = name;      // 'this' pointer to avoid name-shadowing
        this->dept = dept;
        this->salary = salary;
    }

    // Copy constructor (custom)
    Teacher(const Teacher &orgObj) { // Pass by reference
        cout << "I am a custom copy constructor...\n";
        this->name = orgObj.name;   // Copy name
        this->dept = orgObj.dept;   // Copy department
        this->subject = orgObj.subject; // Copy subject
        this->salary = orgObj.salary;   // Copy salary
    }

    // Setter for salary
    void setSalary(double s) {
        salary = s;
    }

    // Getter for salary
    double getSalary() {
        return salary;
    }

    // Setter and getter for subject and name
    void setSubject(string sub) {
        subject = sub;
    }

    string getSubject() {
        return subject;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    // Method to get basic info
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
    }
};

// Account class definition (handling dynamic memory properly)
class Account {
    private:
    double balance;
    string password;

    public:
    string accountId;
    string username;
    string* userIdPtr; // Dynamically allocated pointer for userId

    // Default constructor
    Account() {
        userIdPtr = nullptr;  // Initialize pointer to null
    }

    // Parameterized constructor
    Account(string userId) {
        userIdPtr = new string(userId); // Dynamically allocate memory
    }

    // Setter for balance
    void setBalance(double b) {
        balance = b;
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Setter for userIdPtr (dynamically allocates and assigns the value)
    void setUserId(string userId) {
        if (userIdPtr == nullptr) {
            userIdPtr = new string;  // Allocate memory if not already done
        }
        *userIdPtr = userId;          // Assign value to dynamically allocated string
    }

    // Getter for userIdPtr
    string getUserId() const {
        if (userIdPtr != nullptr) {
            return *userIdPtr;        // Return the value pointed by userIdPtr
        } else {
            return "No user ID set";  // Handle uninitialized case
        }
    }

    // Copy constructor (deep copy)
    Account(const Account &obj) {
        if (obj.userIdPtr != nullptr) {
            userIdPtr = new string(*obj.userIdPtr);  // Deep copy
        } else {
            userIdPtr = nullptr;
        }
        this->balance = obj.balance;  // Copy balance
    }

    // Destructor to free dynamically allocated memory
    ~Account() {
        delete userIdPtr;
    }
};

// Student class definition (handling deep copy)
class Student {
    public : 
    string name;
    double cgpa;
    double* idPtr; // Dynamically allocated pointer

    // Parameterized constructor
    Student(string name, double cgpa, double id){
        this->name = name;
        this->cgpa = cgpa;
        idPtr = new double;   // Allocate memory for idPtr
        *idPtr = id;          // Assign value to idPtr
    }

    // Copy constructor (deep copy)
    Student(const Student &obj){
        this->name = obj.name;      // Copy name
        this->cgpa = obj.cgpa;      // Copy CGPA
        this->idPtr = new double;   // Allocate new memory for pointer
        *idPtr = *obj.idPtr;        // Copy value of idPtr
    }

    // Method to get student's information
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    // Method to display student's data
    void getSay(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "ID: " << *idPtr << endl;
    }

    // Destructor to free memory
    ~Student(){
        cout << "Hi, I delete everything\n";
        delete idPtr; // Prevent memory leak
    }
};

int main() {
    // Create a Teacher object using default constructor
    Teacher t1;
    t1.setName("Mashrafi");
    t1.setSubject("C++");
    t1.setSalary(5000);
    t1.getInfo();
    cout << endl;

    // Create an Account object
    Account t2;
    t2.setUserId("defaultUserId");    // Set user ID using the setter
    t2.setBalance(1500);              // Set balance
    cout << "Account balance: " << t2.getBalance() << endl;
    cout << "User ID: " << t2.getUserId() << endl;  // Get user ID using getter

    // Use deep copy constructor for Account
    Account t3(t2);
    t3.setUserId("newUserId");        // Set a new user ID for the copied object
    cout << "Copied Account User ID: " << t3.getUserId() << endl;

    cout <<"--------------"<<endl;

    // Create another Teacher using parameterized constructor
    Teacher t4("Sakiba", "IIT", "Java", 2500000);
    t4.getInfo();

    cout <<"--------------"<<endl;

    // Teacher object with overloaded constructor
    Teacher t5("Nadiha", "Software engineering", 20000);
    t5.getInfo();

    cout <<"----------"<<endl;

    // Using the custom copy constructor
    Teacher t6(t4); 
    t6.getInfo();

    cout <<"----------"<<endl;
    cout << "Name: " << t1.getName() << endl;
    cout << "Salary: " << t1.getSalary() << endl;

    cout <<"----------"<<endl;

    // Create Student object
    Student s1("Nura Jannat Mili", 3.68, 18);
    s1.getInfo();
    cout <<"----------"<<endl;

    // Use copy constructor for Student (deep copy)
    Student s2(s1);
    s2.getInfo();
    cout <<"----------"<<endl;

    // Create another Student object
    Student s3("Nusaiba", 3.50, 2);
    s3.getSay();
    cout <<"----------"<<endl;

    // Modify ID value using pointer
    *(s3.idPtr) = 3.8;
    s3.getSay();
    cout <<"----------"<<endl;

    return 0;
}
