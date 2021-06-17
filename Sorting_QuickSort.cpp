#include<iostream>
#define I 32767
using namespace std;

int Partition(int* arr, int low,int high)
{
    int pivot= arr[low];
    int i=low, j=high;

    while(i<j)
    {
        do
        {
            i++;
        }while(arr[i]<pivot);

        do
        {
            j--;
        } while (arr[j]>pivot);

        if(i<j)
        {
            swap(arr[i],arr[j]);
        }        
    }
    swap(arr[low],arr[j]);  
    return j; 
}

QuickSort(int* arr,int low, int high)
{
    if(low<high)
    {
        int pi= Partition(arr,low,high);
        QuickSort(arr,low,pi);
        QuickSort(arr,pi+1,high);
    }
}

int main()
{
    int arr[]={5,4,2,3,7,8,1,I};
    QuickSort(arr,0,7);
    for(int i=0; i<7; i++)
        cout<<arr[i]<<" ";
        
}

/*
Output:
1 2 3 4 5 7 8
*/