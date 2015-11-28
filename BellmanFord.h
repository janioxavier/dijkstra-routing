#pragma once
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include "Edge.h"

#define INF INT_MAX/2
#define null -1

class BellmanFord {
 public:
  BellmanFord();
  bool bellmanFord(std::list<Edge<int,int,int> > edgeList, 
		   std::list<int> vertexList, int source);
  std::vector<int> getDistance_() const;
  std::vector<int> getPredecessor_() const;
  std::string toString();
  ~BellmanFord();
 private:
  void init(std::list<int> vertexList, int source);
  void relaxEdges(std::list<Edge<int,int,int> > edgeList, int size);
  bool hasNegativeCycle(std::list<Edge<int,int,int> > edgeList);
  std::vector<int> distance_;
  std::vector<int> predecessor_;
};
