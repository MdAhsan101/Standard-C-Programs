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

Node* Reverse_K_Nodes(Node* p, int k)
{
    Node* prevptr= NULL;
    Node* currptr= p;
    Node* nextptr;
    
    int count=1;
    while((count<=k) && (currptr!=NULL))
    {
        nextptr= currptr->next;
        currptr->next= prevptr;
        prevptr= currptr;
        currptr= nextptr;
        count++; 
    }
    

    if(currptr!=NULL)
        p->next= Reverse_K_Nodes(nextptr,k);
    return prevptr;

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

    Node* newhead= Reverse_K_Nodes(SLL.head,3);
    Display(newhead);
}

/*
Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 
3 -> 2 -> 1 -> 6 -> 5 -> 4 ->
*/
