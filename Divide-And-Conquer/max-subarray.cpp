/*
	Divide and conquer algorithm for maximum subarray problem
*/

#include <bits/stdc++.h>
using namespace std;


/*
	Return type 
		li: left index
		ri: right index
		sum: sum of the subarray
*/
struct info_t
{
	int li, ri, sum;
};

info_t maxCrossing( int l, int r, vector<int> &v);
info_t maxSubarray( int l, int r, vector<int> &v);

int main(int argc, char const *argv[])
{

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
	{
		cout << ar[i] << " ";
	}
	cout << endl;


	info_t info = maxSubarray(0, ar.size()-1, ar);


	cout << "L:" << info.li << "\tR:" << info.ri <<  "\tSum:"<< info.sum << endl;
	for (int i = info.li; i < info.ri+1; ++i)
	{
		cout << ar[i] << " ";
	}
	cout << endl;

	return 0;
}

/*
	Returns the info of the maximum subarray crossing the mid point in given limits
*/
info_t maxCrossing( int l, int r, vector<int> &v)
{
	int lsum = INT_MIN, rsum = INT_MIN, mid=(l+r)/2;
	int li=mid, ri=mid+1, sum=0;

	for (int i = mid; i >= l; --i)
	{
		sum += v[i];
		if( sum  > lsum)
		{
			lsum = sum ;
			li = i;
		}
	}

	sum = 0;
	for (int i = mid+1; i <= r; ++i)
	{
		sum += v[i];
		if( sum + v[i] > rsum)
		{
			rsum = sum ;
			ri = i;
		}
	}

	info_t n;
	n.li = li; n.ri = ri; n.sum = lsum+rsum;

	return n;
}

/*
	Divides the problem into smaller sub problems
	Checks which of the sub solutions has a  greater sum taking into account the crossing solution
	Returns greatest info

	BASE CASE : When sub problem has only one element
*/
info_t maxSubarray( int l, int r, vector<int> &v)
{

	if( l == r )
	{
		info_t n;
		n.li = n.ri = l;
		n.sum = v[l];
		return n;
	}

	int mid = (l+r)/2;

	info_t LI = maxSubarray(l, mid, v);
	info_t RI = maxSubarray(mid+1, r, v);
	info_t CI = maxCrossing(l, r, v);

	if( LI.sum > RI.sum && LI.sum > CI.sum ) return LI;
	if( RI.sum > LI.sum && RI.sum > CI.sum ) return RI;
	return CI;
	
}


