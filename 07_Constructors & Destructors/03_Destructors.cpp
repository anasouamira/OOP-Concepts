#include <iostream>
using namespace std;

// Define a class named clsPerson
class clsPerson {
public:
    string FullName;

    // Constructor: Called automatically when an object is created
    clsPerson() {
        FullName = "Mohammed Abu-Hadhoud";
        cout << "\nHi, I'm Constructor"; // Message to indicate constructor is called
    }

    // Destructor: Called automatically when an object is destroyed
    ~clsPerson() {
        cout << "\nHi, I'm Destructor"; // Message to indicate destructor is called
    }
};

// Function that creates a local object (allocated on the stack)
void Fun1() {
    clsPerson Person1; 
    // Constructor is called when Person1 is created
    // When the function ends, Person1 goes out of scope
    // Destructor is automatically called to clean up
}

// Function that creates a dynamic object (allocated on the heap)
void Fun2() {
    clsPerson* Person2 = new clsPerson;
    // Constructor is called when the object is created using new

    delete Person2; 
    // Destructor is called when we explicitly delete the object
    // If we forget to use delete, the object stays in memory (memory leak)
}

int main() {
    Fun1(); // Calls constructor and destructor automatically
    Fun2(); // Calls constructor and destructor manually

    system("pause>0");
    return 0;
}
