#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int val)
    {
        data=val;
        lchild=NULL;
        rchild=NULL;
    }
};

void PrintSubtreeNodes(Node* root, int k)
{
    if(root==NULL || k<0)
        return;
    
    if(root!=NULL && k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    PrintSubtreeNodes(root->lchild,k-1);
    PrintSubtreeNodes(root->rchild,k-1);
}

int PrintNodeAtK(Node* root, int target, int k)
{
    if(root==NULL)
        return -1;
    
    if(root->data==target)
    {
        PrintSubtreeNodes(root,k);
        return 0;
    }

    int dl= PrintNodeAtK(root->lchild,target,k);
    if(dl!=-1)
    {
        if((1+dl)==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            PrintSubtreeNodes(root->rchild,k-dl-2);
        }
        return (1+dl);
    }

    int dr=PrintNodeAtK(root->rchild,target,k);
    if(dr!=-1)
    {
        if((1+dr)==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            PrintSubtreeNodes(root->rchild,k-dr-2);
        }
        return (1+dr);
    }

    return -1;
}

int main()
{
    /*
                 10
                /
               1
             /   \
            2      3
          /   \   /
         4    5  6
          \  /
          8  9
    */
    Node* root= new Node(10);
    root->lchild= new Node(1);
    root->lchild->lchild= new Node(2);
    root->lchild->rchild= new Node(3);
    root->lchild->lchild->lchild= new Node(4);
    root->lchild->lchild->rchild= new Node(5);
    root->lchild->lchild->rchild->lchild= new Node(9);
    root->lchild->rchild->lchild= new Node(6);
    root->lchild->lchild->lchild->rchild= new Node(8);

    int trgt= 2;
    int k=2;
    PrintNodeAtK(root,trgt,k);
    //Output: 8 9 3 10

}