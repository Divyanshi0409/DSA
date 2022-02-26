

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getpivot(vector<int>&nums, int n){
        int m,s=0,e=n-1;
        while(s<e){
            m=(s+e)/2;
            if(nums[m] >= nums[0])
                s=m+1;
            else 
                e=m;
        }
        return s;
    }
    
    int binarysearch(vector<int>&nums, int s,int e,int target){
        int m;
        while(s<=e){
            m=(s+e)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                e=m-1;
            else
                s=m+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int pivot = getpivot(nums,n);
        if(target >= nums[pivot] && target <= nums[n-1])
            return binarysearch(nums,pivot,n-1,target);
        else
            return binarysearch(nums,0,pivot-1,target);
    }
};

int main(){
    Solution obj;
    vector<int>nums={4,5,6,7,0,1,2};
    cout<<obj.search(nums,0);

    return 0;
}