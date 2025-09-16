#include <iostream>
using namespace std;

class clsPerson
{
public:
    // Virtual function allows runtime polymorphism (late binding)
    virtual void Print()
    {
        cout << "Hi, I'm a person!\n";
    }
};

class clsEmployee : public clsPerson
{
public:
    // Override base class virtual function
    void Print()
    {
        cout << "Hi, I'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    // Override base class virtual function
    void Print()
    {
        cout << "Hi, I'm a student\n";
    }
};

int main()
{
    clsEmployee Employee1;
    clsStudent Student1;

    // Early Binding (Static Binding)
    // Compiler knows exactly which function to call at compile time
    Employee1.Print(); // Output: Hi, I'm an Employee
    Student1.Print();  // Output: Hi, I'm a student

    // Upcasting: derived class objects to base class pointers
    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;

    // Late Binding (Dynamic Binding)
    // Because Print() is virtual, the function call is resolved at runtime
    Person1->Print(); // Output: Hi, I'm an Employee
    Person2->Print(); // Output: Hi, I'm a student

    system("pause>0");
    return 0;
}
