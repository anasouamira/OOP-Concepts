#include <iostream>
#include <string>
using namespace std;

// Define a class named clsA
class clsA {
public:
    int var; // Instance variable (different for each object)
    static int counter; // Static variable (shared between all objects)

    // Constructor: Increments the shared static counter whenever a new object is created
    clsA() {
        counter++;
    }

    // Method to print the object's data
    void Print() {
        cout << "\nvar     = " << var << endl;
        cout << "counter = " << counter << endl;
    }
};

// Static variables must be defined and initialized outside the class
int clsA::counter = 0;

int main() {
    // Create 3 objects of class clsA
    clsA A1, A2, A3;

    // Assign values to each object's instance variable
    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    // Print data of each object
    A1.Print();
    A2.Print();
    A3.Print();

    // Change the static member variable 'counter' using one object
    A1.counter = 500;

    // Since 'counter' is shared, the change reflects in all objects
    cout << "\nAfter changing the static member 'counter' in one object:\n";
    A1.Print();
    A2.Print();
    A3.Print();

    return 0;
}
