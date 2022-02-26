// Given an array of integers. Find the Inversion Count in the array. 
//Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
//Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long A[],long long left,long long mid,long long right){
   long long i = left,j = mid,k = 0;
   long long temp[right-left+1];
   long long count = 0;
   while(i<mid && j<=right){
       if(A[i] <= A[j]){
           temp[k++] = A[i++];
       }else{
           temp[k++] = A[j++];
           count += mid - i;
       }
   }
   while(i<mid){
       temp[k++] = A[i++];
   }
   while(j<=right){
       temp[k++] = A[j++];
   }
   // copy temp array to original array..
   for(int i=left,k=0;i<=right;k++,i++){
       A[i] = temp[k];
   }
   return count;
}
long long merge_sort(long long A[],long long left,long long right){
   long long count=0;
   if(right>left){
       long long mid = (left+right)/2;
       long long countLeft = merge_sort(A,left,mid);
       long long countRight = merge_sort(A,mid+1,right);
       long long myCount = merge(A,left,mid+1,right);
       
       return myCount + countLeft + countRight;
   }
   return count;
}
long long int inversionCount(long long A[],long long n){
   long long ans = merge_sort(A,0,n-1);
   return ans;
}

};
// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends