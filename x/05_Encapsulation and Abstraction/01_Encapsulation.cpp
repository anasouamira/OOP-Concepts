#include <iostream>
using namespace std;

// ============================================
// 🧱 Encapsulation in Action:
// This class hides (encapsulates) its internal data (_FirstName)
// and provides controlled access via getter and setter methods.
// ============================================
class clsPerson {
private:
    // 🔒 Private variable: cannot be accessed directly from outside the class
    string _FirstName;

public:
    // ✅ Public setter method (controlled write access)
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    // ✅ Public getter method (controlled read access)
    string GetFirstName() {
        return _FirstName;
    }

    // 🧩 Property that allows accessing the private variable using field-like syntax
    // This is Microsoft-specific and simulates C#-style properties
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main() {
    clsPerson Person1;

    // 🛠️ Using setter to change the internal variable safely
    Person1.SetFirstName("Mohammed");

    // 🧾 Using getter to retrieve the variable
    cout << "Traditional Access: " << Person1.GetFirstName() << endl;

    // 🧠 Using property (C#-style) — internally calls SetFirstName and GetFirstName
    Person1.FirstName = "Mohammed";           // calls the set method
    cout << "Property Access: " << Person1.FirstName << endl; // calls the get method

    system("pause>0");
    return 0;
}
