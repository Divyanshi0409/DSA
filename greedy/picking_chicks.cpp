/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c,n,k,b,t,i;
    cin>>c;
    
    for(int j=1;j<=c;j++){
        cin>>n>>k>>b>>t;
        
        int x[n],v[n];
        
        for(i=0;i<n;i++)
            cin>>x[i];
        for(i=0;i<n;i++)
            cin>>v[i];
            
        int count=0,swap=0,not_possible=0;
        for(i=n-1;i>=0;i--){
            int distance_possible=v[i]*t;
            int distance_needed=b-x[i];
            
            if(distance_needed <= distance_possible){
                count++;
                if(not_possible>0)
                    swap+=not_possible;
            }
            else
                not_possible++;
                
            if(count >= k)
                break;
        }
        
        if(count>=k)
            cout<<"case #"<<j<<":"<<swap;
        else
            cout<<"case #"<<j<<":IMPOSSIBLE";
        
    }

    return 0;
}