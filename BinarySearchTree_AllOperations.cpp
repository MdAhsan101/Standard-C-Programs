#include<iostream>
using namespace std;

struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}*root=NULL;


int Height(struct Node* p)
{
    if(p==NULL)
        return 0;
    int x= Height(p->lchild);
    int y= Height(p->rchild);
    return x>y ? (x+1):(y+1);
}

struct Node* InorderPredecessor(struct Node* p)
{
    if(p && p->rchild)
    {
        p=p->rchild;
    }
    return p;
}

struct Node* InorderSuccessor(struct Node* p)
{
    if(p && p->lchild)
    {
        p=p->lchild;
    }
    return p;
}

struct Node* RInsert(struct Node* p, int key)
{
    if(p==NULL)
    {
        struct Node* t= new Node;
        t->data=key;
        t->rchild=t->lchild=NULL;
        return t;
    }

    if(key==p->data)
        return p;
    if(key<p->data)
        p->lchild= RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild= RInsert(p->rchild,key);
    
    return p;
}

void PreOrder(struct Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(struct Node* p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout<<p->data<<" ";
        InOrder(p->rchild);
    }
}

void PostOrder(struct Node* p)
{
    if(p)
    {        
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

struct Node* Delete(struct Node* p, int key)
{
    if(p==NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(root==p)
        {
            root=NULL;
            return NULL;
        }
        delete p;
        return NULL;
    }

    if(key<p->data)
        p->lchild= Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild= Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            struct Node* q= InorderPredecessor(p->lchild);
            p->data=q->data;
            p->lchild= Delete(p->lchild,q->data);
        }
        else
        {
            struct Node* q= InorderSuccessor(p->rchild);
            p->data=q->data;
            p->rchild= Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    int i=1;
    int key;
    cout<<"Enter the value for root node: ";
    cin>>key;
    root= RInsert(root,key);
    cout<<endl;
    while(i!=-1)
    {
        cout<<"Enter the node value: "<<endl;
        cin>>key;
        RInsert(root,key);
        cout<<"Press any integer key to enter again: (Press -1 to exit) "<<endl;
        cin>>i;        
    }

    cout<<"Preorder Seq: ";
    PreOrder(root);
    cout<<endl;

    cout<<"Inorder Seq: ";
    InOrder(root);
    cout<<endl;

    cout<<"Postorder Seq: ";
    PostOrder(root);
    cout<<endl;

    cout<<"Height of BST is "<<Height(root)<<endl;

    cout<<"Enter value to delete a node: ";
    cin>>key;
    Delete(root,key);

    cout<<"Inorder Seq: ";
    InOrder(root);
    cout<<endl;
}

/*
Output:

nter the value for root node: 10

Enter the node value:
5
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
20
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
4
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
8
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
15
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
25
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
3
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
18
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
16
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
19
Press any integer key to enter again: (Press -1 to exit) 
-1

Preorder Seq: 10 5 4 3 8 20 15 18 16 19 25 
Inorder Seq: 3 4 5 8 10 15 16 18 19 20 25
Postorder Seq: 3 4 8 5 16 19 18 15 25 20 10

Height of BST is 5

Enter value to delete a node: 15
Inorder Seq: 3 4 5 8 10 16 18 19 20 25

*/