// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_map<int,int>mp;
        int h=0,count=0,maxcount=INT_MIN;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        
        for(int i=0;i<mp.size();i++)
        {
            if(mp[i]!=0){
                count++;
            }
            else {
                
                maxcount= max(maxcount,count);
                count=0;
            }    
        }
        return maxcount;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
    return 0;
} 