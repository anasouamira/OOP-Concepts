#include<iostream>
using namespace std;

// This class represents an Address.
// It uses encapsulation to hide the internal data (_AddressLine1, _POBox, etc.)
// and abstraction to expose only the necessary methods to the user.
class clsAddress {
private:
    // Private data members (encapsulated)
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    // Constructor to initialize all address details
    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode) {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    // Setter method for AddressLine1
    void SetAddressLine1(string AddressLine1) {
        _AddressLine1 = AddressLine1;
    }

    // Getter method for AddressLine1
    string AddressLine1() {
        return _AddressLine1;
    }

    // Setter method for AddressLine2
    void SetAddressLine2(string AddressLine2) {
        _AddressLine2 = AddressLine2;
    }

    // Getter method for AddressLine2
    string AddressLine2() {
        return _AddressLine2;
    }

    // Setter method for POBox
    void SetPOBox(string POBox) {
        _POBox = POBox;
    }

    // Getter method for POBox
    string POBox() {
        return _POBox;
    }

    // Setter method for ZipCode
    void SetZipCode(string ZipCode) {
        _ZipCode = ZipCode;
    }

    // Getter method for ZipCode
    string ZipCode() {
        return _ZipCode;
    }

    // Print method: displays the address details.
    // This is part of abstraction: user can easily access complete information.
    void Print() {
        cout << "\nAddress Details:\n";
        cout << "------------------------";
        cout << "\nAddressLine1: " << _AddressLine1 << endl;
        cout << "AddressLine2: " << _AddressLine2 << endl;
        cout << "POBox       : " << _POBox << endl;
        cout << "ZipCode     : " << _ZipCode << endl;
    }
};

int main() {
    // Creating an object of clsAddress and initializing it using the constructor
    clsAddress Address1("Queen Alia Street", "B 303", "11192", "5555");

    // Using the Print method to display the address
    Address1.Print();

    system("pause>0");
    return 0;
}
