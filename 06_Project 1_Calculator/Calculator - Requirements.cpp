#include<iostream>
using namespace std;

// Class encapsulates all calculator logic, exposing only necessary operations to the user.
// This is an example of Abstraction: we hide internal logic like error handling and last operation tracking.
class clsCalculator {
private:
    // These private variables store the state of the calculator.
    // They are hidden from the outside to protect internal logic.
    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation = "Clear";
    float _PreviousResult = 0;

    // This helper function checks if a number is zero.
    // It's not needed by the user, so it's kept private.
    bool _IsZero(float Number) {
        return (Number == 0);
    }

public:
    // Public method: Adds a number to the result.
    void Add(float Number) {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    // Public method: Subtracts a number from the result.
    void Subtract(float Number) {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Number;
    }

    // Public method: Divides the result by a number.
    // If the number is zero, it replaces it with 1 to avoid division by zero.
    void Divide(float Number) {
        _LastNumber = Number;
        if (_IsZero(Number)) {
            Number = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }

    // Public method: Multiplies the result by a number.
    void Multiply(float Number) {
        _LastNumber = Number;
        _LastOperation = "Multiplying";
        _PreviousResult = _Result;
        _Result *= Number;
    }

    // This method returns the current result.
    float GetFinalResults() {
        return _Result;
    }

    // Resets the calculator.
    void Clear() {
        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }

    // Reverts to the result before the last operation.
    void CancelLastOperation() {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }

    // Prints the current result and last operation to the user.
    void PrintResult() {
        cout << "Result ";
        cout << "After " << _LastOperation << " " << _LastNumber << " is: " << _Result << "\n";
    }
};

int main() {
    clsCalculator Calculator1;

    Calculator1.Clear();
    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Subtract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(3);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    system("pause>0");
    return 0;
}
