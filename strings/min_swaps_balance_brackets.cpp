// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int close=0,open=0,fault,i,ans=0;
        for(i=0;i<S.length();i++){
            if(S[i] == ']')
            {
                close++;
                fault=close-open;
            }
            else
            {
                open++;
                if(fault>0)
                {
                    ans+=fault;
                    fault--;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends