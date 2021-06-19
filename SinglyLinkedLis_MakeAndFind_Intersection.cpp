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
        void MakeLL_Intersection(Node*,Node*,int);
        int Find_IntersectionPos(Node*,Node*);
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

void SinglyLinkedList::MakeLL_Intersection(Node* head1, Node* head2, int pos)
{
    
    Node* ptr1=head1, *ptr2=head2;
    
    while(ptr2->next!=NULL)
        ptr2= ptr2->next;
    
    int count=1;
    while(count<pos)
    {
        ptr1= ptr1->next;
        count++;
    }

    ptr2->next= ptr1;
}

int SinglyLinkedList::Find_IntersectionPos(Node* head1, Node* head2)
{
        int l1= Length(head1);
        int l2= Length(head2);
        Node *ptr1, *ptr2;
        int pos;

        if(l1>l2)
        {
            pos=l1-l2; ptr1= head1; ptr2= head2;
        }
        else
        {
            pos=l2-l1; ptr1=head2; ptr2= head1;
        }

        int count=1;
        while(count<=pos)
        {
            ptr1= ptr1->next;
            count++;
        }

        int x=-1;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->next==ptr2->next)
            {x=count+1; return x;}
            ptr1= ptr1->next;
            ptr2= ptr2->next;
            count++;
        }
        return x;
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
    cout<<"Enter nodes for second LL: "<<endl;
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
    Display(SLL2.head);

    cout<<"\nEnter position where the 2nd LL will be joined on 1st LL: ";
    int p; cin>>p;

    SLL1.MakeLL_Intersection(SLL1.head,SLL2.head,p);
    cout<<"Intersection of LL completed "<<endl;
    p= SLL1.Find_IntersectionPos(SLL1.head,SLL2.head);
    cout<<"SLL1 and SLL2 are intersecting at "<<p<<" pos from SLL1's head."<<endl;    
}

/*
Output:

Want to enter node to tail of SLL (y/n) :  y
Enter node value : 1
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 2
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 3
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 4
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 5
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 6
Want to enter node to tail of SLL again (y/n) :  n
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 

Enter nodes for second LL:
Want to enter node to tail of SLL (y/n) :  y
Enter node value : 10
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 11
Want to enter node to tail of SLL again (y/n) :  y
Enter node value : 12
Want to enter node to tail of SLL again (y/n) :  n
10 -> 11 -> 12 -> 

Enter position where the 2nd LL will be joined on 1st LL: 5
Intersection of LL completed 

SLL1 and SLL2 are intersecting at 5 pos from SLL1's head.

*/


