//Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL)
            return head;
        
        Node *dummy_even = new Node(-1);
        Node *dummy_odd = new Node(-1);
        Node *eventail=dummy_even;
        Node *oddtail=dummy_odd;
        
        Node *cur=head;
        while(cur!=NULL){
            if(cur->data%2!=0){
                oddtail->next=cur;
                oddtail=oddtail->next;
            }
            
            else{
                eventail->next=cur;
                eventail=eventail->next;
            }
            
            cur=cur->next;
        }
        
        eventail->next=dummy_odd->next;
        oddtail->next=NULL;
        
        return dummy_even->next;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends