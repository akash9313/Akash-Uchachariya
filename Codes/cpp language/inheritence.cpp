#include <bits/stdc++.h>
using namespace std;

class Person{
    public:

    string name;
    void setName(string n){
        name = n;
    }
    void displayName(){
        cout<<"Name of Employee : "<<name<<endl;
    }
};

class Employee : public Person{
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
    Employee E;
    E.setName("Akash");
    E.displayName();
    E.setSalary(1000000);
    E.displaySalary();

    return 0;
}