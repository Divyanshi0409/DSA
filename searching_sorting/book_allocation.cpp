/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

bool isallocatepossible(int arr[],int n,int barrier,int person){
    int per=1,pages=0,i;
    for(i=0;i<n;i++){
        if(arr[i] > barrier)
            return false;
        if(arr[i]+pages > barrier)
        {
            pages = arr[i];
            per++;
        }
        else
        {
            pages+=arr[i];
        }
        
    }
    if(per<=person)
            return true;
    return false;
    
}

int main()
{
    int students,books;
    
    cout<<"Enter number of books: ";
    cin>>books;
    
    cout<<"Enter number of students: ";
    cin>>students;
    
    int arr[books],low,high=0,res;
    
    cout<<"Enter pages in books: ";
    for(int i=0;i<books;i++)
    {
        cin>>arr[i];
        high+=arr[i];
    }
        
    low = arr[0];
    
    while(low<=high){
        int mid=(low+high)/2;
        if(isallocatepossible(arr,books,mid,students))
        {
            res=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    
    cout<<"Minimum pages that can be allocated : "<<res;

    return 0;
}