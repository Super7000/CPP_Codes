#include <iostream>
using namespace std;
int arr[10];
int front = -1;
int rear = -1;
void enqueue(int val)
{
    if (front == rear + 1 || (rear == 9 && front == 0))
    {
        cout << "Overflow\n";
        return;
    }
    else if (front == -1 && rear == -1) front = rear = 0;
    else rear = (rear +1)%10;
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
    if (front == rear) front = rear = -1;
    else front = (front +1) %10;
}
void display()
{
    int i;
    if(front == -1 && rear == -1)
    {
        cout << "empty\n";
        return;
    }
    for (i = front; i != rear; i=(i+1)%10) {
        cout << arr[i] << ",";
    }
    cout << arr[i] << "\n";
}
int main()
{
    while(1)
    {
        int optval;
        cout << "1. enq\n2. deq\n3. exit\n4. dis\n5. full que\n";
        cout << "Enter value: ";
        cin >> optval;
        switch(optval)
        {
            case 1: int val;
                    cout << "Enter elem: ";
                    cin >> val;
                    enqueue(val);
                    cout << front << "," << rear << "\n";
                    break;
            case 2: dequeue();
                    cout << front << "," << rear << "\n";
                    break;
            case 3: return 0;
            case 4: display();
                    cout << front << "," << rear << "\n";
                    break;
            case 5: for (int i = 0; i < 10; i++)
                    {
                        enqueue(i+1);
                    }    
                    cout << front << "," << rear << "\n";
                    break;
            default: cout << "worng value";
                    break;
        }
    }
    return 0;
}