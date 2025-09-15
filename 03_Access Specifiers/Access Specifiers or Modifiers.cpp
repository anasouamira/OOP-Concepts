#include <iostream>
using namespace std;

// Define a class named clsPerson
class clsPerson {
private:
    // 🔒 Private members: accessible only inside this class
    int Variabl1 = 5;

    int Function1() {
        return 40;
    }

protected:
    // 🛡️ Protected members: accessible inside this class AND derived (child) classes
    int Variabl2 = 100;

    int Function2() {
        return 50;
    }

public:
    // 🌍 Public members: accessible from anywhere (inside, outside, or from child classes)
    string FirstName;
    string LastName;

    // Public method that returns the full name
    string FullName() {
        return FirstName + " " + LastName;
    }

    // Public method that uses private and protected members internally
    float Function3() {
        return Function1() * Variabl1 * Variabl2;
    }
};

int main() {
    clsPerson Person1;

    // Set public members
    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";

    // Access public method FullName()
    cout << "Person1: " << Person1.FullName() << endl;

    // Access public method that uses private & protected members internally
    cout << Person1.Function3(); // Output: 40 * 5 * 100 = 20000

    return 0;
}
