#pragma once

#include <climits>
#include <sstream>
#include <string>
#include <queue> //std::priority_queue
#include <vector>
#include <functional> //std::greater
#include <iostream>

#include "AdjacencyMatrix.h"

/**
 * Calcula a maior distância de um DAG.
 */
class Dijkstra {
 public:
  Dijkstra() {};
  void dijkstra(AdjacencyMatrix graph, int source);
  std::vector<int> getDistance() const;
  std::vector<int> getParent() const;
  std::string toString();
  ~Dijkstra() {};
 private:
  AdjacencyMatrix getNegativeGraph(AdjacencyMatrix graph);
  std::vector<int> distance_;
  std::vector<int> parent_;
};
