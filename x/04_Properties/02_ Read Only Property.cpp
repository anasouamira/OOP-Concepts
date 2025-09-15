#include <iostream>
using namespace std;

// Define class clsPerson
class clsPerson {
private:
    // Private members: hidden from outside
    int _ID = 10;              // Read-only ID initialized to 10
    string _FirstName;         // Will be set through setter
    string _LastName;          // Will be set through setter

public:
    // Getter for ID (read-only property)
    int ID() {
        return _ID; // No setter for _ID, so it's read-only
    }

    // Setter for FirstName (write)
    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    // Getter for FirstName (read)
    string FirstName() {
        return _FirstName;
    }

    // Setter for LastName (write)
    void setLastName(string LastName) {
        _LastName = LastName;
    }

    // Getter for LastName (read)
    string LastName() {
        return _LastName;
    }

    // Method to return full name (read-only operation)
    string FullName() {
        return _FirstName + " " + _LastName;
    }
};

int main() {
    // Create object of clsPerson
    clsPerson Person1;

    // Set values using setters
    Person1.setFirstName("Mohammed");
    Person1.setLastName("Abu-Hadhoud");

    // Display values using getters and FullName method
    cout << "ID: " << Person1.ID() << endl;                   // Read-only ID
    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: " << Person1.FullName() << endl;

    system("pause>0"); // Keeps the console open (Windows only)
    return 0;
}
