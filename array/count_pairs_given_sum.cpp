// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int h=0,count=0;
        
        for(int i=0;i<n;i++){
            h=k-arr[i];
            if(mp[h])
                count+=mp[h];
            mp[arr[i]]++;
        }
        return count;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
    
    return 0;
} 