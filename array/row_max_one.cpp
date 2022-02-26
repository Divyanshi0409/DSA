// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int index,i,j,count=0,maxcount = INT_MIN;
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++)
	        {
	            if(arr[i][j] == 1)
	                count++;
	        }
	        if(count>maxcount)
	        {
	            maxcount=count;
	            index=i;
	        }
	        count=0;
	    }
	    if (maxcount==0) index=-1;
	    return index;
	}

};

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > arr(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
    Solution ob;
    auto ans = ob.rowWithMax1s(arr, n, m);
    cout << ans << "\n";
    return 0;
}