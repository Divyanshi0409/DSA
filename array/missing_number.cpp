// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        sort(array.begin(),array.end());
        int i;
        for(i=0;i<n;i++)
        {
            if(array[i] != i+1)
                return i+1;
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> array(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> array[i];
    Solution obj;
    cout << obj.MissingNumber(array, n) << "\n";
    return 0;
} 