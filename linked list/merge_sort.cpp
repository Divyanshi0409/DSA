// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
  void MergeSorting(Node **head){
      Node *cur=*head;
      Node*first;
      Node*second;
      if(!cur || !cur->next)
        return;
        
        findmid(cur,&first,&second);
        MergeSorting(&first);
        MergeSorting(&second);
        *head = merge(first, second);
        
  }
  
  void findmid(Node *cur, Node **first, Node **second){
      Node *fast=cur, *slow=cur;
      while(!fast && !fast->next ){
          fast=fast->next->next;
          slow=slow->next;
      }
      *first = cur;
      *second = slow->next;
      slow->next=NULL;
  }
  
  Node *merge(Node *first, Node *second){
      Node *ans=NULL;
      if(!first)
        return second;
      if(!second)
        return first;
      if(first->data <= second->data){
          ans=first;
          ans->next = merge(first->next, second);
      }
      else{
          ans = second;
          ans->next = merge(first, second->next);
      }
      return ans;
  }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        MergeSorting(&head);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends