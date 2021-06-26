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

int DistBtwTwoNodes(Node* root, int key, int dist)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return dist;

    int l_dist= DistBtwTwoNodes(root->lchild,key,dist+1);
    if(l_dist!=-1)
        return l_dist;
    
    int r_dist= DistBtwTwoNodes(root->rchild,key,dist+1);
    return r_dist;   

}

Node* LCA(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    Node* l_lca= LCA(root->lchild,n1,n2);
    Node* r_lca= LCA(root->rchild,n1,n2);

    if(l_lca!=NULL && r_lca!=NULL)
        return root;
    else if(l_lca==NULL && r_lca==NULL)
        return NULL;
    else if(l_lca!=NULL)
        return l_lca;
    return r_lca;
}

int ShortestDistBtwTwoNodes(Node* root, int n1, int n2)
{
    Node* lca_ptr = LCA(root,n1,n2);
    int lca_val= lca_ptr->data;

    int dist1= DistBtwTwoNodes(lca_ptr,n1,0);
    int dist2= DistBtwTwoNodes(lca_ptr,n2,0);

    return dist1+dist2; 
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

    cout<<"The shortest dist btw node 5 and 3 is "<<ShortestDistBtwTwoNodes(root,5,3)<<endl;
    // Output: The shortest dist btw node 5 and 3 is 3
}