#include<iostream>
#include<climits>
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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool IsBST;
};

Info LargestBSTInBT(Node* root)
{
    if(root==NULL)
        return {0,INT_MIN,INT_MAX,0,true};
    if(root->lchild==NULL && root->rchild==NULL)
        return {1,INT_MIN,INT_MAX,1,true};
    
    Info LeftInfo= LargestBSTInBT(root->lchild);
    Info RightInfo= LargestBSTInBT(root->rchild);

    Info CurInfo;
    CurInfo.size= (LeftInfo.size + RightInfo.size + 1);
    
    if(LeftInfo.IsBST && RightInfo.IsBST && (LeftInfo.max<root->data && RightInfo.min>root->data))
    {
        CurInfo.max= max(LeftInfo.max, max(RightInfo.max,root->data));
        CurInfo.min= min(LeftInfo.min, min(RightInfo.min,root->data));
        CurInfo.ans= CurInfo.size;
        CurInfo.IsBST= true;
        return CurInfo;
    }

    CurInfo.ans= max(LeftInfo.ans,RightInfo.ans);
    CurInfo.IsBST= false;
    return CurInfo;
}


int main()
{
    /*
               1
             /   \
            8      30
          /   \   /
         4    9  16
          \
           5
    */
    Node* root= new Node(1);
    root->lchild= new Node(8);
    root->rchild= new Node(30);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(9);
    root->rchild->lchild= new Node(16);
    root->lchild->lchild->rchild= new Node(5);
    
    Info BTInfo= LargestBSTInBT(root); 
    cout<<"BT has largest BST of size "<<BTInfo.ans<<endl;
    // Output: BT has largest BST of size 4

}