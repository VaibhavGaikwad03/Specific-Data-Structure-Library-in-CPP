#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLLL
{
    private:
        PNODE Head;
        int Count;

    public:
        SinglyLLL();
        int CountNode();
        void Display();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

SinglyLLL::SinglyLLL()
{
    Head = NULL;
    Count = 0;
}

int  SinglyLLL::CountNode()
{
    return Count;
}
void SinglyLLL::Display()
{   
    PNODE temp = Head;
    cout<<"Data from Linked List is : "<<endl;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void SinglyLLL::InsertFirst(int iNo)
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
void SinglyLLL::InsertLast(int iNo)
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
void SinglyLLL::InsertAtPos(int iNo, int iPos)
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
        newn = new NODE;
        
        newn->data = iNo;
        newn->next = NULL;

        PNODE temp = Head;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }
}
void SinglyLLL::DeleteFirst()
{
    if(Head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    PNODE temp = Head;

    Head = Head->next;
    delete temp;

    Count--;
}
void SinglyLLL::DeleteLast()
{
    if(Head == NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    PNODE temp = Head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
    Count--;
}
void SinglyLLL::DeleteAtPos(int iPos)
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
        PNODE tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }
}