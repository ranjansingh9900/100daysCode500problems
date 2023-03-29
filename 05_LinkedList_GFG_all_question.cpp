
****// reverse linked list ...

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void push(node *&head, int data)
{
    node *p = new node(data);
    if (head == NULL)
    {
        head = p;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
}



void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// this i
node *reverse(node *&head)
{
    node *prev_ptr = NULL;
    node *current_ptr = head;
    node *next_ptr;
    while (current_ptr != NULL)
    {
        next_ptr = current_ptr->next;
        current_ptr->next = prev_ptr;

        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }
    return prev_ptr;
}

node *reverse_methoed2(node *head)
{
    node *new_node = NULL;
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        temp->next = new_node;
        new_node = temp;
    }
    return new_node;
}

int main()
{
    node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    display(head);

    // node *new_head = reverse(head);
    node *new_head = reverse_methoed2(head);

    display(new_head);

    return 0;
}
