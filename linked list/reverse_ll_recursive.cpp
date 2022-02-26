#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head, *tail;
	LinkedList() { head = NULL, tail=NULL;}

    void reverseHelper(Node* node){
        if(node==NULL)
            return;
        reverseHelper(node->next);
        if(node==tail)
        {

        }
        else
        node->next->next = node;

    }

    void reverse()
	{
        reverseHelper(head);
        head->next = NULL;
        Node* temp = tail;
        tail=head;
        head=  temp;
		// Initialize current, previous and
		// next pointers
		
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
        if(tail == NULL)
            tail=temp;

		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}