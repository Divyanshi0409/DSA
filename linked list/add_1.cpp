// { Driver Code Starts
//Initial template for C++

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
        cout << node->data; 
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

class Solution
{
    public:
    Node* reverse(Node *head)
	{
		// Initialize current, previous and
		// next pointers
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;

			// Reverse current node's pointer
			current->next = prev;

			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
		return head;
	}

    Node* addOne(Node *head) 
    {
        head = reverse(head);
        Node *cur=head;
        bool f=true;
        while(cur!=NULL and f==true){
            if(cur->next==NULL and cur->data==9){
                cur->data=1;
                Node *temp= new Node(0);
                temp->next=head;
                head=temp;
                cur=cur->next;
            }
            else if(cur->data==9){
                cur->data=0;
                cur=cur->next;
            }
            else{
                cur->data +=1;
                f=false;
            }
        
        }
        // Your Code here
        head = reverse(head);
        return head;// return head of list after adding one
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends