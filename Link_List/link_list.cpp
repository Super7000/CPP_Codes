#include <iostream>
using namespace std;
class node
{
    public: 
        int val;
        node *next;
};
node *head = NULL;
void int_at_st(int data)
{
    node *node_name = new node();
    node_name->val = data;
    node_name->next = head;
    head = node_name;
}
void int_at_end(int data)
{
    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node *node_name = new node();
    node_name->val = data;
    node_name->next = NULL;
    temp->next = node_name;
}
void int_at_any(int data)
{
    node *temp = head;
    cout << "Enter value of that node after which you want to insert: ";
    int value;
    cin >> value;
    while(temp->val != value)
    {
        temp = temp->next;
    }
    node *node_name = new node();
    node_name->val = data;
    node_name->next = temp->next;
    temp->next = node_name;
}
void display()
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout << "data: " << temp->val << ", self loc: " << temp << " || next loc: " << temp->next << "\n\n";
        temp = temp->next;
    }
    cout << "\n";
}
void del_end()
{
    node *temp = head;
    node *prev_end;
    while(temp->next!=NULL)
    {
        prev_end = temp;
        temp = temp->next;
    }
    prev_end->next = NULL;
}
void del_st()
{
    if (head!=NULL)
    {
        node *next = head->next;
        head->next = NULL;
        head = next;
    } else {
        cout << "Unable to delete";
    }
}
int main()
{
    while (1)
    {
        int cho_val, para_val, br=0;
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert at middle\n4. Display\n5. Deletion From End\n6. Deletion from start\n7. Exit\nEnter Value: ";
        cin >> cho_val;
        switch (cho_val)
        {
            case 1: cout << "Enter value that you want to insert: ";
                    cin >> para_val;
                    int_at_st(para_val);
                    break;
            case 2: cout << "Enter value that you want to insert: ";
                    cin >> para_val;
                    int_at_end(para_val);
                    break;
            case 3: cout << "Enter value that you want to insert: ";
                    cin >> para_val;
                    int_at_any(para_val);
                    break;
            case 4: display();
                    break;
            case 5: del_end();
                    break;
            case 6: del_st();
                    break;
            case 7: br=1;
                    break;
            default: cout << "wrong choise";
        }
        if(br==1) break;
    }
    return 0;
}