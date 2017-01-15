#include <bits/stdc++.h>
using namespace std;

int MAX_SIZE = 21;

void merge(vector<int> &A, int s, int m, int e);
void mergeSort(vector<int> &A, int s, int e);

int main(int argc, char const *argv[])
{

	ios_base::sync_with_stdio(0);
	
	srand(time(NULL));


	MAX_SIZE = rand()%80;
	vector<int> ar(MAX_SIZE);
	cout << "Size of array:" << MAX_SIZE <<endl;


	for (int i = 0; i < MAX_SIZE; ++i)
		ar[i] = rand()%1000;

	for (int i = 0; i < MAX_SIZE; ++i)
		cout << ar[i] << " ";
	cout << endl;

	mergeSort(ar, 0, MAX_SIZE);

	cout << "Sorted:" << endl;
	for (int i = 0; i < MAX_SIZE; ++i)
		cout << ar[i] << " ";
	cout << endl;

	return 0;
}



void mergeSort(vector<int> &A, int s, int e)
{
	if(e-s < 2)return;

	int m = (s+e)/2;
	mergeSort(A, s, m);
	mergeSort(A, m, e);
	merge(A, s, m, e);
}



/*
	Merge two sorted intervals : A[s..m-1] and A[m...e-1]
*/
void merge(vector<int> &A, int s, int m, int e)
{

	int n1 = m-s;
	int n2 = e-m;
	
	vector<int> a(n1+1), b(n2+1);

	for(int i=0; i<n1; i++)
		a[i]=A[s+i];
	for(int i=0; i<n2; i++)
		b[i]=A[m+i];

	a[n1]=INT_MAX;
	b[n2]=INT_MAX;

	int i=0, j=0;
	
	for (int k = 0; k <n1+n2; ++k)
	{
		if(a[i] <= b[j])
			A[k+s] = a[i++];
		else
			A[k+s] = b[j++];
	}
}
