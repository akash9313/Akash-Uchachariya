#include <iostream>
using namespace std;

class TaxDetails
{
public:
    virtual double taxCalculation(double salary) = 0;
};

class Employee
{
protected:
    string name;
    int empid;
    double baseSalary;

public:
    Employee(string n, int id, double sal) : name(n), empid(id), baseSalary(sal) {}
    virtual void displayDetails()
    {
        cout << "Name: " << name << "\nEmpID: " << empid << "\nBase Salary: " << baseSalary << endl;
    }
    virtual double calculateSalary() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee, public TaxDetails
{
    double allowance;

public:
    FullTimeEmployee(string n, int id, double sal, double allw)
        : Employee(n, id, sal), allowance(allw) {}
    double calculateSalary() override
    {
        return baseSalary + allowance;
    }
    double taxCalculation(double salary) override
    {
        return salary * 0.10;
    }
    void displayDetails() override
    {
        double salary = calculateSalary();
        cout << "\nFull Time Employee\n";
        Employee::displayDetails();
        cout << "Allowance: " << allowance << "\nSalary: " << salary
             << "\nTax: " << taxCalculation(salary) << endl;
    }
};

class PartTimeEmployee : public Employee, public TaxDetails
{
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string n, int id, int hrs, double rate)
        : Employee(n, id, 0), hoursWorked(hrs), hourlyRate(rate) {}
    double calculateSalary() override
    {
        return hoursWorked * hourlyRate;
    }
    double taxCalculation(double salary) override
    {
        return salary * 0.05;
    }
    void displayDetails() override
    {
        double salary = calculateSalary();
        cout << "\nPart Time Employee\n";
        cout << "Name: " << name << "\nEmpID: " << empid
             << "\nHours Worked: " << hoursWorked << "\nHourly Rate: " << hourlyRate
             << "\nSalary: " << salary << "\nTax: " << taxCalculation(salary) << endl;
    }
};

class Intern : public Employee, public TaxDetails
{
    double stipend;

public:
    Intern(string n, int id, double stp)
        : Employee(n, id, 0), stipend(stp) {}
    double calculateSalary() override
    {
        return stipend;
    }
    double taxCalculation(double salary) override
    {
        return salary * 0.02;
    }
    void displayDetails() override
    {
        double salary = calculateSalary();
        cout << "\nIntern\n";
        cout << "Name: " << name << "\nEmpID: " << empid
             << "\nStipend: " << stipend << "\nSalary: " << salary
             << "\nTax: " << taxCalculation(salary) << endl;
    }
};

int main()
{
    Employee *e1 = new FullTimeEmployee("Akash", 202451011, 50000, 10000);
    Employee *e2 = new PartTimeEmployee("Keval", 202451088, 120, 200);
    Employee *e3 = new Intern("Umang", 202451110, 15000);

    e1->displayDetails();
    e2->displayDetails();
    e3->displayDetails();

    delete e1;
    delete e2;
    delete e3;
    return 0;
}
