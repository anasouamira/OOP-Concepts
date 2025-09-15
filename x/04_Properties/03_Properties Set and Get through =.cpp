#include <iostream>
using namespace std;

// Define class clsPerson
class clsPerson {
private:
    // Private member variable
    string _FirstName;

public:
    // Setter method: assigns value to _FirstName
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    // Getter method: retrieves value of _FirstName
    string GetFirstName() {
        return _FirstName;
    }

    // Declare a property FirstName using MSVC-specific syntax
    // This makes FirstName behave like a field but uses Get/Set behind the scenes
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main() {
    clsPerson Person1;

    // Traditional method-style access
    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() << endl;

    // Property-style access (like in C#)
    Person1.FirstName = "Mohammed";      // Calls SetFirstName()
    cout << Person1.FirstName << endl;   // Calls GetFirstName()

    system("pause>0"); // Keeps the console window open (Windows-specific)
    return 0;
}
