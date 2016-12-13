#include <bits/stdc++.h>
using namespace std;

struct Node
{
	Node *left, *right, *parent;
	int key;
};

struct BST
{
	Node *root;
};


void insert(BST *T, int k);
void insertNode(Node *p, int dir, int k);

void traverse(BST *T, string type);
void inOrder(Node *t);
void preOrder(Node *t);
void postOrder(Node *t);

Node* search(BST *T, int k);

int main(int argc, char const *argv[])
{

	BST *tree = new BST;

	insert(tree,100);
	insert(tree,50);
	insert(tree,150);
	insert(tree,10);
	insert(tree,60);
	insert(tree,110);
	insert(tree,70);
	insert(tree,180);


	traverse(tree, "inorder");
	traverse(tree, "preorder");
	traverse(tree, "postorder");


	cout << "Search Result : " << search(tree, 50)->key << endl;

	return 0;
}


void insert(BST *T, int k)
{
	if(T->root == NULL)
	{
		Node *temp = new Node;
		temp->key = k;
		temp->left = temp->right = temp->parent = NULL;
		T->root = temp;
		return;
	}

	Node *t = T->root;
	while(1)
	{
		if( k < t->key ) 
		{
			if( t->left == NULL)
				return insertNode(t,0,k);
			else
				t = t->left;
		}
		else 
		{
			if( t->right == NULL)
				return insertNode(t,1,k);
			else
				t = t->right;
		}
	}
}

/*
	Inserts a child node at p
	dir specifies whether right(1) or left(0) child	
*/
void insertNode(Node *p, int dir, int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->parent = p;
	temp->left = temp->right = NULL;

	if(dir == 1)
		p->right = temp;
	else 
		p->left = temp;
}


void traverse(BST *T, string type)
{
	if(type == "inorder") {
		cout << "In Order Traversal:" << endl;
		inOrder(T->root);
		cout << endl;
	}
	if(type == "preorder") {
		cout << "Pre Order Traversal:" << endl;
		preOrder(T->root);
		cout << endl;
	}
	if(type == "postorder") {
		cout << "Post Order Traversal:" << endl;
		postOrder(T->root);
		cout << endl;
	}
}

void inOrder(Node *t)
{
	if( t )
	{
		inOrder(t->left);
		cout << t->key << " ";
		inOrder(t->right);
	}
}

void preOrder(Node *t)
{
	if( t )
	{
		cout << t->key << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(Node *t)
{
	if( t )
	{
		postOrder(t->left);
		postOrder(t->right);
		cout << t->key << " ";
	}
}

/*
	Returns pointer to the node if value is found 
	Otherwise returns NULL
*/
Node* search(BST *T, int k) 
{
	Node *t = T->root;
	
	while(1) 
	{
		if( t==NULL || t->key == k )
		{
			return t;
		}
		if( k < t->key )
			t = t->left;
		else
			t = t->right;
	}
}


