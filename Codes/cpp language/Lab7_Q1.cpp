#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = (d == 0) ? 1 : d;
    }

    friend Fraction operator+(Fraction a, Fraction b) {
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator-(Fraction a, Fraction b) {
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator*(Fraction a, Fraction b) {
        return Fraction(a.numerator * b.numerator,
                        a.denominator * b.denominator);
    }

    Fraction operator/(Fraction b) {
        return Fraction(numerator * b.denominator,
                        denominator * b.numerator);
    }

    void display() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 4);

    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    f3.display();
    f4.display();
    f5.display();
    f6.display();

    return 0;
}