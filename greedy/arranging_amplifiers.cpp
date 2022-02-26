// Given a list of integers specifying the set of amplifiers at hand, you must find out the order in which they must be placed, to get the highest signal strength. In case their exist multiple permutations with same output, you should print the one which has bigger amplifiers first.


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,n,ones=0;
        cin>>n;
        
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i] ==1)ones++;
        }
        
        sort(a,a+n,greater<int>());
        
        for(i=0;i<ones;i++) cout<<"1 ";        
        if((n-ones)==2 and a[0]==3 and a[1]==2)
            cout<<"2 3"<<endl;
            
        for(i=0;i<n-ones;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
        

    return 0;
}