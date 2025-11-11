#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string Name;
    int Rollno;
    int Age;
    void StudentDetail(string name, int rollno, int age){
        Name = name;
        Rollno = rollno;
        Age = age;
    }

};

class UGstudent:public Student{
    public:

    int Semester;
        int Fee;
        int Stipend;

    void UGstudentDetail(int sem,int fee,int stipend){
        Semester = sem;
        Fee = fee;
        Stipend = stipend;
    }

};

int main()
{
   UGstudent U1, U2, U3, U4, U5;
   U1.StudentDetail("Akash",202451011,19);
   U2.StudentDetail("Darshit",202451041,17);
   U3.StudentDetail("Umang",202451110,17);
   U4.StudentDetail("Keval",202451088,18);
   U5.StudentDetail("Ayush",202451029,18);

   float average = (U1.Age + U2.Age + U3.Age + U4.Age + U5.Age)/5.0;
   cout<<average;

    return 0;
}