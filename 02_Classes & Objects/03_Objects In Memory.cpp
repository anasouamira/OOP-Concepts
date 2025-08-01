#include <iostream>
using namespace std;

/*
Objects in Memory - Detailed Explanation:

1. When you create an object from a class, like:
     clsPerson Person1;
   the system allocates a block of memory to store that object's data members.

2. Each object has its own separate memory space for its data members.
   For example:
     Person1.FirstName and Person2.FirstName
   are stored at different memory locations and can hold different values.

3. The size of the memory allocated depends on the combined size of all data members.
   For example, if a class has two strings and one int, the memory must hold all three.

4. Member functions (methods) do NOT consume memory per object instance.
   They are stored once in the program's code segment and shared by all objects of the class.

5. When you access or modify a data member, you're reading or writing to that object's unique memory area.

6. Objects can be created in:
   - Stack memory (automatic storage), e.g., declared inside a function.
   - Heap memory (dynamic storage), using pointers and 'new' operator.

7. Understanding objects in memory helps:
   - Optimize memory usage
   - Understand object copying and assignment
   - Manage object lifetime and scope

-------------------------------------------------------------
| Category          | Description                                   |
|-------------------|-----------------------------------------------|
| Object Instance   | A block of memory holding the object's data members. |
| Data Members      | Variables inside the object; each has its own space.  |
| Member Functions  | Stored once, shared by all objects, not duplicated.   |
| Memory Location   | Objects may reside in stack or heap memory.           |
| Size              | Sum of sizes of all data members determines object size. |

Example: For class clsPerson with
  - string FirstName
  - string LastName
  - int x (private)
Each object stores these data members separately in memory.
Methods like FullName() are shared and don't occupy extra space per object.
*/

class clsPerson {
    int x; // private data member, occupies memory per object

public:
    string FirstName;  // data member, memory allocated per object
    string LastName;   // data member, memory allocated per object

    string FullName() {
        return FirstName + " " + LastName;
    }
};

int main() {
    clsPerson Person1;
    clsPerson Person2;

    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";

    Person2.FirstName = "Sarah";
    Person2.LastName = "Johnson";

    cout << Person1.FullName() << endl; // Outputs: Mohammed Abu-Hadhoud
    cout << Person2.FullName() << endl; // Outputs: Sarah Johnson

    return 0;
}
