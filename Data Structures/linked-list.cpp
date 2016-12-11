#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *next;
};


void insert(Node *head, int k);
void printList(Node* head);
Node* search(Node *head,int k);
int del(Node *head, int k);

int main(int argc, char const *argv[])
{
	Node *head = new Node;
	head->key = 0;
	head->next = NULL;



	// Test insert
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);

	// Test traverse
	printList(head);

	// Test search
	cout << search(head, 1)->key << endl;

	// Delete 2
	del(head,2);

	printList(head);

	return 0;
}


/*
	Inserts a node at the head of the list O(1)
*/
void insert(Node *head, int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->next = head->next;

	head->next = temp;
}

/*
	Prints the list from head onwards
*/
void printList(Node* head)
{
	Node *temp = head->next;
	
	while(temp)
	{
		cout << temp->key << " ";
		temp = temp->next;
	}
	cout << endl;
}

/*
	Returns a pointer to the node searched
	Returnds NULL when it fails
	O(n)
*/
Node* search(Node *head,int k)
{
	Node *temp = head->next;
	
	while(temp)
	{
		if( temp->key == k )
		{
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

/*
	Returns 0 on successfully deleting the node with the given data
	Returns -1 when search for data fails
*/
int del(Node *head, int k)
{
	Node *curr = head->next, *prev = head;
	
	while(curr)
	{
		if( curr->key == k )
		{
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if(curr == NULL)
		return -1;

	cout << "Deleting " << curr->key << endl;

	prev->next = curr->next;
	delete curr;

	return 0;
}
