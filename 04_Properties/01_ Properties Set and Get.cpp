#include <iostream>
using namespace std;

// Define class clsPerson
class clsPerson {
private:
    // Private member variables - cannot be accessed directly outside the class
    string _FirstName;
    string _LastName;

public:
    // Setter for FirstName (Write property)
    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    // Getter for FirstName (Read property)
    string FirstName() {
        return _FirstName;
    }

    // Setter for LastName (Write property)
    void setLastName(string LastName) {
        _LastName = LastName;
    }

    // Getter for LastName (Read property)
    string LastName() {
        return _LastName;
    }

    // Method to return the full name (Read-only operation)
    string FullName() {
        return _FirstName + " " + _LastName;
    }
};

int main() {
    clsPerson Person1;

    // Set values using setters (not direct access to private members)
    Person1.setFirstName("Mohammed");
    Person1.setLastName("Abu-Hadhoud");

    // Get values using getters
    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;

    // Display full name
    cout << "Full Name: " << Person1.FullName() << endl;

    system("pause>0"); // For Windows: keeps console window open
    return 0;
}
