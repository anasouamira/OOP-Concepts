// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsPerson
{
    // ✅ Private data member to store the person's full name
    string _FullName;

    // ✅ Nested class: clsAddress
    //    This class is used only inside clsPerson to represent an address.
    class clsAddress
    {
    private:
        // Private members of the nested class
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        // Constructor to initialize all address fields
        clsAddress(string AddressLine1, string AddressLine2,
                   string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City         = City;
            _Country      = Country;
        }

        // ======= Setters and Getters =======
        void setAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }
        string AddressLine1()
        {
            return _AddressLine1;
        }

        void setAddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }
        string AddressLine2()
        {
            return _AddressLine2;
        }

        void setCity(string City)
        {
            _City = City;
        }
        string City()
        {
            return _City;
        }

        void setCountry(string Country)
        {
            _Country = Country;
        }
        string Country()
        {
            return _Country;
        }

        // Print the full address to the console
        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City         << endl;
            cout << _Country      << endl;
        }
    }; // end of nested class clsAddress

public:
    // ======= Setters and Getters for FullName =======
    void setFullName(string FullName)
    {
        _FullName = FullName;
    }
    string FullName()
    {
        return _FullName;
    }

    // ✅ Composition: Person *has an* Address
    //    We create a public member `Address` of type clsAddress.
    //    It is initialized with empty strings by default.
    clsAddress Address = clsAddress("", "", "", "");

    // Constructor of the outer class
    // Initializes both _FullName and the nested Address object
    clsPerson(string FullName,
              string AddressLine1,
              string AddressLine2,
              string City,
              string Country)
    {
        _FullName = FullName;

        // Initialize Address with the provided data
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
};

int main()
{
    // Create a person object with a full name and a full address
    clsPerson Person1(
        "Mohammed Abu-Hadhoud",
        "Building 10",
        "Queen Rania Street",
        "Amman",
        "Jordan"
    );

    // Access the nested class instance and print the address
    Person1.Address.Print();

    system("pause>0");
    return 0;
}
