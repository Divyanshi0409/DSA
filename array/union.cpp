#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        vector<int>c(m+n);
        for(int i=0;i<n;i++)
            c.push_back(a[i]);
            
        for(int i=0;i<m;i++)
            c.push_back(b[i]);
        set<int> d;
        for(int i=0;i<c.size();i++)
            d.insert(c[i]);
        int size = d.size();
        return size-1;
    }

    
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	}
	
	return 0;
} 