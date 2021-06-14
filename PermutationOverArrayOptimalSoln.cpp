#include<iostream>
#include<vector>
using namespace std;

string permute(vector<int> a, int n, int k, string ans)
{
    int fact=1;
    for(int i=1; i<=n ;i++)
    {
        fact = fact*i;
    }
    fact= fact/n;

    while(true)
    {
        int x= k/fact;
        ans= ans + to_string(a[x]);
        a.erase(a.begin()+x); // Begin()+Index_Pos
        if(a.size()==0)
            break;
        k= k%fact;
        fact = fact/a.size();
    }
    return ans;
}

int main()
{
    string ans="";
    vector<int> arr={1,2,3,4};
    int s= 4;
    
    
    cout<<"Enter the Kth pos for which number to find : ";
    int k;
    cin>>k;
    cout<< permute(arr,s,k-1,ans)<<endl; // as index start with 0
    /*
    Output
    Enter the Kth pos for which number to find : 2
    1243
    */

    int fact=1;
    for(int i=1; i<=s ;i++)
    {
        fact = fact*i;
    }

    cout<<"Now printing all elements :"<<endl;
    for(int i=0; i<fact ;i++)
    {
        cout<< permute(arr,s,i,ans)<<endl;
    }
    /*
    Output
    Now printing all elements :
    1234
    1243
    1324
    1342
    1423
    1432
    2134
    2143
    2314
    2341
    2413
    2431
    3124
    3142
    3214
    3241
    3412
    3421
    4123
    4132
    4213
    4231
    4312
    4321
    */
}
