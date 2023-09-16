#include <iostream>
using namespace std;
int arr[10];
int front = -1;
int rear = -1;
void enqueue(int val)
{
    if(rear == 9) 
    {
        cout << "Overflow\n";
        return;
    }
    else if(rear == -1 && front == -1)
    {
        front = rear = 0;
    }
    else rear++;
    arr[rear] = val;
}
void dequeue()
{
    if(front == -1) 
    {
        cout << "Underflow\n";
        return;
    }
    cout << arr[front] << " removed\n";
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(rear-front>=1)
    {   
        for(int i = front; i <= rear; i++) cout << arr[i] << ",";
        cout << "\n";
    } else cout << "Empty\n";
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}