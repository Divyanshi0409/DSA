// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */


struct node*gettail(struct node *head){
    node*temp = head;
    while(temp!=NULL && temp->next!=NULL)
        temp=temp->next;
    return temp;
}

struct node* partition(struct node *head, struct node *tail){
    struct node *pivot = head;
    struct node *cur=head->next, *prev =head;
    while(cur != tail->next){
        if(cur->data < pivot->data){
            swap(prev->next->data , cur->data);
            prev= prev->next;
        }
        cur= cur->next;
    }
    swap(prev->data, pivot->data);
    return prev;
}

void solve(struct node*head, struct node *tail){
    if(head==nullptr || tail==nullptr || head==tail)
        return;
    node *pivot = partition(head,tail);
    solve(head,pivot);
    solve(pivot->next, tail);
}

//you have to complete this function
void quickSort(struct node **headRef) {
    node *head=*headRef;
    if(head==nullptr || head->next==nullptr)
        return;
    node *tail=gettail(head);
    
    solve(head,tail);
}