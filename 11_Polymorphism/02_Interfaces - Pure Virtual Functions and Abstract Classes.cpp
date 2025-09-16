// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

// ===============================
// Abstract Class / Interface / Contract
// Abstraction: clsMobile defines only what a mobile should do
// without specifying how it does it.
// ===============================
class clsMobile
{
public:
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;

    virtual ~clsMobile() {} // Virtual destructor for safe polymorphic deletion
};

// ===============================
// Derived Class: iPhone
// Inherits from abstract clsMobile and implements all methods
// ===============================
class clsiPhone : public clsMobile
{
public:
    void Dial(string PhoneNumber) override
    {
        cout << "iPhone dialing: " << PhoneNumber << endl;
    }

    void SendSMS(string PhoneNumber, string Text) override
    {
        cout << "iPhone sending SMS to " << PhoneNumber 
             << ": " << Text << endl;
    }

    void TakePicture() override
    {
        cout << "iPhone takes a photo!" << endl;
    }

    void MyOwnMethod()
    {
        cout << "iPhone unique feature!" << endl;
    }
};

// ===============================
// Derived Class: Samsung Note10
// Also implements all abstract methods
// ===============================
class clsSamsungNote10 : public clsMobile
{
public:
    void Dial(string PhoneNumber) override
    {
        cout << "Samsung Note10 dialing: " << PhoneNumber << endl;
    }

    void SendSMS(string PhoneNumber, string Text) override
    {
        cout << "Samsung Note10 sending SMS to " << PhoneNumber 
             << ": " << Text << endl;
    }

    void TakePicture() override
    {
        cout << "Samsung Note10 takes a photo!" << endl;
    }
};

int main()
{
    // ===============================
    // Polymorphism Example:
    // Base class pointer points to different derived objects
    // ===============================
    clsMobile* MyPhone;

    clsiPhone iPhone1;
    clsSamsungNote10 Note10;

    MyPhone = &iPhone1;
    MyPhone->Dial("123456789");  // Calls iPhone Dial
    MyPhone->TakePicture();       // Calls iPhone TakePicture

    MyPhone = &Note10;
    MyPhone->SendSMS("987654321", "Hello!"); // Calls Samsung SendSMS
    MyPhone->TakePicture();                  // Calls Samsung TakePicture

    system("pause>0");
    return 0;
}
