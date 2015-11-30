#include "Graph.h"

Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u’s list
}

void Graph::addEdges(list<Edge<int,int> > edges_list) {
	for (list<Edge<int,int> >::iterator it = edges_list.begin();
			it != edges_list.end(); ++it)
	{
		Edge<int,int> e = *it;
		addEdge(e.source_, e.sink_, e.weight_);
	}
}
 
// A recursive function used by longestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
 
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}
 
// The function to find longest distances from a given vertex. It uses
// recursive topologicalSortUtil() to get topological sorting.
string Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[V];
    int parent[V];
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++) {
        dist[i] = NINF;
        parent[i] = null;
    }
    dist[s] = 0;
 
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != NINF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] < dist[u] + i->getWeight()) {
                dist[i->getV()] = dist[u] + i->getWeight();
             	parent[i->getV()] = u;
             }
        }
    }
 
    // Print the calculated longest distances
    std::stringstream ss;
    ss << "Longest Path from source vertex " << s << "\n";
    for (int i = 0; i < V; i++) {
    	ss << "[" << i << "]" << " = ";
        (dist[i] == NINF)? ss << "INF ": ss << dist[i] << "\n"; 
   	}
   	ss << "Path\n";
   	for (int i = 0; i < V; i++) {
   		ss << "[" << i << "]" << " = ";
   		(parent[i] == null)? ss << "-" : ss << parent[i];
   		ss << "\n";
   	}
   	return ss.str();
}
