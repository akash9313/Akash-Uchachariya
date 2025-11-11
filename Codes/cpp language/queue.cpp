#include<iostream>
using namespace std;

class queue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int value)
    {
        arr[rear] = value;
        rear++;
    }

    void pop()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    void Front()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Front element is : "<<arr[front]<<endl;
        }
    }

    void isEmpty()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }
};

int main()
{
    queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.Front();
    q.isEmpty();

    return 0;
}