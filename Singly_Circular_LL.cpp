#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCLL
{
    private:
        PNODE Head;
        PNODE Tail;
        int Count;
    
    public:
        SinglyCLL();
        int CountNode();
        void Display();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

};

SinglyCLL::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

int  SinglyCLL::CountNode()
{
    return Count;
}
void SinglyCLL::Display()
{   
    PNODE temp = Head;
    cout<<"Data from Linked List is : "<<endl;
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while (temp != Head);

    cout<<"NULL"<<endl;
}
void SinglyCLL::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if((Head == NULL) || (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;

    Count++;
}
void SinglyCLL::InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if((Head == NULL) || (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;

    Count++;
}
void SinglyCLL::InsertAtPos(int iNo, int iPos)
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

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}
void SinglyCLL::DeleteFirst()
{
    if((Head == NULL) || (Tail == NULL))
    {
        cout<<"Linked List is empty"<<endl;\
        return;
    }

    if(Head->next == Tail)
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
    Tail->next = Head;

    Count--;
}
void SinglyCLL::DeleteLast()
{
    if((Head == NULL) || (Tail == NULL))
    {
        cout<<"Linked List is empty"<<endl;\
        return;
    }

    if(Head->next == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE temp = Head;

        while (temp->next->next != Head)
        {
            temp = temp->next;
        }
        delete temp->next;
        Tail = temp;
    }
    Tail->next = Head;

    Count--;
}
void SinglyCLL::DeleteAtPos(int iPos)
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
        PNODE tempdelete = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }   
}