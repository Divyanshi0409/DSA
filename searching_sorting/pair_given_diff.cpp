// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N

#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i=0, j =1;
    while(i<size && j<size)
    {
        if(arr[j]-arr[i] == n)
            return true;
        else if(arr[j] - arr[i] < n)
            j++;
        else 
            i++;
    }
    return false;
}