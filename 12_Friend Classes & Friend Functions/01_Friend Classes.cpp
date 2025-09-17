// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsA
{
private:
    int _Var1;     // ✅ Private: normally only accessible inside clsA.

protected:
    int _Var3;     // ✅ Protected: normally accessible only inside clsA and its derived classes.

public:
    int Var2;      // ✅ Public: accessible from anywhere.

    // Constructor initializes all members
    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    // Friend class declaration
    // 👉 This line gives clsB full access to all private/protected members of clsA.
    friend class clsB;
};

class clsB
{
public:
    // This method can access clsA's private and protected members
    void display(clsA A1)
    {
        cout << "\nThe value of Var1 = " << A1._Var1; // Accessing private member of clsA
        cout << "\nThe value of Var2 = " << A1.Var2;  // Accessing public member of clsA
        cout << "\nThe value of Var3 = " << A1._Var3; // Accessing protected member of clsA
    }
};

int main()
{
    clsA A1;
    clsB B1;

    // clsB is a friend of clsA, so B1 can access private/protected members of A1
    B1.display(A1);

    system("pause>0");
    return 0;
}
