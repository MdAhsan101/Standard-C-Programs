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

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LL_Rotation(p); // Called L1 Rotation in case of deletion, Code is same as LL_Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LR_Rotation(p); // Called L-1 Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
        return LL_Rotation(p); // LO Rotation -> Can use either L1 or L-1, its our choice
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RR_Rotation(p); // R-1 Rotation , Same as RR_Rotation code
    if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RL_Rotation(p); // R1 Rotation , Same as RL Rotation code
    if(BalanceFactor(p)==-2 && BalanceFactor(p->lchild)==0)
        return RR_Rotation(p); // R0 Rotation -> Can choise either of R1 or R-1 Rotation

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

    cout<<"Enter the node to be deleted: ";
    cin>>key;
    Delete(root,key);
    cout<<endl;

    cout<<"Root node is "<<root->data<<endl;
    int tree_height=Height(root);
    cout<<"Height of AVL tree is "<< tree_height-1<<endl;
}

/*
Output:

Enter the value for root node: 33

Enter the node value: 
22
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
77
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
55
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
99
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
11
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
35
Press any integer key to enter again: (Press -1 to exit) 
0
Enter the node value: 
66
Press any integer key to enter again: (Press -1 to exit) 
-1
Preorder Seq: 33 22 15 11 25 77 55 35 66 99 
Inorder Seq: 11 15 22 25 33 35 55 66 77 99
Postorder Seq: 11 15 25 22 35 66 55 99 77 33 
Enter the node to be deleted: 88

Root node is 33
Height of AVL tree is 3
*/