#include <bits/stdc++.h>
using namespace std;

void initialize(vector<int> &v);
void print( vector<int> const &v);
void insertionSort(vector<int> &v);

int main(int argc, char const *argv[])
{

	// Size of the array to be sorted
	int N = 20;
	vector<int> ar(N);			

	// Initilize with random values 
	initialize(ar);

	print(ar);

	insertionSort(ar);
	print(ar);

	return 0;
}

void initialize(vector<int> &v)
{
	int n = v.size();

	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		v[i] = rand()%100;
}

/*
	Prints the vector in order of increasing indices
*/
void print( vector<int> const  &v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout  << endl;
}

/*
	Invariant : ar[0..i) is sorted after each iteration
	Algorithm : insert 'curr' into already sorted subarray	
*/
void insertionSort(vector<int> &ar)
{
	int curr,j;
	for (int i = 1; i < ar.size(); ++i)
	{
		curr = ar[i];
		j = i-1;
		while (ar[j] > curr && j >= 0 )
		{
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = curr;
	}
}

