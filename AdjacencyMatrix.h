#pragma once

#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <climits>
#include "Edge.h"

const int inf = INT_MAX;

class AdjacencyMatrix {
 public:
 AdjacencyMatrix(unsigned int vertices, bool directed) : vertices_(vertices), directed_(directed), edges_(0) { init(vertices); };
  ~AdjacencyMatrix();
  void add_edge(unsigned int source, unsigned int sink, int weight);
  void add_edges(std::list<Edge<int,int> > edges_list);
  int getCost(unsigned int source, unsigned int sink);
  bool is_directed() const;
  unsigned int getVertices() const;
  unsigned int getEdges() const;
  std::list<Edge<int,int> > getEdges_list() const;
  std::list<Edge<int,int> > getNegativeEdgeList();
  std::string toString();
 private:
  void init(int size);
  std::vector<std::vector<int> > adjacency_matrix_;
  std::list<Edge<int,int> > edges_list_;
  const bool directed_;
  unsigned int edges_;
  unsigned int vertices_;
};
