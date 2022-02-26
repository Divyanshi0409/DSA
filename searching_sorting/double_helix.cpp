#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr , int lb, int ub, int key){
    while(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            ub=mid-1;
        else
            lb=mid+1;
    }
    
    return -1;
}

int doublehelix(vector<int>a1, vector<int>a2){
    int temp1=0, temp2=0,index1=0,index2=0;
    int result=0;
    
    for(index1=0;index1<a1.size(); index1++){
        temp1+=a1[index1];
        int index = binarySearch(a2,0,a2.size()-1,a1[index1]);
        if(index !=-1 ){
            for(int i = index2; i<=index;i++){
                temp2+=a2[i];
            }
            result+=max(temp1, temp2);
            temp1=0;
            temp2=0;
            index2=index+1;
        }
        else if(index1 == a1.size()-1){
            for(int i = index2; i<=index;i++){
                temp2+=a2[i];
            }
            result+=max(temp1, temp2);
        }
    }
    return result;
}

int main(){
    vector<int>a1=vector<int>{3 ,5, 7, 9 ,20, 25, 30 ,40 ,55 ,56, 57, 60, 62};
    vector<int>a2=vector<int>{1 ,4 ,7, 11, 14, 25 ,44, 47 ,55, 57, 100};
    int result = doublehelix(a1,a2);
    cout<<"Result is: "<<result;
}