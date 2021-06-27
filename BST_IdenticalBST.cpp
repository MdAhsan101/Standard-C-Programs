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

bool IsIdentical(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    else if(root1==NULL || root2==NULL)
        return false;
    else // both NOT NULL
    {
        bool cond1= root1->data==root2->data;
        bool cond2= IsIdentical(root1->lchild,root2->lchild);
        bool cond3= IsIdentical(root1->rchild,root2->rchild);
        if(cond1 && cond2 && cond3)
            return true;
        return false;
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

    bool ans= IsIdentical(root,root);
    cout<<"BT is Identical ? : "<<ans<<endl;

    /*
               1
             /   \
            9      3
          /   \   /
         4    5  6
          \
           8
    */
    Node* root2= new Node(1);
    root->lchild= new Node(9);
    root->rchild= new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->lchild= new Node(6);
    root->lchild->lchild->rchild= new Node(8);

    ans= IsIdentical(root,root2);
    cout<<"BT is Identical ? : "<<ans<<endl;

    /*
    Output:
    BT is Identical ? : 1
    BT is Identical ? : 0
    */

}