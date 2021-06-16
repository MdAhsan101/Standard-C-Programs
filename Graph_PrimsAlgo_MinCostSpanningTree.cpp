#include<iostream>
using namespace std;
#define N 8
#define I 32767

int G[][N]={{I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}};

void Prims(int *near, int **soln)
{
    int min=I;
    int u,v,k;
    //Finding min edge of graph 
    for(int i=1; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            if(G[i][j]<min)
            {
                min=G[i][j];
                u=i; v=j;
            }                        
        }
    }    
    
    // First edge out of 7 edges is found and noted down in soln
    soln[0][1]= u; soln[1][1]= v; 
    near[u]=0; near[v]=0; // marking the vertices of the found edges with zero

    // Now initializing the near_array with the vertex nearer to end vertices of first min edge
    for(int j=1; j<N; j++)
    {
        if(near[j]!=0)
        {
            if(G[u][j]<G[v][j])
                near[j]=u;
            else
                near[j]=v;
        }
        
    }

    // Now the repeating steps for choosing other edges
    int i=2; // As first edge already being choosen
    while(i<N)
    {
        min=I;
        // Finding min edge
        for(int j=1; j<N; j++)
        {
            if(near[j]!=0 && G[j][near[j]]<min)
            {
                min =G[j][near[j]];
                u=j; v=near[j];
            }
        } 

        //Note: Found edge will always be min connected edge
        soln[0][i]=u; soln[1][i]=v;
        near[u]=0;

        // Finding nearby vertices and updating the near_array
        for(int j=1; j<N; j++)
        {
            if(near[j]!=0 && G[j][u]<G[j][near[j]])
            {
                near[j]=u;
            }
        }
        i++;
    }

    // Printing the soln matrix
    for(int j=1; j<N-1; j++)
    {
        cout<<"{"<<soln[0][j]<<","<<soln[1][j]<<"}"<<endl;
    }
}

int main()
{
    int** soln= new int* [2];
    for(int i=0; i<2; i++)
    {
        soln[i]= new int [N-1]; // means N-1=7 thus 6 edges to note starting from index 1
    }

    int near[N]={I,I,I,I,I,I,I,I};

    Prims(near,soln);

    for(int i=0; i<2; i++)
    {
        delete[] soln[i];
    }
}

/*
Output:

{1,6}
{5,6}
{4,5}
{3,4}
{2,3}
{7,2}
*/