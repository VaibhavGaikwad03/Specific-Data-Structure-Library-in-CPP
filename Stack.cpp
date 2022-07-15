#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Stack
{
    private:
        PNODE Head;
        int Count;

    public:
        Stack();
        int CountNode();
        void Display();
        void Push(int);
        void Pop();
};

Stack::Stack()
{
    Head = NULL;
    Count = 0;
}

int Stack::CountNode()
{
    return Count;
}

void Stack::Display()
{
    PNODE temp = Head;

    cout<<"Data from the stack is : "<<endl;
    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

void Stack::Push(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

void Stack::Pop()
{
    if(Head == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp = Head;

        Head = Head->next;
        delete temp;
    }
    Count--;
}