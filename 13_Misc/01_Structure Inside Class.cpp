// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsPerson
{
    // ✅ Nested struct defined INSIDE the class.
    //    It groups address-related fields in a single type.
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    string FullName; // Public member to store full name

    // ✅ Object of nested struct as a member of clsPerson
    stAddress Address;

    // Constructor initializes default values
    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City        = "Amman";
        Address.Country     = "Jordan";
    }

    // Method to print the address
    void PrintAddress()
    {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City         << endl;
        cout << Address.Country      << endl;
    }
};

int main()
{
    // Create a person object
    clsPerson Person1;

    // Call the method to print the address information
    Person1.PrintAddress();

    system("pause>0");
    return 0;
}
