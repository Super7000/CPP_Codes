#include <iostream>
using namespace std;
class dbll
{
    public:
        dbll *prev;
        int val;
        dbll *next;
};
dbll *head =NULL;
void int_end(int data)
{
    dbll *node = new dbll();
    node->val = data;
    node->prev = head;
    head = node;
    node->next = NULL;
    if(node->prev!=NULL)
    {
        node->prev->next = node;
    }
}
void int_st(int data)
{
    dbll *node = new dbll();
    dbll *temp = head;
    node->prev = NULL;
    node->val= data;
    while (temp->prev!=NULL)
    {
        temp = temp->prev;
    }
    node->next = temp;
    temp->prev = node;
}
void display()
{
    dbll *temp = head;
    while(temp!=NULL)
    {
        cout << "prev loc: " << temp->prev << " || data: " << temp->val << " , self loc: " << temp << " || next loc: " << temp->next << "\n\n";
        temp = temp->prev;
    }
    cout << "\n";
}
void rev_display()
{
    dbll *temp = head;
    while(temp->prev!=NULL)
    {
        temp = temp->prev;
    }
    while (temp!=NULL)
    {        
        cout << "prev loc: " << temp->prev << " || data: " << temp->val << " , self loc: " << temp << " || next loc: " << temp->next << "\n\n";
        temp = temp->next;
    }
    cout << "\n";
}
void del_end()
{
    if(head!=NULL)
    {
        head = head->prev;
        head->next = NULL;
    } else {
        cout << "unable to delete\n";
    }
}
void del_st()
{
    dbll *temp = head;
    while(temp->prev!=NULL)
    {
        temp = temp->prev;
    }
    temp->next->prev = NULL;
}
int main()
{
    int_end(6);
    int_end(5);
    int_end(4);
    int_end(2);
    rev_display();
    del_end();
    del_st();
    int_st(7);
    display();
    rev_display();
    return 0;
}