// Given a singly linked list, remove all the nodes which have a greater value on its following nodes.
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


class Solution
{
    public:
    void reverse(Node **head)
    {
        Node *forward,*cur=*head, *prev=NULL;
        while(cur!=NULL){
            forward = cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
        }
        *head=prev;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        
        reverse(&head);
        int max=head->data;
        Node *cur=head, *prev=head;
        cur=cur->next;
        
        while(cur){
            
            if(cur->data >= max)
            {
                max = cur->data;
                prev=cur;
                cur=cur->next;
                
            }
            else{
                prev->next = cur->next;
                cur = prev->next;
            }
        }
        reverse(&head);
        return head;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends