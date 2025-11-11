#include <bits/stdc++.h>
using namespace std;

class Drone{
    protected:
        const string droneID;
        
    public:
        Drone(string id){
            droneID = id;
        }

        virtual void deliverPackage() = 0;
        static void showTotalDeliveries(){
            cout << "Total deliveries made: " <<<< endl;
        }
}

class CityDrone : public Drone{
    protected:
        string City;

    public:
        CityDrone(string id, string cityName) : Drone(id), city(cityName) {
            city = cityName;
        }

        void deliverPackage() override {
            cout << "City Drone " << droneID << " is delivering a package in " << city << "." << endl;
        }
}