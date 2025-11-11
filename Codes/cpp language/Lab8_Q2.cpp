#include<bits/stdc++.h>
using namespace std;

class Employee{
    protected:
        string name;
        int emplID;

    public:
        const string CompanyName = "Tata";
        static int totalEmployees;

        Employee(string empName, int id){
            name = empName;
            emplID = id;
            totalEmployees++;
        }

        virtual ~Employee(){ 
            totalEmployees--;
        }

        virtual void calculateSalary() = 0; 

        static void showEmployeeCount(){
            cout<<"Total employees in the company: "<<totalEmployees<<endl;
        }
};

int Employee::totalEmployees = 0;


class PermanentEmployee : public Employee{
    protected:
        double basicSalary, bonus;
    public:
        PermanentEmployee(string empName, int id, double basic, double bon) : Employee(empName, id){
            basicSalary = basic;
            bonus = bon;
        }

        void calculateSalary() override{ 
            cout<<"Salary of permanent employee "<<name<<" is "<<(basicSalary + bonus)<<endl;
        }
};

class ContractEmployee : public Employee{
    protected:
        double hourlyRate;
        int hoursWorked;
    public:
        ContractEmployee(string empName, int id, double rate, int hours) : Employee(empName, id){
            hourlyRate = rate;
            hoursWorked = hours;
        }

        void calculateSalary() override{
            cout<<"Salary of contract employee "<<name<<" is "<<(hourlyRate * hoursWorked)<<endl;
        }
};

class Intern final : public Employee{
    protected:
        double stipend;
    public:
        Intern(string empName, int id, double stip) : Employee(empName, id){
            stipend = stip;
        }

        void calculateSalary() override{
            cout<<"Stipend of intern "<<name<<" is "<<stipend<<endl;
        }
};

int main(){
    PermanentEmployee pe1("AKash", 101, 50000, 5000);
    pe1.calculateSalary();

    ContractEmployee ce1("Umang", 102, 200, 160);
    ce1.calculateSalary();

    Intern in1("Keval", 103, 15000);
    in1.calculateSalary();

    Employee::showEmployeeCount();

    return 0;
}
