#include <iostream>
using namespace std;

class clsA
{
private:
    // -------- PRIVATE --------
    // Only accessible inside clsA.
    int V1;
    int Fun1()
    {
        return 1;
    }

protected:
    // -------- PROTECTED --------
    // Accessible inside clsA and any class derived from clsA,
    // but NOT directly accessible from an object.
    int V2;
    int Fun2()
    {
        return 2;
    }

public:
    // -------- PUBLIC --------
    // Accessible from anywhere: inside clsA, derived classes,
    // and directly from objects.
    int V3;
    int Fun3()
    {
        return 3;
    }
};

/*
 * clsB inherits from clsA with **private** visibility.
 * ----------------------------------------------
 * Rules:
 * - All public and protected members of clsA become **private** in clsB.
 * - Private members of clsA are still inaccessible.
 * => From outside, an object of clsB cannot access V3 or Fun3 anymore!
 */
class clsB : private clsA
{
public:
    int Fun4()
    {
        // Inside clsB, we can still access protected and public members of clsA
        // because inheritance always gives access to those internally.
        V2 = 20;          // ✅ allowed inside clsB
        V3 = 30;          // ✅ allowed inside clsB
        return 4;
    }
};

/*
 * clsC inherits from clsB with **public** visibility.
 * ---------------------------------------------------
 * BUT: because clsB inherited clsA privately,
 * all clsA members inside clsB are treated as private.
 * So clsC CANNOT see clsA's V2 or V3 at all.
 */
class clsC : public clsB
{
public:
    int Fun5()
    {
        // We cannot access V2 or V3 here,
        // because clsB made them private when inheriting from clsA.
        return 5;
    }
};

int main()
{
    clsB B1;
    // Because clsB inherited clsA privately:
    // B1.V3;       // ❌ Error: V3 is private inside clsB
    // B1.Fun3();   // ❌ Error: Fun3 is private inside clsB
    B1.Fun4();      // ✅ We can call B1's own public method.

    clsC C1;
    // clsC also cannot access V3 or Fun3:
    // C1.V3;      // ❌ Error
    // C1.Fun3();  // ❌ Error
    C1.Fun4();      // ✅ Allowed (Fun4 is public in clsB)
    C1.Fun5();      // ✅ Allowed
}
