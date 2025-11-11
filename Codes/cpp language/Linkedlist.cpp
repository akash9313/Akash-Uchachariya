#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *Head;
    Head = NULL;
    int n;
    cout << "How many values you want to enter : ";
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (Head == NULL)
        {
            int val1;
            cin >> val1;
            Head = new Node(val1);
        }
        else
        {
            Node *temp;
            int val2;
            cin >> val2;
            temp = new Node(val2);
            temp->next = Head;
            Head = temp;
        }
        count++;
    }
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}