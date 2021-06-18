#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Implementing constructor
        Node()
        {
            this->data = 0;
            next=  NULL;                    
        }
        Node(int data)
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
        void Insert_Node_ToHead(Node* p);
        void Insert_After_Node(Node* p,int key);
        void Delete(int key);
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

Node* IReverse(Node* p)
{
    Node* prevptr= NULL;
    Node* currptr= p;
    Node* nextptr;

    while(currptr != NULL)
    {
        nextptr= currptr->next;
        currptr->next= prevptr;
        prevptr= currptr;
        currptr= nextptr;
    }
    return prevptr;
}

Node* RReverse(Node* &p)
{
    if(p->next==NULL || p==NULL)
        return p;
    
    Node* newhead = RReverse(p->next);
    p->next->next = p;
    p->next= NULL;
    return newhead; 
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

    /*
    Node* newhead= IReverse(SLL.head);
    Display(newhead);
    */
    /*
    Output:
    1 -> 2 -> 3 -> 
    3 -> 2 -> 1 ->
    */

    cout<<endl;
    Node* newhead= RReverse(SLL.head);
    Display(newhead);
    /*
    Output:
    1 -> 2 -> 3 -> 
    3 -> 2 -> 1 ->
    */

}

