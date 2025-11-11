#include <bits/stdc++.h>
using namespace std;

class Vehicle {
    public:
    string vehicleName;

    Vehicle(string vn){
        vehicleName = vn; 
    }
};

class Bus : public Vehicle{
    protected:
    int distance;
    int farePerKm;

    public:
    Bus(string vn, int d, int f) : Vehicle(vn){
        distance = d;
        farePerKm = f;
    }

    int calculateFare(){
        int fare = distance * farePerKm;

        return fare;
    }

    void operator+(Bus &b){
        int totalfare = this->calculateFare() + b.calculateFare();
        cout<<"Total fare : "<<totalfare<<endl;
    }

};

class Taxi : public Vehicle{
    protected:
    int hours;
    int ratePerHour;

    public:
    Taxi(string vn, int h, int r) : Vehicle(vn){
        hours = h;
        ratePerHour = r;
    }

    void calculateFare(){
        int rate = hours * ratePerHour;

        cout<<"Taxi rate : "<<rate<<endl;
    }
};

int main(){
    Bus b1("bus1", 20, 150);
    Bus b2("bus2", 30, 250);

    b1 + b2;

    Taxi T("Taxi1",5, 250);
    T.calculateFare();

    return 0;
}

