#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    double radius;
    double side;

public:
    Shape(){
        radius = 0.0;
        side = 0.0;
    }

    void setRadius(double r) { 
        radius = r; 
    }
    double getRadius() const { 
        return radius; 
    }

    void setSide(double s) { 
        side = s; 
    }
    double getSide() const { 
        return side; 
    }

    virtual double area() const = 0;

    void show() const
    {
        cout << "Area = " << area() << endl;
    }
};

class Circle : public Shape
{
public:
    void setDimension(double r)
    {
        setRadius(r);
    }

    double area() const override
    {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape
{
public:
    void setDimension(double s)
    {
        setSide(s);
    }

    double area() const override
    {
        return side * side;
    }
};

int main()
{
    Shape *shapePtr;

    Circle c;
    c.setDimension(5.0);
    shapePtr = &c;
    cout << "Circle ";
    shapePtr->show();

    Square s;
    s.setDimension(4.0);
    shapePtr = &s;
    cout << "Square ";
    shapePtr->show();

    return 0;
}
