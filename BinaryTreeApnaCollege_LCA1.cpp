#include<iostream>
#include<vector>
#include<queue>
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

Node* LCA1(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    
    Node* left_lca= LCA1(root->lchild,n1,n2);
    Node* right_lca= LCA1(root->rchild,n1,n2);

    if(left_lca==NULL && right_lca==NULL)
        return NULL;
    else if(left_lca!=NULL && right_lca!=NULL)
        return root;
    else if(left_lca!=NULL)
        return root->lchild;
    return root->rchild;
}

bool getpath(Node* root, int key, vector<int> &path)
{
    if(root==NULL)
        return false;

    path.push_back(root->data);

    if(root->data==key)
        return true;
    
    if(getpath(root->lchild,key,path) || getpath(root->rchild,key,path))
        return true;
    
    path.pop_back();
    return false;
}

int LCA2(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if(!getpath(root,n1,path1)||!getpath(root,n2,path2))
    {
        return -1;
    }

    int i=0;
    for(;i<(path1.size()&&path2.size()); i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
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

    Node* lca= LCA1(root,8,5);
    cout<<"Least Common Ancestor of 8 and 5 is "<<lca->data<<endl;
    // Output: Least Common Ancestor of 8 and 5 is 2

    int n1=8;
    int n2=6;
    int lca2= LCA2(root,n1,n2);
    cout<<"Least Common Ancestor of 8 and 6 is "<<lca2<<endl;
    // Output: Least Common Ancestor of 8 and 6 is 1

}