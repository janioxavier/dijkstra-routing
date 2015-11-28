#include <iostream>
#include <vector>
#include <list>

#include "Reader.h"
#include "HandleInputToGraph.h"

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
	HandleInputToGraph handle(filename);
	handle.init();
	cout <<	handle.toString();
}

int main(int argc, char* argv[]) {
	testReader();
	testHandleInputToGraph();
  return 0;
}
