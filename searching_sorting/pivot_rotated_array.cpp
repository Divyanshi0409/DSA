
#include <stdio.h>
#include<iostream>
using namespace std;


int pivotelement(int arr[], int n){
    int low =0,high=n-1;
    while(low<high){
        int mid = (low+high)/2;
        if(arr[mid] > arr[high])
            low=mid+1;
        else 
            high=mid;
    }
    
    return arr[high];
}

int main()
{
    cout<<"pivot element in rotated sorted array ";
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    
    cout<<"\n";
    cout<<"Enter elements: ";
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"\n";    
    int pivot = pivotelement(arr,n);    
    cout<<"pivot element is "<<pivot;
    return 0;
}
