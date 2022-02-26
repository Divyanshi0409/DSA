// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node*reverse(struct Node* node){
        struct Node*cur=node;
        struct Node* prev=NULL;
        struct Node* nex=NULL;
        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev;
            prev= cur;
            cur=nex;
        }
        cur=prev;
        return cur;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        Node*res=NULL, *cur=NULL, *temp;
        int s=0,c=0;
        while(first!=NULL || second!=NULL){
            s=c+(first?first->data:0)+(second?second->data:0);
            if(s>9)
            {
                c=1;
                s=s%10;
            }
            else 
                c=0;
            temp=new Node(s);
            if(res==NULL)res=temp;
            else
            cur->next=temp;
            cur=temp;
            
            if(first)
                first = first->next;
            if(second)
                second = second->next;
        }
        if(c>0)
        {
            temp = new Node(c);
            cur->next = temp;
            cur=temp;
        }
        res = reverse(res);
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends