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
        void EvenPosAfterOdd();
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

void SinglyLinkedList::EvenPosAfterOdd()
{
    Node* odd_ptr= head;
    Node* even_head= head->next;
    Node* even_ptr= even_head;

    while(odd_ptr->next!=NULL && even_ptr->next!=NULL)
    {
        odd_ptr->next= even_ptr->next;
        odd_ptr= odd_ptr->next;

        even_ptr->next= odd_ptr->next;
        even_ptr= even_ptr->next;
    }

    if(odd_ptr->next==NULL)
    {
        even_ptr->next=NULL;
    }
    odd_ptr->next= even_head;
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
    
    SinglyLinkedList SLL1 ;

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
    
    SLL1.EvenPosAfterOdd();
    Display(SLL1.head);

}

/*
Output:
1 -> 2 -> 3 -> 4 -> 
1 -> 3 -> 2 -> 4 -> 
*/


