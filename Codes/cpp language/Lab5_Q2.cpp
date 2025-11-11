#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int rollno;
    Student(string n, int r){
        name = n;
        rollno = r;
    }
};

class Sports : virtual public Student{
    public:
    int grade;

    Sports(string n, int r, int g) : Student(n,r) {
        grade = g;
    }
};

class Exam : virtual public Student{
    public:
    int e_grade;

    Exam(string n, int r, int eg) : Student(n,r){
        e_grade = eg;
    }
};

class Results : public Sports, public Exam{
    public:
    string FinalResult;
    Results(string n, int r, int g, int eg, string f) : Student(n,r), Sports(n,r,g), Exam(n,r,eg){
        FinalResult = f;
    }

    void Display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll no : "<<rollno<<endl;
        cout<<"Grade in sports : "<<grade<<endl;
        cout<<"Grade in Exam : "<<e_grade<<endl;
        cout<<"Final result : "<<FinalResult<<endl;
    }
};

int main(){
    Results R("Akash", 202451011, 67, 75, "Pass");
    R.Display();

    return 0;
}

