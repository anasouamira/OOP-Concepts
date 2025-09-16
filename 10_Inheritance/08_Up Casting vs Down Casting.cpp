#include <iostream>
using namespace std;

class clsPerson
{
public:
    string FullName = "Mohammed Abu-Hadhoud";
};

class clsEmployee : public clsPerson
{
public:
    string Title = "CEO";
};

int main()
{
    clsEmployee Employee1;

    // Accessing member of derived class
    cout << Employee1.FullName << endl; // Output: Mohammed Abu-Hadhoud

    //// Upcasting
    // Upcasting: Converting derived class pointer to base class pointer
    // Safe and implicit. Only base class members are accessible via base pointer.
    clsPerson* Person1 = &Employee1;
    cout << Person1->FullName << endl; // Output: Mohammed Abu-Hadhoud
    // Person1->Title; // ❌ Not accessible, base class pointer cannot see derived members

    //// Downcasting
    // Downcasting: Converting base class pointer/object to derived class pointer
    // Unsafe unless the object is actually of derived type
    // clsPerson Person2;
    // clsEmployee* Employee2 = &Person2; // ❌ Error: cannot convert base object to derived pointer

    system("pause>0");
    return 0;
}
