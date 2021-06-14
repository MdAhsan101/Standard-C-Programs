#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int> &narr,int n, int *hash, vector<int> &ans)
{
    if(ans.size()==n)
    {
        for(int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return ;
    }

    for(int i=0; i<n; i++)
    {
        if(hash[i]==false)
        {
            int val= narr[i];
            ans.push_back(val);
            hash[i]=1; // Used for marking , 1 denotes mark position
            permute(narr,n,hash,ans);
            hash[i]=0;  // 0 denoted unmark pos
            ans.pop_back();
        }
    }
}

int main()
{
    vector<int> a={1,2,3,4};
    int n=4;
    int hash[n]={0};
    vector<int> ans;
    permute(a,n,hash,ans);
}

/*
Output:

1 2 3 4 
1 2 4 3 
1 3 2 4 
1 3 4 2 
1 4 2 3 
1 4 3 2 
2 1 3 4 
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4 
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1

*/