#include <iostream>
#include <vector>
#include <list>

#include "Reader.h"
#include "HandleInputToGraph.h"
#include "BellmanFord.h"
#include "AdjacencyMatrix.h"
#include "Dijkstra.h"

using namespace std;

void testDijkstra() {
	cout << "Test Dijkstra class \n";
	string filename("example.txt");
	HandleInputToGraph handle(filename);
	AdjacencyMatrix g(handle.getVertex_Set().size(), true);
	g.add_edges(handle.getEdge_List());
	cout << g.toString();
	Dijkstra d;
	d.dijkstra(g, handle.getSource());
	cout << d.toString();
}

void testReader() {
    cout << "Test Reader class" << "\n";
    string fileName("example.txt");
    Reader r(fileName.c_str());
    while(r.hasNextLine()){
        cout << r.readLine() << endl;
	} 
}

void testHandleInputToGraph() {
	cout << "Test HandleInputToGraph class\n";
	string filename ("example.txt");
	HandleInputToGraph handle(filename, false);
	cout <<	handle.toString();
}

void testBellmanFord() {
	cout << "Test BellmanFord class\n";
	string filename("example.txt");
	HandleInputToGraph handle(filename, false);
	BellmanFord *bf = new BellmanFord();
	bf->bellmanFord(handle.getEdge_List(), 
		handle.getVertex_List(), handle.getSource());
	cout << bf->toString() << "\n";
}

void testAdjacencyMatrix() {
	cout << "Test AdjacencyMatrix class\n";
	string filename("example.txt");
	HandleInputToGraph handle(filename);
	AdjacencyMatrix g(handle.getVertex_Set().size(), false);
	g.add_edges(handle.getEdge_List());
	cout << g.toString() << endl;
	AdjacencyMatrix g1(handle.getVertex_Set().size(), true);
	g1.add_edges(handle.getEdge_List());
	cout << g1.toString() << "\n";
}

void testAdjacencyMatrix_Negative_Edge() {
	cout << "Test AdjacencyMatrix class\n";
	string filename("example.txt");
	HandleInputToGraph handle(filename);
	AdjacencyMatrix g(handle.getVertex_Set().size(), true);
	g.add_edges(handle.getEdge_List());
	cout << g.toString() << endl;
	cout << "Negative Edge List\n";
	std::list<Edge<int,int> > n_edg_list = g.getNegativeEdgeList();
	for (std::list<Edge<int,int> >::iterator it = n_edg_list.begin();
		it != n_edg_list.end(); ++it) {
		Edge<int,int> e = (*it);
		cout << e.source_ << " " << e.sink_ << " " << e.weight_ << "\n";
	}
	BellmanFord *bell = new BellmanFord();
	if (!(bell->bellmanFord(n_edg_list, handle.getVertex_List(), 2)))
		cout << bell->toString();
	else
		cout << "has negative cycle\n";
}

void initTest(const char* className) {
	cout << "Test " << className << " class\n";
}

int main(int argc, char* argv[]) {
	testReader();
	testHandleInputToGraph();
	testBellmanFord();
	testAdjacencyMatrix();
	testAdjacencyMatrix_Negative_Edge();
	testDijkstra();
  return 0;
}
