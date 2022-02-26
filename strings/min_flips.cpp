// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    int i,c1=0,c2=0;
    for(i=0;i<n;i++){
        if((i & 1) and S[i]=='0') c1++;
        if((i%2==0) and S[i]=='1') c1++;
        
        if((i & 1) and S[i]=='1') c2++;
        if((i%2==0) and S[i]=='0') c2++;
    }
    
    return min(c1,c2);
}