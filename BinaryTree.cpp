#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
}*root=NULL;

void CreateTree()
{
    int val;
    
    root= (struct Node*) malloc (sizeof(struct Node));
    cout<<"Enter value for root node: ";
    cin>>val;
    
    root->data=val;
    queue<struct Node*> q;
    q.push(root);
    struct Node* p;
    
    while(!q.empty())
    {
        p= q.front();
        q.pop();
        
        cout<<"Enter value for lchild of "<<p->data<<endl;
        cin>>val;
        if(val!=-1)
        {
            struct Node* t= (struct Node*) malloc(sizeof(struct Node));
            t->data = val; t->lchild=t->rchild=NULL;
            p->lchild = t;
            q.push(t);
        }

        cout<<"Enter value for rchild of "<<p->data<<endl;
        cin>>val;
        if(val!=-1)
        {
            struct Node* t= (struct Node*) malloc(sizeof(struct Node));
            t->data = val; t->lchild=t->rchild=NULL;
            p->rchild = t;
            q.push(t);
        }
        
    }

}

void RPreOrder(struct Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        RPreOrder(p->lchild);
        RPreOrder(p->rchild);
    }    
}

void RPostOrder(struct Node* p)
{
    if(p)
    {
        RPostOrder(p->lchild);
        RPostOrder(p->rchild);
        cout<<p->data<<" ";
    }    
}

void RInOrder(struct Node* p)
{
    if(p)
    {
        RInOrder(p->lchild);
        cout<<p->data<<" ";
        RInOrder(p->rchild);
    }    
}

void LevelOrderTraversal(struct Node* p)
{
    queue<struct Node*> q;
    cout<<p->data<<" ";
    q.push(p);

    while(!q.empty())
    {
        p= q.front();
        q.pop();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);    
        }    
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
    
}

int Height(struct Node* p) //Calculate height of binary tree
{
    if(p==NULL)
        return 0;
    int x= Height(p->lchild);
    int y= Height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int Count_Nodes(struct Node* p)
{
    if(p==NULL)
        return 0;
    int x= Count_Nodes(p->lchild);
    int y= Count_Nodes(p->rchild);
    return x+y+1;    
}

int main()
{
    
    CreateTree();

    cout<<"PreOrder: ";
    RPreOrder(root);
    cout<<endl;

    cout<<"PostOrder: ";
    RPostOrder(root);
    cout<<endl;

    cout<<"InOrder: ";
    RInOrder(root);
    cout<<endl;

    cout<<"LevelOrderTraversal: ";
    LevelOrderTraversal(root);
    cout<<endl;

    cout<<"Height of the tree: "<<Height(root)-1<<endl;
    //Note: In actual height function is returning no. of level (i.e level starts from 1)
    //So we deducted 1 at the end to output actual height (i.e. height starts from 0)

    cout<<"Total No. of nodes in binary tree is "<<Count_Nodes(root)<< endl;
    
}

/*
Output:

Enter value for root node: 10
Enter value for lchild of 10
5
Enter value for rchild of 10
20
Enter value for lchild of 5
4
Enter value for rchild of 5
8 
Enter value for lchild of 20
15
Enter value for rchild of 20
25
Enter value for lchild of 4
3
Enter value for rchild of 4
-1
Enter value for lchild of 8
-1
Enter value for rchild of 8
-1
Enter value for lchild of 15
-1
Enter value for rchild of 15
18
Enter value for lchild of 25
-1
Enter value for rchild of 25
-1
Enter value for lchild of 3
-1
Enter value for rchild of 3
-1
Enter value for lchild of 18
16
Enter value for rchild of 18
19
Enter value for lchild of 16
-1
Enter value for rchild of 16
-1
Enter value for lchild of 19
-1
Enter value for rchild of 19
-1

PreOrder: 10 5 4 3 8 20 15 18 16 19 25 
PostOrder: 3 4 8 5 16 19 18 15 25 20 10
InOrder: 3 4 5 8 10 15 16 18 19 20 25 
LevelOrderTraversal: 10 5 20 4 8 15 25 3 18 16 19
Height of the tree: 4
Total No. of nodes in binary tree is 11
*/