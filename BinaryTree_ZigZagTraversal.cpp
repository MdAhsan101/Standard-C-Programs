#include<iostream>
#include<stack>
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

void ZigZagTraverse(Node* root)
{
    stack<Node*> curlvlstk;
    stack<Node*> nextlvlstk;

    curlvlstk.push(root);
    bool LeftToRight= true;

    while(!curlvlstk.empty())
    {
        Node* t= curlvlstk.top();
        curlvlstk.pop();
        cout<<t->data<<" ";
        
        if(LeftToRight)
        {   
            if(t->lchild)
                nextlvlstk.push(t->lchild);
            if(t->rchild)
                nextlvlstk.push(t->rchild);
        }
        else
        {
            if(t->rchild)
                nextlvlstk.push(t->rchild);
            if(t->lchild)
                nextlvlstk.push(t->lchild);
        }

        if(curlvlstk.empty())
        {
            swap(curlvlstk,nextlvlstk);
            LeftToRight= !LeftToRight;
        }
    }

}

int main()
{
    /*
               1
             /   \
            2      3
          /   \   /
         4    5  6
          \
           8
    */
    Node* root= new Node(1);
    root->lchild= new Node(2);
    root->rchild= new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->lchild= new Node(6);
    root->lchild->lchild->rchild= new Node(8);

    ZigZagTraverse(root);
    // Output: 1 3 2 4 5 6 8
}
