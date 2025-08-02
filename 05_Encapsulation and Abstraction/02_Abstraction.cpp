#include <iostream>
using namespace std;

// -------------------------------------------------
// Abstraction in C++
// -------------------------------------------------
// Abstraction involves hiding the implementation details
// and exposing only what is necessary for the user to interact with.
// In C++, abstraction is often achieved using abstract classes:
// - An abstract class is a class that contains at least one pure virtual function.
// - Pure virtual functions define the interface but leave the implementation
//   to derived (child) classes.
// -------------------------------------------------

// Abstract class representing a general Shape.
class Shape {
public:
    // Pure virtual function: forces derived classes to implement Draw().
    // This is the abstract interface for drawing a shape.
    virtual void Draw() = 0;
};

// Concrete class representing a Circle, derived from Shape.
class Circle : public Shape {
public:
    // Implements the abstract Draw method for a circle.
    void Draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    // Here, we create an instance of Circle.
    // The user interacts with the Circle object through the Draw method,
    // without needing to know how the drawing is actually implemented.
    Circle circle;
    circle.Draw();  // Output: Drawing a circle.

    
    return 0;
}
