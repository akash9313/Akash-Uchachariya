#include<iostream>
using namespace std;

class Vehicle{
    private:
    string Brand;
    string Model;
    int Speed;

    public:
    Vehicle(){
        Brand = "unknown";
        Model = "unknown";
        Speed = 0;
    }

    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;

    void setBrand(string b) { 
        Brand = b; 
    }
    string getBrand() const { 
        return Brand; 
    }

    void setModel(string m) { 
        Model = m; 
    }
    string getModel() const { 
        return Model; 
    }

    void setSpeed(int s) { 
        Speed = s; 
    }
    int getSpeed() const { 
        return Speed; 
    }
};

class Maintenance{
    public:

    virtual void service() = 0;
    virtual void checkOil() = 0;
};

class Car: public Vehicle, public Maintenance{
    public:
    void SetBrand(string b) {
        setBrand(b);
    }
    string GetBrand() const {
        return getBrand();
    }
    void SetModel(string m) {
        setModel(m);
    }
    string GetModel() const {
        return getModel();
    }
    void SetSpeed(int s) {
        setSpeed(s);
    }
    int GetSpeed() const {
        return getSpeed();
    }

    void startEngine() override {
        cout << "Car engine started." << endl;
    }
    void stopEngine() override {
        cout << "Car engine stopped." << endl;
    }
    void service() override {
        cout << "Car serviced." << endl;
    }
    void checkOil() override {
        cout << "Car oil checked." << endl;
    }
};

class Bike: public Vehicle, public Maintenance{
    public:

    void SetBrand(string b) {
        setBrand(b);
    }
    string GetBrand() const {
        return getBrand();
    }
    void SetModel(string m) {
        setModel(m);
    }
    string GetModel() const {
        return getModel();
    }
    void SetSpeed(int s) {
        setSpeed(s);
    }
    int GetSpeed() const {
        return getSpeed();
    }

    void startEngine() override {
        cout << "Bike engine started." << endl;
    }
    void stopEngine() override {
        cout << "Bike engine stopped." << endl;
    }
    void service() override {
        cout << "Bike serviced." << endl;
    }
    void checkOil() override {
        cout << "Bike oil checked." << endl;
    }
};

int main(){
    Vehicle *vehicle;
    Maintenance *M;

    Car c;
    vehicle = &c;
    cout << "Car"<<endl;
    c.SetBrand("BMW");
    c.SetModel("M5");
    c.SetSpeed(250);
    cout << "Brand: " << c.GetBrand() << ", Model: " << c.GetModel() << ", Speed: " << c.GetSpeed() << " km/h" << endl;
    vehicle->startEngine();
    vehicle->stopEngine();
    M = &c;
    M->service();
    M->checkOil();

    Bike b;
    vehicle = &b;
    cout << "Bike"<<endl;
    b.SetBrand("Royal Enfield");
    b.SetModel("Classic 350");
    b.SetSpeed(180);
    cout << "Brand: " << b.GetBrand() << ", Model: " << b.GetModel() << ", Speed: " << b.GetSpeed() << " km/h" << endl;
    vehicle->startEngine();
    vehicle->stopEngine();
    M = &b;
    M->service();
    M->checkOil();

    return 0;
}