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
Node* minimum(Node *n);
Node* maximum(Node *n);

Node* successor(Node *n);
Node* predecessor(Node *n);


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
	insert(tree,65);
	insert(tree,180);
	insert(tree,15);


	traverse(tree, "inorder");
	cout << endl;
	traverse(tree, "preorder");
	cout << endl;
	traverse(tree, "postorder");
	cout << endl;


	cout << "Search Result : " << search(tree, 50)->key << endl;
	cout << endl;


	cout << "Minimum Key : " << minimum(tree->root)->key << endl;
	cout << "Maximum Key : " << maximum(tree->root)->key << endl;
	cout << endl;


	cout << "Successor of 50 is " << successor( search(tree,50) )->key  << endl;
	cout << "Successor of 70 is " << successor( search(tree,70) )->key  << endl;
	cout << endl;


	cout << "Predecessor of 50 is " << predecessor( search(tree,50) )->key  << endl;
	cout << "Predecessor of 110 is " << predecessor( search(tree,110) )->key  << endl;
	cout << endl;


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

Node* minimum(Node *n)
{
	while(n->left)n = n->left;
	return n;
}

Node* maximum(Node *n)
{
	while(n->right)n = n->right;
	return n;
}

/*
	NOTE : Can return NULL
	Successor is either:
		1. Minimum value in right sub tree if right sub tree exists
		2. Lowest node whose left child is an ancestor of 'n'
			(First node which is a right parent from n upwards)
*/
Node* successor(Node *n)
{
	if(n->right) return minimum(n->right);
	
	Node *p= n->parent;
	while( p && n==p->right)
	{
		n = p;
		p = p->parent;
	}
	return p;
}


/*
	NOTE : Can return NULL
	Predecessor is either:
		1. Maximum value in left sub tree if left sub tree exists
		2. Lowest node whose right child is an ancestor of 'n'
			(First node which is a left parent from n upwards)
*/
Node* predecessor(Node *n)
{
	if(n->left) return maximum(n->left);
	
	Node *p= n->parent;
	while( p && n==p->left)
	{
		n = p;
		p = p->parent;
	}
	return p;
}

