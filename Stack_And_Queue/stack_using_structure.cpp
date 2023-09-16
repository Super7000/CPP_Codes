#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack
{
    int top;
    char c[100];
};
struct stack *loc = (struct stack *) malloc(sizeof(struct stack));
void push(char val)
{
    if(loc->top == 99) cout << "Overflow";
    else
    {
        loc->top++;
        loc->c[loc->top]=val;
    }
}
int pop()
{
    char val;
    if(loc->top==-1) cout << "underflow";
    else
    {
        val = loc->c[loc->top];
        loc->top--;
    }
    return val;
}
void display()
{
    for(int i = 0; i <= loc->top; i++) cout << loc->c[i];
    cout << "\n";
}
int main()
{
    loc->top = -1;
    int ch;
    char val;
    int exit_val=0;
    while(1)
    {   
        cout << "1. push\n2. pop\n3. display\n4. exit\n" << "Enter value: ";
        cin >> ch;
        switch(ch)
        {
            case 1: cout << "Enter Value: ";
                    cin >> val;
                    push(val);
                    break;
            case 2: printf("%c deleted from stack\n",pop());
                    break;
            case 3: display();
                    break;
            case 4: exit_val = 1;
                    break;
            default: cout << "Please enter a valid value";
        }
        if(exit_val!=0) break;
    }
    return 0;
}