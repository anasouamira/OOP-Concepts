#include <iostream>
using namespace std;

// Define a class to represent a Person
class clsPerson {
private:
    // Private attributes (encapsulation - only accessible within the class)
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // Constructor to initialize a person with required data
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Read-only property: returns the ID (no setter, so cannot be changed from outside)
    int ID() {
        return _ID;
    }

    // Setter for FirstName (allows changing first name from outside)
    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    // Getter for FirstName
    string FirstName() {
        return _FirstName;
    }

    // Setter for LastName
    void setLastName(string LastName) {
        _LastName = LastName;
    }

    // Getter for LastName
    string LastName() {
        return _LastName;
    }

    // Setter for Email
    void setEmail(string Email) {
        _Email = Email;
    }

    // Getter for Email
    string Email() {
        return _Email;
    }

    // Setter for Phone
    void setPhone(string Phone) {
        _Phone = Phone;
    }

    // Getter for Phone
    string Phone() {
        return _Phone;
    }

    // Returns the full name by combining first and last names
    string FullName() {
        return _FirstName + " " + _LastName;
    }

    // Prints the full details of the person
    void Print() {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID        : " << _ID;
        cout << "\nFirstName : " << _FirstName;
        cout << "\nLastName  : " << _LastName;
        cout << "\nFull Name : " << FullName();
        cout << "\nEmail     : " << _Email;
        cout << "\nPhone     : " << _Phone;
        cout << "\n___________________\n";
    }

    // Simulates sending an email
    void SendEmail(string Subject, string Body) {
        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody   : " << Body << endl;
    }

    // Simulates sending an SMS
    void SendSMS(string TextMessage) {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }
};

int main() {
    // Create an object of clsPerson with initial values
    clsPerson Person1(10, "Mohammed", "Abu-Hadhoud", "my@gmail.com", "0098387727");

    // Display all details
    Person1.Print();

    // Simulate sending an email
    Person1.SendEmail("Hi", "How are you?");

    // Simulate sending a text message
    Person1.SendSMS("How are you?");

    // Pause the console window (Windows only)
    system("pause>0");

    return 0;
}
