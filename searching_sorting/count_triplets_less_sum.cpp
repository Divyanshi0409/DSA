// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int i,j,k;
	    long long count=0;
	    sort(arr,arr+n);
	    for(k=0;k<n-2;k++){
	        i=k+1;
	        j=n-1;
	        while(i<j){
	            if(arr[i]+arr[j]+arr[k] < sum)
	            {
	                count += (j-i);
	                i++;
	            }
	            else j--;
	        }
	    }
	    
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends