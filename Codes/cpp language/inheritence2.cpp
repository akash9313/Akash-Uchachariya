#include <bits/stdc++.h>
using namespace std;

class Person{
    public:

    string name;
    string city;
    void setName(string n, string c){
        name = n;
        city = c;
    }
    void displayName(){
        cout<<"Name of Employee : "<<name<<endl;
        cout<<"City of Employee : "<<city<<endl;
    }
};

class Employee{
    public:
    int salary;
    void setSalary(int s){
        salary = s;
    }
    void displaySalary(){
        cout<<"Salary : "<<salary;
    }
};

int main()
{
    Person P;
    Employee E;
    P.setName("Akash", "Bhachau");
    P.displayName();
    E.setSalary(1000000);
    E.displaySalary();

    return 0;
}