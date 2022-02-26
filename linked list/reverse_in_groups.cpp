//Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(k==1 || head==NULL)
            return head;
        struct node *dummy = new node(0);
        dummy->next = head;
        struct node *cur=dummy, *nex =dummy, *pre=dummy;
        
        int count=0;
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }
        
        while(count>=k){
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++){
                cur->next = nex->next;
                nex->next=pre->next;
                pre->next = nex;
                nex=cur->next;
            }
            
            pre=cur;
            count-=k;
        }
        
        return dummy->next;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends