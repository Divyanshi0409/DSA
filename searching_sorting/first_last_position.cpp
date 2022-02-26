// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans={-1,-1};
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(x==arr[mid]){
            while(arr[lo]!=x)
                lo++;
            while(arr[hi]!=x)
                hi--;
            
            ans[0]=lo;
            ans[1]=hi;
            return ans;
            
        }
        
        else if(x<arr[mid])
            hi=mid-1;
        else
            lo=mid+1;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends