#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of elements you want to sort: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=1; i<n; i++)
    {
        int ith_element= arr[i];
        int j=i-1;
        while(j>=0 && (arr[j]>=ith_element))
        {
            swap(arr[j+1],arr[j]);
            j--;                        
        } 
        arr[j+1]=ith_element;
    }

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}

