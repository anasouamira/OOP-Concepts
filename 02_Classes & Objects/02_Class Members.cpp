#include <iostream>
using namespace std;

/*
Class Members in C++:

1. Data Members:
   - Variables declared inside a class that hold the object's data or state.
   - Example: string brand; int speed;

2. Member Functions:
   - Functions defined inside a class that perform operations on data or provide behavior.
   - Example: void Drive();

3. Access Specifiers:
   - public: members accessible from outside the class.
   - private: members accessible only within the class.
   - protected: accessible within the class and derived classes.

Summary:
- Data members represent what an object knows.
- Member functions represent what an object can do.
*/

class clsPerson {
    int x; // private data member (internal use)

public:
    string FirstName;  // public data member
    string LastName;   // public data member

    // member function to return full name
    string FullName() {
        return FirstName + " " + LastName;
    }
};

int main() {
    clsPerson Person1;

    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";

    cout << Person1.FullName() << endl;

    return 0;
}
