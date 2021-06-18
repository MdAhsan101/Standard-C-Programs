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

void SinglyLinkedList::Insert_Node_ToHead(Node* p)
{
    if(head==NULL)
    {
        head= p;
        return;
    }

    p->next= head;
    head= p;
}

void SinglyLinkedList::Insert_After_Node(Node* p, int key)
{
    Node* temp= head;
    while((temp->data != key) && (temp!=NULL))
    {
        temp= temp->next;
    }   
    if(temp==NULL)
        cout<<"No such node value is found. Enter correct key again."<<endl; 
    else
    {
        Node* t= temp->next;
        temp->next= p;
        p->next= t;
    }
}

void SinglyLinkedList::Delete(int key)
{
    if(head==NULL)
        return ;
    Node* tail= head;
    if(head->data==key)
    {
        Node* t= head;
        head=t->next;
        delete t;
        return;
    }
    Node* curr= head->next;
    while((curr!=NULL) && (curr->data != key))
    {
        tail= curr;
        curr= curr->next;        
        cout<<curr->data<<endl;
    }
    
    if(curr == NULL)
    {
        cout<<"Node with such key value is not found in SLL.\n";
        return ;           
    }

    Node* t= curr;
    tail->next = t->next;
    delete t; 
    
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

    // cout<<"Want to enter node to head of SLL (y/n) :  ";
    // cin>>c;
    // while(c=='y' || c=='Y')
    // {
    //     cout<<"Enter node value : ";
    //     cin>>key;
    //     Node* node= new Node(key);
    //     SLL.Insert_Node_ToHead(node); 
        
    //     cout<<"Want to enter node to head of SLL again (y/n) :  ";
    //     cin>>c;       
    // }
    // Display(SLL.head); // 3 -> 2 -> 1 ->

    /*
    int val;
    cout<<"\nEnter key to insert node after that in SLL: ";
    cin>>key;
    cout<<"Now enter value for the node: ";
    cin>>val;
    Node node(val);
    SLL.Insert_After_Node(&node,key);
    Display(SLL.head);
    */
    /*
    Output:
    1 -> 2 -> 3 -> 
    Enter key to insert node after that in SLL: 2
    Now enter value for the node: 4
    1 -> 2 -> 4 -> 3 ->
    */

   cout<<"\nEnter node value to delete: ";
   cin>>key;
   SLL.Delete(key);
   Display(SLL.head);
   /*
   1 -> 2 -> 3 -> 4 -> 
   Enter node value to delete: 2
   1 -> 3 -> 4 ->
   */

}