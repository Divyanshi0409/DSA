// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>result;
	    void permute(string s, string op){
	        vector<string>r;
	        if(s.size() == 0){
	            result.push_back(op);
	            return;
	        }
	        for(int i=0; i<s.size();i++){
	            char current=s[i];
	            string lpart = s.substr(0,i);
	            string rpart = s.substr(i+1);
	            string roq=lpart+rpart;
	            permute(roq,op+current);
	        }
	            
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string output;
		    permute(S,output);
		    sort(result.begin(), result.end());
		    return result;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends