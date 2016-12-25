#include <bits/stdc++.h>
using namespace std;

struct info_t
{
	int start, end, sum;
};


int main(int argc, char const *argv[])
{

	ios_base::sync_with_stdio(0);

	// The size of the array (vector in this case)
	int N = 25;
	vector<int> ar(N);

	// Initialize array with random values with neg and pos numbers
	srand(time(NULL));
	int sign;
	for (int i = 0; i < N; ++i)
	{
		sign=rand()%2;
		ar[i] =  (sign == 1 ? rand()%100 : -rand()%100); 
	}


	cout << "ARRAY:\t";
	for (int i = 0; i < N; ++i)
		cout << ar[i] << " ";
	cout << endl;




	/*
		Current sums and maximum sum structures
		At the end of the algorithm maxS structure has info regarding the starting,
		end and the sum of the maximum subarray sum
	*/
	info_t currS, maxS;
	currS.start=0;currS.sum=0;maxS.sum = 0;

	for (int i = 0; i < N; ++i)
	{

		/*
			Update current sum.
			If current sum ends up being negative make current sum zero
			Start points to the start of current positive segment
		*/
		currS.sum += ar[i];
		if(currS.sum < 0)
		{
			currS.sum = 0;
			currS.start = i+1;
		}

		/*
			Check if maximum sum can be updated
			Update ending point of positive segment as well
		*/
		if(currS.sum > maxS.sum)
		{
			currS.end = i;
			maxS = currS;
		}
	}
	cout << "S:" << maxS.start << "\tE:" << maxS.end << endl;
	cout << maxS.sum << endl;

	return 0;
}
