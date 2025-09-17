// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud

#include <iostream>
using namespace std;

class clsEmployee
{
public:
    int ID;
    string Name;
    float Salary;

    // ✅ Constructor: initializes all data members.
    clsEmployee(int ID, string Name, float Salary)
    {
        // Use of `this` pointer to distinguish member variables from parameters
        this->ID     = ID;
        this->Name   = Name;
        this->Salary = Salary;
    }

    // ✅ Static function:
    //    Does not belong to a specific object.
    //    Receives an `clsEmployee` object and prints it.
    static void Func1(clsEmployee Employee)
    {
        // Call the Print() function of the received object
        Employee.Print();
    }

    // ✅ Normal member function:
    //    Demonstrates using `this` to pass the current object to a static function.
    void Func2()
    {
        // *this dereferences the `this` pointer to pass the current object by value
        Func1(*this);
    }

    // ✅ Prints all data members of the current object
    void Print()
    {
        // We can write simply ID, Name, Salary
        // or explicitly use `this->` to show they belong to this object.
        cout << ID << "  " << Name << "  " << Salary << endl;
        // Equivalent to:
        // cout << this->ID << "  " << this->Name << "  " << this->Salary << endl;
    }
};

int main()
{
    // Create an employee object and initialize it
    clsEmployee Employee1(101, "Ali", 5000);

    // Print details directly
    Employee1.Print();

    // Call Func2(), which calls the static Func1(), which then prints again
    Employee1.Func2();

    return 0;
}
