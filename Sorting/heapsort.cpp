/*
	
MAX HEAP
Consider A to be the array object

1. Must satisfy max heap property : A[parent(i)] >= A[i]
	-> Node at root must have the largest element

METHODS:

1. maxHeapify(A,i)
	Assumes the trees rooted at left(i) and right(i) are max-heaps and that node i itself violates the heap property.
	It percolates A[i] down such that tree rooted at i is a max-heap

2. buildMaxHeap(A)
	converts an array A into a max heap in a bottoms up fashion
	Note : A[ (n/2)]...A[MAX_SIZE] are all leaves of the tree
	Note: Linear time

3. heapSort(A)
	builds a max heap
	calls maxHeapify repeatedly
*/

// NOTE: This implementation will use 1 based indexing

#include <bits/stdc++.h>
using namespace std;


// Macros for 1 based indexing
#define parent(i) (i/2)
#define leftChild(i) (2*i)
#define rightChild(i) ((2*i)+1)

// Max data size + 1
#define M (int) (100)

// Max number of elements
int MAX_SIZE = 21;

// Function signatures
void maxHeapify(  vector<int> &A , int i);
void buildMaxHeap( vector<int> &A);
void heapSort( vector<int> &A);


// Inline functions
int inline mySwap(int &a, int &b) { a^=b; b^=a; a^=b;}
int inline print(vector<int> &A) { 	for(auto i:A) cout << i << " "; cout<<endl;}

int main(int argc, char const *argv[])
{

	vector<int> heap(MAX_SIZE,0);

	// Populate with random data
	srand(time(NULL));
	for (int i = 1; i < MAX_SIZE; ++i)
		heap[i] = rand() % M ;

	heapSort(heap);
	print(heap);

	return 0;
}

void maxHeapify(  vector<int> &A , int i)
{
	int l,r, largest, max;
	l = leftChild(i);
	r = rightChild(i);


	largest = i;
	max = MAX_SIZE - 1;
	
	if( l <= max  && A[l] > A[i] )
		largest = l;
	if( r <= max && A[r] > A [largest])
		largest = r;

	if( largest != i)
	{
		// Swap 'i' with 'largest'
		mySwap(A[i],A[largest]);
		maxHeapify(A, largest);
	}
}

void buildMaxHeap( vector<int> &A)
{
	int max = MAX_SIZE-1;
	for (int i = max/2 ; i > 0; --i)
		maxHeapify(A,i);
}


void heapSort( vector<int> &A)
{
	int max = MAX_SIZE-1;
	buildMaxHeap(A);

	for (int i = max; i > 1; --i)
	{
		mySwap(A[i],A[1]);
		--MAX_SIZE;
		maxHeapify(A,1);
	}
}
