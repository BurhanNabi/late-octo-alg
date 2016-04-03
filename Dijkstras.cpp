#include <iostream>
#include <queue>
#include <vector>


// The maximum number of vertices in the graph
#define MAX (int)1e5+1

// Add a pair to the vector
#define add(a,b) push_back(make_pair(a,b))

using namespace std;


typedef pair<int, int> edge;

/* 
Structure for holding distances of vertices in the Priority Queue
*/
struct NodeDistance
{
	int id;
	long distance;

	/*
	For the priority queue to work with

	NOTE: 	STL priority_queue is a max heap by default
			We can convert it to a min heap in multiple ways.
			One way is to modify how < opertor works

			Here we greater element of the two NodeDistance is seen as 
			the one with lesser distance, hence giving us a min heap in
			effect.
	*/
	bool operator<(NodeDistance other) const {
		if(distance!=other.distance)
			return other.distance < distance;
		else
			return id < id;
	}
};


// Adjacency List
vector<edge> AdjList[MAX];

// Vector that maintains whether a vertex has been added to the SET 
vector<int> added(MAX,0);

// To maintain lower bound on distance of vertices not in SET
vector<long> lowerBound(MAX,1e11);

// Maintains the minimum distance returned bt Dijkstra's
vector<long> minD(MAX,-1);


// Priority Q implemented using a vector
priority_queue < NodeDistance, vector<NodeDistance> > PQ;



/*
Function for Dijkstra's that handles the PQ	and calls relax(int)
*/
void dijkstras(int source) ;


/*
Relax all edges from this vertex that havent been visited
*/
void relax(int v) ;




int main(int argc, char const *argv[])
{	
	
	int numV, numE, t, f, w, source;
	cin >> numV >> numE;



	// Read weighted edges
	for (int i = 0; i < numE; ++i)
	{
		cin >> f >> t >> w;
		AdjList[f].add(t,w);

		/* For undirected graphs un-comment next line*/
		AdjList[t].add(f,w);
	}

	// Source vertex for the algorithm
	cin >> source;

	dijkstras(source);
	


	// Print Min Distances
	cout<<"Node\tDistance"<<endl;

	for (int i = 0; i < numV; ++i)
	{
		cout<<i<<"\t    "<<minD[i]<<endl;
	}

	return 0;
}

void dijkstras(int source) {

	// Push the source vertex into the Priority Queue
	NodeDistance f;
	f.id = source;
	f.distance = 0;
	PQ.push(f);



	while( !PQ.empty() ) {
		
		// Pop min-distance element from PQ
		NodeDistance t = PQ.top();
		PQ.pop();

		// Needed because there may be multiple NodeDistances with same id
		if( !added[t.id]) {
			added[t.id] = 1;
			minD[t.id] = t.distance;

			relax(t.id);
		}
	}
}


void relax(int v) {


	int curr;
	
	// Iterate over the AdjList of the node
	for (int i = 0; i < AdjList[v].size(); ++i)
	{
		curr = AdjList[v][i].first;

		/*
		If the curr node hasn't been added to the set and lowerBound can be
		lowered, then we add it to the PQ
		
		NOTE: This can introduce multiple NodeDistances with same id, but 
		that is taken care of in the dijkstra() 
		*/

		if(!added[ curr ] && lowerBound[ curr ] > minD[v] + AdjList[v][i].second) {
			lowerBound[ curr ] = minD[v] + AdjList[v][i].second;
			NodeDistance n;
			n.id = curr;
			n.distance = lowerBound[curr];
			PQ.push(n);
		}
	}
}