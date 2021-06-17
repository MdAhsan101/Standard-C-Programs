#include<iostream>
using namespace std;

void Merge(int* A, int low, int mid, int high)
{
    int b_size= high-low+1;
    int B[b_size];
    int i=low, j=mid+1, k=0;

    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i]; k++; i++;
        }
        else if(A[i]>A[j])
        {
            B[k]=A[j]; k++; j++;
        }
        else // A[i]==A[j]
        {
            B[k]=A[i]; i++; k++;
            B[k]=A[j]; j++; k++;
        }
        
    }

    while(i<=mid)
    {
        B[k]=A[i]; k++; i++;
    }

    while(j<=high)
    {
        B[k]=A[j]; k++; j++;
    }

    // Copying all element from B to A.
    k=0; // again setting k=0;
    for(int i=low; i<=high; i++)
    {
        A[i]= B[k]; k++; // incrementing k after each element get copied
    }

}

void MergeSort(int* arr, int low, int high)
{   
    if(low<high)
    {
        int mid= (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[]={5,2,3,4,2,6,7};
    MergeSort(arr,0,5);
    for(int i=0; i<7; i++)
        cout<<arr[i]<<" ";
}

/*
Output:

2 2 3 4 5 6 7
*/