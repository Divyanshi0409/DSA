// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int count(int p,int n){
            int temp=p, f=5,count=0;
            while(f<=temp){
                count+=temp/f;
                f*=5;
            }
            return(count>=n);
        }
    
        int findNum(int n)
        {
            if(n==1)
                return 5;
        //complete the function here
            int low=0, high=5*n;
            while(low < high){
                int mid = (low+high)/2;
                if(count(mid,n))
                    high=mid;
                else 
                    low=mid+1;
            }
            
            
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends