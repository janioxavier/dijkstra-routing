#include <iostream>
#include <vector>
#include <list>

#include "Reader.h"
#include "HandleInputToGraph.h"
#include "BellmanFord.h"

using namespace std;

void testReader() {
    cout << "Test Reader class\n";
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
	handle.init();
	cout <<	handle.toString();
}

void testBellmanFord() {
	cout << "Test BellmanFord class\n";
	string filename("example.txt");
	HandleInputToGraph handle(filename, false);
	handle.init();
	BellmanFord *bf = new BellmanFord();
	bf->bellmanFord(handle.getEdge_List(), 
		handle.getVertex_List(), handle.getSource());
	cout << bf->toString() << "\n";
}

int main(int argc, char* argv[]) {
	testReader();
	testHandleInputToGraph();
	testBellmanFord();
  return 0;
}
