#include<iostream>
using namespace std;

int main(){
    int i,n;
    cin>>n;

    int arr[n];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    int num,count=0;
    cout<<"Enter element to count: ";
    cin>>num;

    for(i=0;i<n;i++)
    {
        if(arr[i] == num)
            count++;
    }
    cout<<"No of occurences: "<<count;

    return 0;
}