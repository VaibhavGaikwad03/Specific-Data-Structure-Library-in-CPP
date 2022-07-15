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

class DoublyCLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int Count;

    public:
        DoublyCLL();
        int CountNode();
        void Display();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

};

DoublyCLL::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

int DoublyCLL::CountNode()
{
    return Count;
}

void DoublyCLL::Display()
{
    PNODE temp = Head;

    cout<<"Data from the Linked List is : "<<endl;
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp != Head);

    cout<<endl;

}

void DoublyCLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

void DoublyCLL::InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

void DoublyCLL::InsertAtPos(int iNo, int iPos)
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
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        Count++;
    }
}

void DoublyCLL::DeleteFirst()
{
    if(Count == 0)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}   

void DoublyCLL::DeleteLast()
{
    if(Count == 0)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

void DoublyCLL::DeleteAtPos(int iPos)
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