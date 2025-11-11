#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string x;
    int y;

public:
    Person()
    {
        x = "unknown";
        y = 0;
    }
    void setPerson()
    {
        cout << "Enter your name: ";
        cin >> x;
        cout << "Enter your age: ";
        cin >> y;
    }
    void displayPerson()
    {
        cout << "NAME: " << x << "\nAGE: " << y << endl;
    }
};

class Student : public Person
{
protected:
    int a;
    string b;

public:
    Student()
    {
        a = 0;
        b = "unknown";
    }
    void setStudent()
    {
        cout << "Enter your roll number: ";
        cin >> a;
        cout << "Enter your course: ";
        cin >> b;
    }
    void displayStudent()
    {
        cout << "ROLL NUMBER: " << a << "\nCOURSE: " << b << endl;
    }
};

class Faculty : public Person
{
protected:
    int m;
    string n;

public:
    Faculty()
    {
        m = 0;
        n = "unknown";
    }
    void setFaculty()
    {
        cout << "Enter your faculty ID: ";
        cin >> m;
        cout << "Enter your department: ";
        cin >> n;
    }
    void displayFaculty()
    {
        cout << "FACULTY ID: " << m << "\nDEPARTMENT: " << n << endl;
    }
};

class TeachingAssistant : public Student, public Faculty
{
private:
    int hourPerWeek;

public:
    TeachingAssistant()
    {
        hourPerWeek = 0;
    }
    void setTeachingAssistant()
    {
        cout << "Enter your hours per week: ";
        cin >> hourPerWeek;
    }
    void displayTeachingAssistant()
    {
        cout << "HOUR PER WEEK: " << hourPerWeek << endl;
    }
};

int main()
{
    TeachingAssistant ta;

    ta.Student::setPerson();

    ta.setStudent();
    ta.setTeachingAssistant();

    cout << "\n--- Details ---\n";
    ta.Student::displayPerson();
    ta.displayStudent();
    ta.displayTeachingAssistant();
    return 0;
}