#include <list>
#include <sstream>
#include <string>
#include <stack>
#include <limits.h>
#define NINF INT_MIN
#define null -1

#include "AdjListNode.h"
#include "Edge.h"

using namespace std;

// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices’
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
 
    // A function used by longestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    
    // function to add edges from list of edges
 		void addEdges(list<Edge<int,int> > edge_list);
    // Finds longest distances from given source vertex
    string longestPath(int s);
};
