#include <iostream>
using namespace std;

class clsPerson
{
public:
    // Virtual function allows derived classes to override this method.
    // Enables runtime polymorphism.
    virtual void Print()
    {
        cout << "Hi, I'm a person!\n";
    }
};

class clsEmployee : public clsPerson
{
public:
    // Override the base class virtual function
    void Print()
    {
        cout << "Hi, I'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    // Override the base class virtual function
    void Print()
    {
        cout << "Hi, I'm a student\n";
    }
};

int main()
{
    clsEmployee Employee1;
    clsStudent Student1;

    // Direct call using objects: calls the respective derived class methods
    Employee1.Print(); // Output: Hi, I'm an Employee
    Student1.Print();  // Output: Hi, I'm a student

    // Upcasting: derived class object to base class pointer
    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;

    // Because Print() is virtual, the derived class method is called at runtime (polymorphism)
    Person1->Print(); // Output: Hi, I'm an Employee
    Person2->Print(); // Output: Hi, I'm a student

    system("pause>0");
    return 0;
}
