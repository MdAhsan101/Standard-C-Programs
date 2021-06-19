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
        Node* MergeTwoSortedLL(Node* head2);
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

Node* SinglyLinkedList::MergeTwoSortedLL(Node* head)
{
    Node* p1= this->head;
    Node* p2= head;
    Node* d= new Node(-1);

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        { d->next=p1; cout<<p1->data<<endl; p1=p1->next; }
        else
        { d->next= p2; cout<<p2->data<<endl; p2= p2->next;}
    }

    while(p1!=NULL)
    {
        d->next= p1;
        cout<<p1->data<<endl;
        p1= p1->next;
    }

    while(p2!=NULL)
    {
        d->next=p2; 
        cout<<p2->data<<endl;
        p2= p2->next;
    }

    return d;
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
    
    SinglyLinkedList SLL1 , SLL2;

    cout<<"Enter nodes for SLL1 in sorted order: "<<endl;
    cout<<"Want to enter node to tail of SLL (y/n) :  ";
    cin>>c;
    while(c=='y' || c=='Y')
    {
        cout<<"Enter node value : ";
        cin>>key;
        Node* node= new Node(key);
        SLL1.Insert_Node_ToTail(node); 
        
        cout<<"Want to enter node to tail of SLL again (y/n) :  ";
        cin>>c;       
    }
    Display(SLL1.head); // 1 -> 2 -> 3 ->
    
    cout<<endl;
    cout<<"Enter nodes for second LL in sorted order : "<<endl;
    cout<<"Want to enter node to tail of SLL (y/n) :  ";
    cin>>c;
    while(c=='y' || c=='Y')
    {
        cout<<"Enter node value : ";
        cin>>key;
        Node* node= new Node(key);
        SLL2.Insert_Node_ToTail(node); 
        
        cout<<"Want to enter node to tail of SLL again (y/n) :  ";
        cin>>c;       
    }
    Display(SLL2.head);cout<<endl;

    Node* head3=SLL1.MergeTwoSortedLL(SLL2.head);
    Display(head3);
        
}