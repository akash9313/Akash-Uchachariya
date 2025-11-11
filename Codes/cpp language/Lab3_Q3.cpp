#include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
    double length;
    double breadth;
    void shape(double l,double b){
        length = l;
        breadth = b;
    }
    
};

class Tringle:public Shape{
    public:
    
    void DisplayAreaofTriangle(){
        double area = 0.5*length*breadth; 
        cout<<"Area of Tringle : "<<area<<endl;

    }

};

class Rectangle:public Shape{
    public:
    
    void DisplayAreaofRectangle(){
        double area2 = length*breadth;
        cout<<"Area of Rectangle : "<<area2<<endl;

    }

};

int main()
{
    Tringle T;
    Rectangle R;
    T.shape(3,4);
    T.DisplayAreaofTriangle();
    R.DisplayAreaofRectangle();

    return 0;
}