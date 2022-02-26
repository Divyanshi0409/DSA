// Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int>c;
        int i;
        sort(arr,arr+n);
        for(i=0;i<n;i++){
            if(arr[i] == arr[i+1]){
              if(c.empty())
                c.push_back(arr[i]);
              else if(c.back() != arr[i])
                c.push_back(arr[i]);
            }
        }
        if(c.empty())
        {
            c.push_back(-1);
        }
        return c;
    }
};

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution obj;
    vector<int> ans = obj.duplicates(a, n);
    for (int i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}