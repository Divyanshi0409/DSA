// On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,w,h,n,t;
    
    cin>>t;
    while(t--){
        cin>>w>>h>>n;
        vector<int> a;
        vector<int> b;
        a.push_back(0);
        b.push_back(0);
        
        for(int i=0; i<n;i++){
            int x,y;
            cin>>x>>y;
            
            a.push_back(x);
            b.push_back(y);
        }
        
        a.push_back(w+1);
        b.push_back(h+1);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int mh=0, mw=0;
        for(int i=0;i<a.size()-1;i++){
            mh = max(mh,b[i+1]-b[i]-1);
            mw = max(mw,a[i+1]-a[i]-1);
        }
        
        cout<<mh*mw;
    }

    return 0;
}