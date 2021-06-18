#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class SinglyLinkedList
{
    public:
        Node* head= NULL;

        void Insert_Node_ToTail(Node* p);
        int Detect_Cycle(Node* p);
        void Make_Cycle(Node* p,int pos);
        void Remove_Cycle(Node* p);
        void Display();
};

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

void SinglyLinkedList::Make_Cycle(Node* p,int pos)
{
    Node* crossnode;
    int count=1;
    while(p->next!=NULL)
    {
        if(count==pos)
            crossnode=p;
        p= p->next;
        count++;
    }
    p->next= crossnode;
}

void SinglyLinkedList::Remove_Cycle(Node* p)
{
    Node* slowptr= p;
    Node* fastptr= p;

    do
    {
        slowptr= slowptr->next;
        fastptr= fastptr->next->next;
    } while (slowptr!=fastptr);
    
    fastptr= head;
    while(fastptr->next != slowptr->next)
    {
        fastptr= fastptr->next;
        slowptr= slowptr->next;
    }    

    slowptr->next=NULL;
}

int SinglyLinkedList::Detect_Cycle(Node* p)
{
    Node* slowptr= p;
    Node* fastptr= p;

    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        slowptr= slowptr->next;
        fastptr= fastptr->next->next;
        if(fastptr==slowptr)
            return 1;
    }
    return 0;    
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
        Node* node= new Node;
        node->data=key; node->next=NULL;
        SLL.Insert_Node_ToTail(node); 
        
        cout<<"Want to enter node to tail of SLL again (y/n) :  ";
        cin>>c;       
    }
    Display(SLL.head); // 1 -> 2 -> 3 ->
    
    cout<<endl;

    SLL.Make_Cycle(SLL.head,3);
    //int ans= SLL.Detect_Cycle(SLL.head);
    //cout<<"Cycle Present="<<ans;
    /*
    Output:
    1 -> 2 -> 3 -> 4 -> 5 -> 
    Cycle Present=1
    */
    
    SLL.Remove_Cycle(SLL.head);
    //Display(SLL.head);    
    int ans= SLL.Detect_Cycle(SLL.head);
    cout<<"x"<<endl;
    cout<<"\nCycle Present="<<ans;
    /*
    Output:
    1 -> 2 -> 3 -> 4 -> 5 -> 
    Cycle Present=0
    */
    
}