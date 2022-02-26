// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>res;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        if(arr.empty())
            return res;
        
        int i,j;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int left = k-arr[i]-arr[j];
                int first = j+1,last = n-1;
                while(first<last){
                    int two_sum = arr[first]+arr[last];
                    
                    if(two_sum < left)
                        first++;
                    else if(two_sum > left)
                        last--;
                    else{
                        vector<int>quadraplet(4,0);
                        quadraplet[0] = arr[i];
                        quadraplet[1] = arr[j];
                        quadraplet[2] = arr[first];
                        quadraplet[3] = arr[last];
                        res.push_back(quadraplet);
                        
                        while(first < last && arr[first] == quadraplet[2]) first++;
                        while(first < last && arr[last] == quadraplet[3])   last--;
                        
                    }
                }
                while(j<n && arr[j+1] == arr[j]) j++;
            }
             while(i<n && arr[i+1] == arr[i]) i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends