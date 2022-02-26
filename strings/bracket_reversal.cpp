// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
//A reversal means changing '{' to '}' or vice-versa.

#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s)
{
    int open=0,close=0,ans=0;
    if(s.length() & 1) return -1;
    
    stack<char> m;
    for(int i=0;i<s.length();i++){
        if(s[i] == '{')
        {
            open++;
            m.push(s[i]);
        }
        
        else if(s[i] =='}' && !m.empty() && m.top()=='{')
        {
            m.pop();
            open--;
        }
        else close++;
    }
    
    if(open&1) open=(open/2)+1;
    else    open=open/2;
    if(close&1) close=(close/2)+1;
    else    close=close/2;
    
    return (open+close);
    // your code here
}