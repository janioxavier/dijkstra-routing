#include <iostream>
#include <vector>
#include <list>
#include <time.h>

#include "Reader.h"
#include "HandleInputToGraph.h"
#include "Graph.h"

const string filename ("example.txt");

using namespace std;

void Graph_LongestPath_Init(HandleInputToGraph& handle) {
  handle.init();
  Graph g(handle.getVertex_List().size());
  g.addEdges(handle.getEdge_List());
  cout << g.longestPath(handle.getSource()) << endl;
}

void Graph_LongestPath(HandleInputToGraph& handle) {
  if (handle.fileChanged()) {
    handle.update();
    Graph g(handle.getVertex_List().size());
    g.addEdges(handle.getEdge_List());
    cout << g.longestPath(handle.getSource()) << endl;
  }
}

int main(int argc, char* argv[]) {
  unsigned int timeOut = 3;  //wait 3 sec
  HandleInputToGraph handle(filename);
  Graph_LongestPath_Init(handle);
  while(1) {
    sleep(3);
    Graph_LongestPath(handle);
  }
  return 0;
}
