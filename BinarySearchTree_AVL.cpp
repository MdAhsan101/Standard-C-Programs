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
    int hl= Height(p->lchild);
    int hr= Height(p->rchild);

    return hl>hr? (hl+1):(hr+1);
}

int BalanceFactor(struct Node* p)
{
    int hl= (p && p->lchild) ? Height(p->lchild) : 0;
    int hr= (p && p->rchild) ? Height(p->rchild) : 0;
    return hl-hr; 
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

struct Node* LL_Rotation(struct Node* p)
{
    struct Node* pl= p->lchild;
    struct Node* plr= pl->rchild;

    pl->rchild=p;
    p->lchild=plr;        
    
    if(root==p)
        root=pl;
    return pl;
}

struct Node* RR_Rotation(struct Node* p)
{
    struct Node* pr= p->rchild;
    struct Node* prl= pr->lchild;

    pr->lchild=p;
    p->rchild=prl;
    
    if(root==p)
        root=pr;
    return pr;
}

struct Node* LR_Rotation(struct Node* p)
{
    struct Node* pl= p->lchild;
    struct Node* plr= pl->rchild;

    p->lchild= plr->rchild;
    pl->rchild= plr->lchild;
    plr->lchild=pl;
    plr->rchild=p;

    if(root==p)
        root=plr;
    return plr;
}

struct Node* RL_Rotation(struct Node* p)
{
    struct Node* pr= p->rchild;
    struct Node* prl= pr->lchild;

    p->rchild= prl->lchild;
    pr->lchild= prl->rchild;
    prl->rchild=pr;
    prl->lchild=p;

    if(root==p)
        root=prl;
    return prl;
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

    if(key<p->data)
        p->lchild= RInsert(p->lchild,key);
    if(key>p->data)
        p->rchild= RInsert(p->rchild,key);
    
       
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LL_Rotation(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LR_Rotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RR_Rotation(p);
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RL_Rotation(p);
       
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

    cout<<"Root node is "<<root->data<<endl;
    int tree_height=Height(root);
    cout<<"Height of AVL tree is "<< tree_height-1<<endl;
}

/*
Output:

Enter the value for root node: 10

Enter the node value:
20
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
30
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
25
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
28
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
27
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
5
Press any integer key to enter again: (Press -1 to exit) 
-1

Preorder Seq: 25 10 5 20 28 27 30
Inorder Seq: 5 10 20 25 27 28 30
Postorder Seq: 5 20 10 27 30 28 25
Root node is 25
Height of AVL tree is 2
*/