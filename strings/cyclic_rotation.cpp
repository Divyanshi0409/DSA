#include<bits/stdc++.h>
using namespace std;

bool rotation(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    
    string temp = s1+s1;
    return (temp.find(s2)!=string::npos);
}

int main(){

    string s1,s2;
    cout<<"Enter 1st string: ";
    getline(cin,s1);
    cout<<"Enter 2nd string: ";
    getline(cin,s2);

    if(rotation(s1,s2))
        cout<<"Both are cyclic rotation of each other.";
    else    
        cout<<"They are not cyclic rotation of each other.";
    
    return 0;
}