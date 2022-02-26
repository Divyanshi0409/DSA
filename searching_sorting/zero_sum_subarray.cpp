// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<int,int>m;
        long long sum=0,count=0, i=-1;
        m[0]=1;
        while(i<n-1){
            i++;
            sum+=arr[i];
            
            if(m[sum]){
                count+=m[sum];
                m[sum]++;
            }
            else
                m[sum]++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends