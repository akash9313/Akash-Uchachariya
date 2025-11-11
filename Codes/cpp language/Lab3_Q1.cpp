#include <bits/stdc++.h>
using namespace std;

class Circle{
    public:
    float rad;
    void AreaofCircle(float radius){
        float area = 3.14*radius*radius;
        cout<<"Area of Circle : "<<area<<endl;

        rad = radius;
    }

};

class Rectangle:public Circle{
    public:
    
    void AreaofRectangle(float breadth){
        float length = 2.0*rad;
        float area2 = length*breadth;
        cout<<"Area of Rectangle : "<<area2<<endl;

    }

};

int main()
{
    Rectangle R;
    R.AreaofCircle(4.0);
    R.AreaofRectangle(4.0);

    return 0;
}