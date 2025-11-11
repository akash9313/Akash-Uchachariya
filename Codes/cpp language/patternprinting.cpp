#include <iostream>
using namespace std;

class patternprint{
    int n;
    public:

    patternprint(){
        cout<<"Enter the number of rows : ";
        cin>>n;
    }

    void printtriangle(){
        cout<<"Triangle pattern : "<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i ; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }

    void printpyramid(){

        cout<<"Pyramid pattern : "<<endl;
        for (int i = 1; i <= n; i++)
        {
            for (int k = 1; k <= n - i; k++)
            {
                cout<<" ";
            }
            
            for (int j = 1; j <= 2*i - 1; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }
};

int main()
{
    patternprint p;

    p.printtriangle();
    p.printpyramid();

    return 0;
}