#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void BFS(int G[][7], int n, int sv,int* visited)
{
    cout<<sv<<" ";
    visited[sv]=1;
    queue<int> q;
    q.push(sv);

    while(!q.empty())
    {
        int vv= q.front();  //vv= visited vertex
        q.pop();
        for(int j=1; j<=n-1; j++)
        {            
            if(G[vv][j]!=0 && visited[j]==0)
            {
                int ev=j; //ev= explored vertex
                cout<<ev<<" ";
                visited[ev]=1;
                q.push(ev);
            }
        }
    }
}

void DFS(int G[][7], int n, int v,int* visited)
{
    if(visited[v]==0)
    {
        cout<<v<<" ";
        visited[v]=1;
        for(int j=1; j<=n-1; j++)
        {
            if(G[v][j]!=0)
            {
                int ev= j;
                DFS(G,n,ev,visited);
            }
        }
    }
}

int main()
{   
    int visited[7]={0};
    int G[7][7]={
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    }; // We are given 6 vertices and vertex starts with index 1

    cout<<"BFS: ";
    BFS(G,7,1,visited); cout<<endl;
    
    int visited2[7]={0};
    cout<<"DFS: ";
    DFS(G,7,1,visited2);
    cout<<endl;
}