#include <iostream>
using namespace std;

class Parcel
{
protected:
    double weight;
    double shipping_cost;

public:
    Parcel(double w, double sc)
    {
        weight = w;
        shipping_cost = sc;
    }

    virtual void Cal_shipping()
    {
    }
};

class Box : public Parcel
{
private:
    int no_of_boxes;

public:
    Box(double weight, double shipping_cost)
        : Parcel(weight, shipping_cost)
    {
        no_of_boxes = 0;
    }

    void Cal_shipping() override
    {
        if (30 < weight && weight < 50)
        {
            shipping_cost = shipping_cost + weight * 10;
            no_of_boxes = 2;
        }
        else if (weight > 50)
        {
            shipping_cost = shipping_cost + 30 + weight * 10;
            no_of_boxes = 5;
        }
        else
        {
            shipping_cost = shipping_cost + weight * 10;
            no_of_boxes = 1;
        }

        cout << "Total shipping cost: " << shipping_cost << " || Number of boxes: " << no_of_boxes << endl;
    }
};

int main()
{
    Box b(40, 50);
    b.Cal_shipping();

    return 0;
}
