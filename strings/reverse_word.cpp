#include<bits/stdc++.h>
using namespace std;

void reverseWord(string s){
    stack<char> st;
    int i;
    for(i=0; i<s.length(); i++){
        if(s[i]!=' '){
            st.push(s[i]);
        }
        else{
            while(st.empty() == false)
            {
                cout<<st.top();
                st.pop();
            }    
            cout<<" ";
        }
    }
    while(st.empty() == false)
    {
        cout<<st.top();
        st.pop();
    } 
}

int main(){
    string str;
    getline(cin,str);

    reverseWord(str);

    return 0;
}