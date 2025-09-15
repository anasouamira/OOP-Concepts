#include <iostream>
using namespace std;

/* ============================
   Base Class: clsPerson
   Represents a generic person with personal details
   ============================ */
class clsPerson
{
private:
    // Encapsulated (private) data members
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // Default constructor:
    // Added here temporarily because the derived class (clsEmployee)
    // needs to call a base-class constructor when it is created.
    // In future, we can improve it with a parameterized constructor for inheritance.
    clsPerson()
    {
        // No initialization here, just to satisfy inheritance needs.
    }

    // Parameterized constructor to initialize all fields
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // ---------- Getters & Setters ----------
    int ID() { return _ID; }                 // Read-only: can't set ID from outside
    void setFirstName(string FirstName) { _FirstName = FirstName; }
    string FirstName() { return _FirstName; }
    void setLastName(string LastName) { _LastName = LastName; }
    string LastName() { return _LastName; }
    void setEmail(string Email) { _Email = Email; }
    string Email() { return _Email; }
    void setPhone(string Phone) { _Phone = Phone; }
    string Phone() { return _Phone; }

    // Combines first and last name
    string FullName() { return _FirstName + " " + _LastName; }

    // Print all details of the person
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID       : " << _ID;
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";
    }

    // Simulate sending an email
    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody   : " << Body << endl;
    }

    // Simulate sending an SMS
    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }
};

/* ============================
   Derived Class: clsEmployee
   Inherits from clsPerson
   Adds extra attributes specific to employees
   ============================ */
class clsEmployee : public clsPerson
{
private:
    string _Title;      // Job title (e.g., Manager, Engineer)
    string _Department; // Department name
    float _Salary;      // Employee salary

public:
    // Extra properties only for employees
    void setTitle(string Title) { _Title = Title; }
    string Title() { return _Title; }

    void setDepartment(string Department) { _Department = Department; }
    string Department() { return _Department; }

    void setSalary(float Salary) { _Salary = Salary; }
    float Salary() { return _Salary; }
};

/* ============================
   MAIN PROGRAM
   Demonstrates inheritance in action
   ============================ */
int main()
{
    // Create an employee object.
    // The default constructor of clsPerson is called first automatically.
    clsEmployee Employee1;

    // Set base-class (Person) data using inherited setters
    Employee1.setFirstName("Mohammed");
    Employee1.setLastName("Abu-Hadhoud");
    Employee1.setEmail("a@a.com");

    // Use base-class method to print personal info
    Employee1.Print();

    // Send an email using inherited method
    Employee1.SendEmail("Hi", "How are you?");

    // Set and display salary (specific to Employee)
    Employee1.setSalary(5000);
    cout << "Salary is: " << Employee1.Salary() << endl;

    // Print again (still prints only base-class details,
    // not the new Employee-only fields like salary/title/department)
    // This limitation will be fixed later (for example by overriding Print()).
    Employee1.Print();

    system("pause>0"); // Pause console on Windows
    return 0;
}
