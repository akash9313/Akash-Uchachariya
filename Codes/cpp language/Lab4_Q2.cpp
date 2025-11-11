#include <iostream>
using namespace std;

class Account
{
protected:
    int x;
    int y;

public:
    void setAccount()
    {
        cout << "Enter your account number: ";
        cin >> x;
        cout << "Enter your bank balance: ";
        cin >> y;
    }
    void displayAccount()
    {
        cout << "ACCOUNT NUMBER: " << x << "\nBANK BALANCE: " << y << endl;
    }
};

class SavingAccount : virtual public Account
{
protected:
    float a;

public:
    void setSaving()
    {
        cout << "Enter your interest rate: ";
        cin >> a;
    }
    void displaySaving()
    {
        cout << "INTEREST RATE: " << a << endl;
    }
};

class CurrentAccount : virtual public Account
{
protected:
    int b;

public:
    void setCurrent()
    {
        cout << "Enter your overdraft limit: ";
        cin >> b;
    }
    void displayCurrent()
    {
        cout << "OVERDRAFT LIMIT: " << b << endl;
    }
};

class PremiumAccount : public SavingAccount, public CurrentAccount
{
private:
    int c;

public:
    void setPremium()
    {
        cout << "Enter your reward points: ";
        cin >> c;
    }
    void displayPremium()
    {
        cout << "REWARD POINTS: " << c << endl;
    }
};

int main()
{
    PremiumAccount pa;

    pa.setAccount();
    pa.setSaving();
    pa.setCurrent();
    pa.setPremium();

    cout << "\n--- Account Details ---\n";
    pa.displayAccount();
    pa.displaySaving();
    pa.displayCurrent();
    pa.displayPremium();

    return 0;
}