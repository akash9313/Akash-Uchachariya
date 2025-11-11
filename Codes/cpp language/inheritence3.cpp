#include <bits/stdc++.h>
using namespace std;

class Time{
    public:
    int hours, minutes;
    Time(int h, int m){
        hours = h;
        minutes = m;
    }

    Time add(Time T){
        Time temp;
        temp.minutes = minutes + T.minutes;
        temp.hours = hours + T.hours + (temp.minutes/60);
        temp.minutes = temp.minutes % 60;
        return temp;
    };

    void displayTime(){
        cout<<hours<<" hours "<<minutes<<" minutes "<<endl;
    }
};

int main()
{
    Time T1(5,45),T2(8,25),T3;
    T3 = T1.add(T2);

    cout<<"1st time : "<<endl;
    T1.displayTime();

    cout<<"2nd time : "<<endl;
    T2.displayTime();

    cout<<"Sum of time : "<<endl;
    T3.displayTime();

    return 0;
}