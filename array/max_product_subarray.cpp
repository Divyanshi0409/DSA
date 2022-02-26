// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	long long maxProduct(vector<int> arr, int n) {
	    long long l = 1, r = 1 , ans = INT_MIN;
       for(int i=0;i<n;i++){
           l = l * arr[i];
           r = r * arr[n-i-1];
           ans = max(ans,max(l,r));
           if(l==0) l =1;
           if(r==0) r =1;
       }
       return ans;
	}
};

int main() {
    int n, i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << "\n";
    return 0;
}  