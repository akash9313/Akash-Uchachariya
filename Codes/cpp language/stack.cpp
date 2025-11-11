#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n, num;
    cout << "How many numbers you want to enter : ";
    cin >> n;
    cout << "Enter the numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.push(num);
    }
    cout << "size is : " << s.size() << endl;
    cout << "Last number is : " << s.top()<<endl;

    s.pop();

    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "size is : " << s.size() << endl;
}