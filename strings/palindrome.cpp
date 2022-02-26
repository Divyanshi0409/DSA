#include<bits/stdc++.h>
using namespace std;

string reverseWord(string s){
    stack<char> st;
    int i;
    string str;
    for(i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    while(st.empty() == false)
    {
        str.push_back(st.top());
        st.pop();
    } 
    return str;
}

int main(){
    string str;
    getline(cin,str);

    string abc=reverseWord(str);
    cout<<"Reversed string is: "<<abc<<"\n";

    if(str == abc)
        cout<<"The string is palindrome.";
    else    
        cout<<"The string is not palindrome.";
    return 0;
}