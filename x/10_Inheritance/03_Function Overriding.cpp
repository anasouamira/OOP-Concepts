#include <iostream>
using namespace std;

/*
 * Base class: clsPerson
 * Represents a general person with personal information.
 */
class clsPerson
{
private:
    // Private data members (encapsulation: these cannot be accessed directly outside the class)
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // Constructor: initializes all person fields when creating an object
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Read-only property: returns ID (no setter provided, so ID cannot be changed)
    int ID()
    {
        return _ID;
    }

    // Setter and Getter for FirstName
    void setFirstName(string FirstName) { _FirstName = FirstName; }
    string FirstName() { return _FirstName; }

    // Setter and Getter for LastName
    void setLastName(string LastName) { _LastName = LastName; }
    string LastName() { return _LastName; }

    // Setter and Getter for Email
    void setEmail(string Email) { _Email = Email; }
    string Email() { return _Email; }

    // Setter and Getter for Phone
    void setPhone(string Phone) { _Phone = Phone; }
    string Phone() { return _Phone; }

    // Returns the full name by combining first and last names
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    // Prints all person information
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

    // Simulate sending an email to the person's email address
    void SendEmail(string Subject, string Body)
    {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;
    }

    // Simulate sending an SMS to the person's phone
    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }
};

/*
 * Derived class: clsEmployee
 * Inherits from clsPerson (IS-A relationship: Employee is a Person).
 * Adds employee-specific details like Title, Department, and Salary.
 */
class clsEmployee : public clsPerson
{
private:
    // Additional private data members specific to an employee
    string _Title;
    string _Department;
    float _Salary;

public:
    // Constructor: calls the base constructor to set person data
    // and initializes employee-specific members
    clsEmployee(int ID, string FirstName, string LastName,
                string Email, string Phone,
                string Title, string Department, float Salary)
        : clsPerson(ID, FirstName, LastName, Email, Phone) // base class constructor
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    // Setter and Getter for Title
    void setTitle(string Title) { _Title = Title; }
    string Title() { return _Title; }

    // Setter and Getter for Department
    void setDepartment(string Department) { _Department = Department; }
    string Department() { return _Department; }

    // Setter and Getter for Salary
    void setSalary(float Salary) { _Salary = Salary; }
    float Salary() { return _Salary; }

    // Override Print method to include employee-specific details
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << ID();          // Access base class method
        cout << "\nFirstName : " << FirstName();    // Access base class method
        cout << "\nLastName  : " << LastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << Email();
        cout << "\nPhone     : " << Phone();
        cout << "\nTitle     : " << _Title;
        cout << "\nDepartment: " << _Department;
        cout << "\nSalary    : " << _Salary;
        cout << "\n___________________\n";
    }
};

int main()
{
    // Create an employee object with all required details
    clsEmployee Employee1(
        10, "Mohammed", "Abu-Hadhoud",
        "A@a.com", "8298982",
        "CEO", "ProgrammingAdvices", 5000);

    // Print all information of the employee
    Employee1.Print();

    system("pause>0"); // Pause console on Windows
    return 0;
}
