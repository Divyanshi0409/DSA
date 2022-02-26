#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    string str;
    
    getline(cin,str);
    int i,len=str.length();
    for(i=0;i<(len/2);i++){
        swap(str[i], str[len-i-1]);
    }
    
    cout<<str;
    return 0;
}