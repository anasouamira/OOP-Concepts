#include <iostream>
#include <string>
using namespace std;

// =====================
// 1. Encapsulation & Abstraction
// Encapsulation: Data members are private and accessed through public methods.
// Abstraction: Only the essential details (methods) are exposed.
// =====================
class clsPerson {
private:
    string _FirstName;
    string _LastName;

public:
    clsPerson(string FirstName, string LastName) {
        _FirstName = FirstName;
        _LastName = LastName;
    }

    void setFirstName(string FirstName) { _FirstName = FirstName; }
    void setLastName(string LastName) { _LastName = LastName; }
    string FullName() { return _FirstName + " " + _LastName; }

    // Virtual function for polymorphism
    virtual void Print() {
        cout << "Hi, I am a person: " << FullName() << endl;
    }
};

// =====================
// 2. Inheritance
// clsEmployee and clsStudent inherit from clsPerson
// =====================
class clsEmployee : public clsPerson {
private:
    string _Title;
public:
    clsEmployee(string FirstName, string LastName, string Title)
        : clsPerson(FirstName, LastName) {
        _Title = Title;
    }

    void setTitle(string Title) { _Title = Title; }
    string Title() { return _Title; }

    // =====================
    // 3. Polymorphism
    // Overriding base class Print method (dynamic binding)
    // =====================
    void Print() override {
        cout << "Hi, I am an Employee: " << FullName() 
             << ", Title: " << _Title << endl;
    }
};

class clsStudent : public clsPerson {
private:
    string _Major;
public:
    clsStudent(string FirstName, string LastName, string Major)
        : clsPerson(FirstName, LastName) {
        _Major = Major;
    }

    void setMajor(string Major) { _Major = Major; }
    string Major() { return _Major; }

    void Print() override {
        cout << "Hi, I am a Student: " << FullName() 
             << ", Major: " << _Major << endl;
    }
};

int main() {
    // Encapsulation & Abstraction example
    clsPerson person1("Mohammed", "Abu-Hadhoud");
    person1.Print(); // prints basic person info

    // Inheritance & Polymorphism example
    clsEmployee emp1("Alice", "Smith", "CEO");
    clsStudent stu1("Bob", "Johnson", "Computer Science");

    // Static binding (compile-time)
    emp1.Print();
    stu1.Print();

    // Dynamic binding (runtime) using base class pointer
    clsPerson* persons[2];
    persons[0] = &emp1;
    persons[1] = &stu1;

    cout << "\nPolymorphism with base class pointers:\n";
    for (int i = 0; i < 2; i++) {
        persons[i]->Print(); // Correct overridden Print() is called
    }

    return 0;
}
