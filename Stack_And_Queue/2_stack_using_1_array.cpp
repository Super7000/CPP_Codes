#include <iostream>
using namespace std;
int top[2] = {-1,-1};
int arr[50];
void push(int val)
{
    int elem;
    cout << "Enter Element: ";
    cin >> elem;
    int index = val-1;
    if (top[index] == 24)
    {
        cout << "Overflow\n";
    }
    else
    {
        top[index] = top[index]+1;
        if(val == 2)
        {
            arr[24+top[index]] = elem;
        }
        else
        {
            arr[top[index]] = elem;
        }
        cout << "element inserted\n";
    }
}
int pop(int val)
{
    int elem;
    int index = val-1;
    if (top[index] == -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        val == 2 ? elem =  arr[24+top[index]] : elem = arr[top[index]];
        top[index] = top[index]-1;
    }
    return elem;
}
void display(int val)
{
    int index = val-1;
    if(top[index] >= 0)
    {
        for(int i = 0; i <= top[index]; i++)
        {
            cout << arr[i] << ",";
        }
        cout << "\n";
    }
    else 
    {
        cout << "stack is empty\n";
    }
}
void full_arr_view()
{
    for(int i = 0; i < 50; i++) cout << arr[i] << ",";
    cout << "\b\n";
}
int main()
{
    int val, opt_val,br=0;
    while(1)
    {
        cout << "1. first stack \n2. second stack \nEnter value(1/2): ";
        cin  >> val;
        if (val != 1 && val != 2) 
        {
            cout << "enter a valid value\n";
            main();
        }
        cout << "1. push()\n2. pop()\n3. display()\n4. exit()\n5. full array view()\nEnter value(1/2/3/4/5): ";
        cin >> opt_val;
        switch(opt_val)
        {
            case 1: push(val);
                    break;
            case 2: cout << pop(val) << " poped\n";
                    break;
            case 3: display(val);
                    break;
            case 4: br = 1;
                    break;
            case 5: full_arr_view();
                    break;
            default: cout << "worng value";
        }
        if(br==1) break;
    }
    return 0;
}