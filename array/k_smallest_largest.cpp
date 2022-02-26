#include<iostream>
#include<algorithm>
using namespace std;

int k_smallest(int arr[] , int n, int k){
    sort(arr, arr+n);
    return arr[k-1];
}

int k_largest(int arr[] , int n, int k){
    sort(arr, arr+n);
    return arr[n-k];
}

int main(){

    int n,k;
    cin>>n;

    int i,arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter k: ";
    cin>>k;
    int largest,smallest;
    smallest = k_smallest(arr,n,k);
    largest = k_largest(arr,n,k);

    cout<<k<<" largest is "<<largest<<" and "<<k<<" smallest is "<<smallest<<endl;
    return 0;
}