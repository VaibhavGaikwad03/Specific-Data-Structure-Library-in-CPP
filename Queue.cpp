#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Queue
{   
    private:
        PNODE Head;
        int Count;
    
    public:
        Queue();
        int CountNode();
        void Display();
        void Enqueue(int);
        void Dequeue();
};

Queue::Queue()
{
    Head = NULL;
    Count = 0;
}

int Queue::CountNode()
{
    return Count;
}

void Queue::Display()
{
    PNODE temp = Head;

    cout<<"Data from the Queue is : "<<endl;
    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void Queue::Enqueue(int iNo)
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
        PNODE temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

void Queue::Dequeue()
{
    if(Head == NULL)
    {
        cout<<"Queue is empty"<<endl;
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