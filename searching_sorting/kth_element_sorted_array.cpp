// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=n-1, j=0;
        while(arr1[i] > arr2[j] && i>=0 && j<m)
        {
            swap(arr1[i] , arr2[j]);
            i--;
            j++;
        }
        
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        
        if(k<=n)
            return arr1[k-1];
        else
            return arr2[k-n-1];
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends