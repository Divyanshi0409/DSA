// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        unordered_map<char,char> m;
        m[')']='(';
        m['}']='{';
        m[']']='[';
        
        int i;
        // if(s.length() ==)
        for(i=0;i<x.length();i++)
        {
            if(x[i] == '(' || x[i]=='{' || x[i]=='[')
                s.push(x[i]);
            else if(x[i] == ')' || x[i]=='}' || x[i] == ']')
            {   if(!s.empty() && s.top()  == m[x[i]] )
                    s.pop();
                else 
                    return false;
            }
        }
        if(s.empty())
            return true;
        else 
            return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends