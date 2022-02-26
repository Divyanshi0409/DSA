// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int i,j,n=nums.size();
        int space[n+1][n+1],ls[n+1][n+1],c[n+1],p[n+1];
        for(i=1;i<=n;i++){
            space[i][i] = k-nums[i-1];
            for(j=i+1;j<=n;j++)
                space[i][j] = space[i][j-1] - nums[j-1] -1;
        }
        
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                if(space[i][j] < 0)
                    ls[i][j] = 1e6;
                else if(j==n && space[i][j] > 0)
                    ls[i][j]=0;
                else ls[i][j] = space[i][j] * space[i][j];
            }
        }
            
        c[0]=0;
        for(i=1;i<=n;i++){
            c[i]=1e6;
            for(j=1;j<=i;j++){
                if(c[j-1]!=1e6 && ls[j][i]!=1e6 and c[j-1]+ls[j][i]<c[i])
                {
                    c[i] = c[j-1]+ls[j][i];
                    p[i]=j;
                }    
            }
        }
        return c[n];
        
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends