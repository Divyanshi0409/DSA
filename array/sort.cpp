#include<iostream>
using namespace std;
int main(){

    int n,i;
    cin>>n;
    int a[n];
    cout<<"Enter numbers: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    int sort=1;
    for(i=0;i<n;i++){
        if((a[i] == 1 && a[i+1] == 0) || (a[i] == 2 && a[i+1] == 0) || (a[i] == 2 && a[i+1] == 1)){
            sort=0;
            break;
        }
    }

    cout<<sort;


    return 0;
}