#include<iostream>
#define I 32767
#define E 9 //e= No. of edges
#define N 7 //N= No. of vertices
using namespace std;

int edges[3][9]=
            {   {1,1,2,2,3,4,4,5,5},
                {2,6,3,7,4,5,7,6,7},
                {25,5,12,10,8,16,14,20,18}
            };
int set[N+1]={-1,-1,-1,-1,-1,-1,-1,-1};
// '7' Vertices and '9' edges are present for the given graph
int include[E]={0};
int soln[2][N];

// writing union function
void do_union(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u]= set[u]+set[v];
        set[v]= u;
    }
    else
    {
        set[v]= set[u]+set[v];
        set[u]= v;
    }
}

// writing find function
int find_parent(int i)
{
    while(set[i]>0)
    {
        i= set[i];
    }
    return i;
}

void Kruskals()
{
    // Finding first min edge
    int u,v,min_edge_index,min;
    int s=1;
    while(s<=N-1)
    {
        min= I;
        for(int j=0; j<E; j++)
        {
            if(edges[2][j]<min && include[j]==0)
            {
                min=edges[2][j];
                u=edges[0][j]; v=edges[1][j];
                min_edge_index= j;
            }
        } 

        if(find_parent(u)!=find_parent(v))
        {
            do_union(find_parent(u),find_parent(v));
            soln[0][s]=u; soln[1][s]=v;
            s++;
        }
        include[min_edge_index]=1;
    }

    // Printing the soln matrix
    for(int j=1; j<=N-1; j++)
    {
        cout<<"{"<<soln[0][j]<<","<<soln[1][j]<<"}"<<endl;
    }
}

int main()
{
    Kruskals();
    return 0;
}

/*
Output:

{1,6}
{3,4}
{2,7}
{2,3}
{4,5}
{5,6}
*/