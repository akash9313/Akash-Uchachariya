#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    int roll_no;
    string city;
    int age;

public:
    Student(string n, int r, string c, int a)
    {
        name = n;
        roll_no = r;
        city = c;
        age = a;
    }

    void display_details()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "City: " << city << endl;
        cout << "Age: " << age << endl;
    }

    bool search_by_roll_no(int r)
    {
        return roll_no == r;
    }

    void calculate_avg_age()
    {
        double avg_age = age;
        cout << "Average Age: " << avg_age << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student *students[n];

    for (int i = 0; i < n; i++)
    {
        string name, city;
        int roll_no, age;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Roll No: ";
        cin >> roll_no;
        cout << "City: ";
        cin >> city;
        cout << "Age: ";
        cin >> age;

        students[i] = new Student(name, roll_no, city, age);
    }

    cout << "Student Details:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Details of student " << i + 1 << ":" << endl;
        students[i]->display_details();
        cout << endl;
    }

    return 0;
}