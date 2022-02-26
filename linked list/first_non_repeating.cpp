// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		     string s;
		  int a[26]={0,};
		  a[A[0]-'a']++;
		  s+=A[0];
		  int k=0;
		   for(int i=1;i<A.size();i++){
		       a[A[i]-'a']++;
		       bool t=true;
		     for(int j=k;j<=i;j++ ){
		          if(a[A[j]-'a']<=1){
		              t=false;
		              s+=A[j];
		              break;
		          }else{
		              k++;
		          }
		         
		      }
		      if(t){
		          s+='#';
		      }
		   }
		   return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends