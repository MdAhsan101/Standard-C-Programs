#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Implementing constructor
        Node(int data) // Parameterized Constructor
        {
            this->data = data;
            next=  NULL;                    
        }
};

class SinglyLinkedList
{
    public:
        Node* head= NULL;

        void Insert_Node_ToTail(Node* p);
        int Length(Node* p);
        void Append_K_Nodes(int k);
        void Delete(int key);
        void Display();

};

int SinglyLinkedList::Length(Node* p)
{
    int l=1;
    while(p->next!=NULL)
    {
        p= p->next;
        l++;
    }
    return l;
}

void SinglyLinkedList::Insert_Node_ToTail(Node* p)
{
    
    if(head==NULL)
    {
        head=p;
        return;
    }
    
    Node* temp= head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next= p;    
}

void SinglyLinkedList::Append_K_Nodes(int k)
{
    Node* p= head;
    Node* newtail;
    Node* newhead;

    int l= Length(head);
    int pos= l-k;
    int count=1;

    while(p->next!=NULL)
    {
        if(count==pos)
        { newtail=p;}
        
        if(count==pos+1)
        { newhead=p; }

        p= p->next;
        count++;
    }

    p->next= head;
    newtail->next= NULL;
    head= newhead;
}

void Display(Node* p)
{
    if(p==NULL)
        return;
    cout<<p->data<<" -> ";
    Display(p->next);
}

int main()
{
    char c='y';
    int key;
    
    SinglyLinkedList SLL;

    cout<<"Want to enter node to tail of SLL (y/n) :  ";
    cin>>c;
    while(c=='y' || c=='Y')
    {
        cout<<"Enter node value : ";
        cin>>key;
        Node* node= new Node(key);
        SLL.Insert_Node_ToTail(node); 
        
        cout<<"Want to enter node to tail of SLL again (y/n) :  ";
        cin>>c;       
    }
    Display(SLL.head); // 1 -> 2 -> 3 ->
    
    cout<<endl;

    SLL.Append_K_Nodes(2);
    Display(SLL.head);
}

/*
Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 
5 -> 6 -> 1 -> 2 -> 3 -> 4 ->
*/


