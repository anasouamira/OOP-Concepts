#include <iostream>
using namespace std;

/*
 * ---------------------------
 * Base Class: clsA
 * ---------------------------
 * Demonstrates different access
 * specifiers: private, protected, public.
 */
class clsA
{
private:
    // ===== PRIVATE =====
    // Accessible ONLY inside clsA.
    // Not accessible in derived classes or from objects.
    int _Var1;

    void _Fun1()
    {
        cout << "Function 1 (private)" << endl;
    }

protected:
    // ===== PROTECTED =====
    // Accessible inside clsA AND any class that inherits from clsA.
    // Not accessible directly from objects of clsA or its children.
    int Var2;

    void Fun2()
    {
        cout << "Function 2 (protected)" << endl;
    }

public:
    // ===== PUBLIC =====
    // Accessible everywhere:
    // inside clsA, derived classes, and directly from objects.
    int Var3;

    void Fun3()
    {
        cout << "Function 3 (public)" << endl;
    }
};

/*
 * ---------------------------
 * Derived Class: clsB
 * ---------------------------
 * Inherits publicly from clsA,
 * so:
 *   - public members of clsA stay public in clsB.
 *   - protected members stay protected.
 *   - private members remain inaccessible.
 */
class clsB : public clsA
{
public:
    void Func1()
    {
        // We can access Var2 here because it's protected in clsA,
        // and protected members are accessible inside derived classes.
        cout << Var2 << endl;

        // We can also call Fun2() here if we wanted:
        // Fun2();

        // We CANNOT access _Var1 or _Fun1() because they are private in clsA.
        // cout << _Var1;     // ❌ Error
        // _Fun1();          // ❌ Error
    }
};

int main()
{
    clsB objB;

    // Public members of clsA are accessible through objB:
    objB.Var3 = 100;
    objB.Fun3();

    // Protected and private members are NOT accessible through the object:
    // objB.Var2 = 10;   // ❌ Error: Var2 is protected
    // objB._Var1 = 20;  // ❌ Error: _Var1 is private

    // We can, however, call the derived class's method
    // which can access protected members internally:
    objB.Func1(); // prints Var2 (default-initialized, likely 0)

    system("pause>0");
    return 0;
}
