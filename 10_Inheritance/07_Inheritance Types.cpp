#include <iostream>
using namespace std;

// Base class
class Base {
public:
    int PublicVar = 1;
protected:
    int ProtectedVar = 2;
private:
    int PrivateVar = 3;
};

// Public inheritance
class PublicDerived : public Base {
public:
    void ShowVars() {
        cout << "PublicDerived:\n";
        cout << "PublicVar  = " << PublicVar << endl;       // accessible
        cout << "ProtectedVar = " << ProtectedVar << endl; // accessible
        // cout << PrivateVar; // ❌ Error: private not accessible
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
public:
    void ShowVars() {
        cout << "ProtectedDerived:\n";
        cout << "PublicVar  = " << PublicVar << endl;       // accessible inside derived
        cout << "ProtectedVar = " << ProtectedVar << endl; // accessible inside derived
        // cout << PrivateVar; // ❌ Error: private not accessible
    }
};

// Private inheritance
class PrivateDerived : private Base {
public:
    void ShowVars() {
        cout << "PrivateDerived:\n";
        cout << "PublicVar  = " << PublicVar << endl;       // accessible inside derived
        cout << "ProtectedVar = " << ProtectedVar << endl; // accessible inside derived
        // cout << PrivateVar; // ❌ Error: private not accessible
    }
};

int main() {
    PublicDerived pubObj;
    pubObj.ShowVars();
    cout << "Access PublicVar via pubObj: " << pubObj.PublicVar << endl; // ✅ public accessible

    ProtectedDerived protObj;
    protObj.ShowVars();
    // cout << protObj.PublicVar; // ❌ Error: public became protected

    PrivateDerived privObj;
    privObj.ShowVars();
    // cout << privObj.PublicVar; // ❌ Error: public became private

    return 0;
}
