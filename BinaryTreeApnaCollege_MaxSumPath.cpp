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

int MaxPathUtil(Node* root, int &ans)
{
    if(root==NULL)
        return 0;
    
    int left= MaxPathUtil(root->lchild,ans);
    int right= MaxPathUtil(root->rchild,ans);

    int SinglePathSum= max(root->data, max(root->data+left, root->data+right));
    int NodeMax= max(SinglePathSum,(root->data+left+right));

    ans= max(NodeMax,ans);
    return SinglePathSum; 
}

int MaxPathSum(Node* root)
{
    int ans=-32767;
    MaxPathUtil(root,ans);
    return ans;
}

int main()
{
    /*
                 10
                /
               1
             /   \
           -2      3
          /   \   /
         4    5  6
          \  /
          8 -9
    */
    Node* root= new Node(10);
    root->lchild= new Node(1);
    root->lchild->lchild= new Node(-2);
    root->lchild->rchild= new Node(3);
    root->lchild->lchild->lchild= new Node(4);
    root->lchild->lchild->rchild= new Node(5);
    root->lchild->lchild->rchild->lchild= new Node(-9);
    root->lchild->rchild->lchild= new Node(6);
    root->lchild->lchild->lchild->rchild= new Node(8);

    int ans= MaxPathSum(root);
    cout<<"The max path sum in given BTree is "<<ans<<endl;
    // Output: The max path sum in given BTree is 21
}