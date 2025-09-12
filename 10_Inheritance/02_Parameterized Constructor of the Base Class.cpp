#include <iostream>
using namespace std;

/* ================================
   Base Class: clsPerson
   Represents a generic person
   ================================ */
class clsPerson
{
private:
    // ---------- Private Data Members ----------
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // ---------- Constructor ----------
    // Initializes all private members when a new clsPerson object is created.
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // ---------- Getters & Setters ----------
    // Read-only property for ID
    int ID() { return _ID; }

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

/* ================================
   Derived Class: clsEmployee
   Extends clsPerson and adds
   employee-specific information
   ================================ */
class clsEmployee : public clsPerson
{
private:
    string _Title;       // Job title (e.g., CEO)
    string _Department;  // Department name
    float  _Salary;      // Employee salary

public:
    // ---------- Constructor ----------
    // Uses an *initializer list* to call the clsPerson constructor
    // to initialize all inherited (base) data members.
    clsEmployee(int ID, string FirstName, string LastName,
                string Email, string Phone,
                string Title, string Department, float Salary)
        : clsPerson(ID, FirstName, LastName, Email, Phone) // base-class init
    {
        _Title      = Title;
        _Department = Department;
        _Salary     = Salary;
    }

    // ---------- Getters & Setters for employee-specific fields ----------
    void setTitle(string Title)        { _Title = Title; }
    string Title()                     { return _Title; }

    void setDepartment(string Department) { _Department = Department; }
    string Department()                   { return _Department; }

    void setSalary(float Salary)       { _Salary = Salary; }
    float Salary()                     { return _Salary; }
};

/* ================================
   MAIN FUNCTION
   Demonstrates inheritance in use
   ================================ */
int main()
{
    // Create an Employee object and initialize both base and derived class data.
    clsEmployee Employee1(
        10,
        "Mohammed",
        "Abu-Hadhoud",
        "A@a.com",
        "8298982",
        "CEO",
        "ProgrammingAdvices",
        5000
    );

    // Print all base-class (Person) details
    Employee1.Print();

    // Print derived-class (Employee) details
    cout << "\n" << Employee1.Title()      << endl;
    cout << "\n" << Employee1.Department() << endl;
    cout << "\n" << Employee1.Salary()     << endl;

    system("pause>0"); // Keep console window open on Windows
    return 0;
}
