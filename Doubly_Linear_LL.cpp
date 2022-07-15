#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLLL
{
    private:
        PNODE Head;
        int Count;
    
    public:
        DoublyLLL();
        int CountNode();
        void Display();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

};

DoublyLLL::DoublyLLL()
{
    Head = NULL;
    Count = 0;
}

int DoublyLLL::CountNode()
{
    return Count;
}

void DoublyLLL::Display()
{
    PNODE temp = Head;

    cout<<"Data from the Linked List is : "<<endl;
    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void DoublyLLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}
void DoublyLLL::InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
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
        newn->prev = temp;
    }
    Count++;
}
void DoublyLLL::InsertAtPos(int iNo, int iPos)
{
    int size = CountNode();

    if((iPos < 1) || (iPos > size+1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == size+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = Head;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        Count++;
    }
}
void DoublyLLL::DeleteFirst()
{
    if(Count == 0)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
    Count--;
}
void DoublyLLL::DeleteLast()
{
    if(Count == 0)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    
    if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp = Head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}
void DoublyLLL::DeleteAtPos(int iPos)
{
    int size = CountNode();

    if((iPos < 1) || (iPos > size))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == size)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = Head;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}