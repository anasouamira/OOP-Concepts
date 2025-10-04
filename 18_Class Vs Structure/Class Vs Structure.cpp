#include <iostream>
using namespace std;

/*
🔹 Similarities between class and struct in C++

Both can:
- Contain data members (variables).
- Contain member functions (methods).
- Have constructors and destructors.
- Support inheritance.
- Support access specifiers (public, protected, private).
- Support polymorphism (when using virtual functions).

So unlike C (where struct is just a data container), 
in C++ both class and struct are very similar.

🔹 Key Differences between class and struct in C++

Feature                class                               struct
---------------------------------------------------------------------------
Default Access Spec.   private (by default)                public (by default)
Default Inheritance    private inheritance                 public inheritance
Usage Convention       Usually used for OOP                Usually used for plain 
                       (encapsulation, abstraction,        data structures 
                        polymorphism).                     (like grouping vars).
Compatibility with C   Not compatible with C.              Compatible with C struct style.
Readability            Used when you want to hide          Used for lightweight 
                       implementation details.             objects or PODs.
*/


// ===============================
// Structure Example
// ===============================
struct Student {
    // 🔹 By default, members in struct are PUBLIC
    int id;        // anyone can access directly
    string name;   // anyone can access directly

    // Member function to print student info
    void print() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// ===============================
// Class Example
// ===============================
class Employee {
    // 🔹 By default, members in class are PRIVATE
    int id;        // cannot be accessed directly outside the class
    string name;   // cannot be accessed directly outside the class

public: 
    // Constructor (called when creating an object)
    Employee(int i, string n) {
        id = i;
        name = n;
    }

    // Public function to print employee info
    void print() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    // -------- STRUCT USAGE --------
    Student s1;        // create a struct object
    s1.id = 101;       // ✅ allowed (public by default)
    s1.name = "Ali";   // ✅ allowed (public by default)
    s1.print();        // call struct function

    // -------- CLASS USAGE --------
    Employee e1(201, "Sara");  
    // e1.id = 201;    // ❌ ERROR: id is private by default in class
    // e1.name = "Sara"; // ❌ ERROR: name is private
    e1.print();        // ✅ must use public function to access private data

    return 0;
}
