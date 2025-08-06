#include <iostream>
using namespace std;

// Define a class named clsA
class clsA {
public:
    // Static method: belongs to the class, not to any specific object
    static int Function1() {
        return 10;
    }

    // Non-static method: belongs to each object separately
    int Function2() {
        return 20;
    }
};

int main() {
    // Static function is called directly via the class name
    // This is the recommended way to call static methods
    cout << clsA::Function1() << endl;

    // You can also call a static function through an object
    clsA A1, A2;

    // Calling static function via object A1
    cout << A1.Function1() << endl;

    // Calling non-static function via object A1
    cout << A1.Function2() << endl;

    // Calling static function again via another object A2
    cout << A2.Function1() << endl;

    return 0;
}
