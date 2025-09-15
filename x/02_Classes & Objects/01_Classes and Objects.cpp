#include <iostream>       // Include the input-output stream library
using namespace std;      // Use the standard namespace

// Define a class named clsPerson to represent a person
class clsPerson {
    // Private member variable - only accessible inside the class
    // Used for internal logic or hidden data (not used in this example)
    int x;

public:
    // Public member variables - accessible from outside the class
    string FirstName;  // Stores the first name of the person
    string LastName;   // Stores the last name of the person

    // Public member function (method) that returns the full name
    string FullName() {
        return FirstName + " " + LastName;
    }
};

int main() {
    // Create an object of type clsPerson named Person1
    clsPerson Person1;

    // Set the public member variables
    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";

    // Call the FullName() method and print the result
    cout << Person1.FullName() << endl;

    // Declare a string variable (not used in this code)
    string S1;

    return 0; // Indicate successful program termination
}
