// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsPerson
{
    // ✅ Nested class defined INSIDE clsPerson
    //    This class represents a full address and
    //    is logically related only to a person.
    class clsAddress
    {
    public:
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;

        // Method to print the complete address
        void Print()
        {
            cout << "\nAddress:\n";
            cout << AddressLine1 << endl;
            cout << AddressLine2 << endl;
            cout << City         << endl;
            cout << Country      << endl;
        }
    };

public:
    string FullName;    // Person’s name
    clsAddress Address; // Person’s address (nested class instance)

    // Constructor initializes the person and the nested address fields
    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City         = "Amman";
        Address.Country      = "Jordan";
    }
};

int main()
{
    // Create a person object
    clsPerson Person1;

    // Call the Print method of the nested class through the outer object
    Person1.Address.Print();

    system("pause>0");
    return 0;
}
