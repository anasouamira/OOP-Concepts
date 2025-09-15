#include <iostream>
using namespace std;

/*
 * -------------------------------
 *  Base Class: clsPerson
 * -------------------------------
 * Represents a generic person with
 * ID, name, email, and phone number.
 */
class clsPerson
{
private:
    // Private data members – encapsulated (cannot be accessed directly)
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // Constructor: initializes a person’s data
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Read-only property: only a getter for ID
    int ID() { return _ID; }

    // Setters and Getters for each property
    void setFirstName(string FirstName) { _FirstName = FirstName; }
    string FirstName() { return _FirstName; }

    void setLastName(string LastName) { _LastName = LastName; }
    string LastName() { return _LastName; }

    void setEmail(string Email) { _Email = Email; }
    string Email() { return _Email; }

    void setPhone(string Phone) { _Phone = Phone; }
    string Phone() { return _Phone; }

    // Combine first and last name
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    // Display person info
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
        cout << "\nBody: " << Body << endl;
    }

    // Simulate sending an SMS
    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n"
             << TextMessage << endl;
    }
};

/*
 * -------------------------------
 *  Derived Class: clsEmployee
 * -------------------------------
 * Inherits from clsPerson (IS-A Person).
 * Adds employee-specific attributes.
 */
class clsEmployee : public clsPerson
{
private:
    string _Title;
    string _Department;
    float _Salary;

public:
    // Constructor: calls base constructor, then sets employee fields
    clsEmployee(int ID, string FirstName, string LastName,
                string Email, string Phone,
                string Title, string Department, float Salary)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    // Setters and Getters for employee data
    void setTitle(string Title) { _Title = Title; }
    string Title() { return _Title; }

    void setDepartment(string Department) { _Department = Department; }
    string Department() { return _Department; }

    void setSalary(float Salary) { _Salary = Salary; }
    float Salary() { return _Salary; }

    // Override Print to include employee info
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << ID();        // from clsPerson
        cout << "\nFirstName : " << FirstName(); // from clsPerson
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

/*
 * -------------------------------
 *  Derived Class: clsDeveloper
 * -------------------------------
 * Inherits from clsEmployee.
 * Adds a developer's main programming language.
 */
class clsDeveloper : public clsEmployee
{
private:
    string _MainProgrammingLanguage;

public:
    // Constructor: chains to clsEmployee constructor, then sets language
    clsDeveloper(int ID, string FirstName, string LastName,
                 string Email, string Phone,
                 string Title, string Department,
                 float Salary, string MainProgrammingLanguage)
        : clsEmployee(ID, FirstName, LastName, Email, Phone,
                      Title, Department, Salary)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    // Setter and Getter for main programming language
    void setMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    string MainProgrammingLanguage() { return _MainProgrammingLanguage; }

    // Override Print to include developer-specific field
    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << ID();
        cout << "\nFirstName : " << FirstName();
        cout << "\nLastName  : " << LastName();
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << Email();
        cout << "\nPhone     : " << Phone();
        cout << "\nTitle     : " << Title();
        cout << "\nDepartment: " << Department();
        cout << "\nSalary    : " << Salary();
        cout << "\nPLanguage : " << MainProgrammingLanguage();
        cout << "\n___________________\n";
    }
};

int main()
{
    // Create a Developer object with all required information
    clsDeveloper Developer1(
        10, "Mohammed", "Abu-Hadhoud",
        "A@a.com", "8298982",
        "Web Developer", "ProgrammingAdvices",
        5000, "C++");

    // Display all developer information
    Developer1.Print();

    // Send an SMS using inherited method from clsPerson
    Developer1.SendSMS("Hi mr Developer :-)");

    system("pause>0"); // Keep console window open on Windows
    return 0;
}
