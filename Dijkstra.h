#pragma once

#include "AdjacencyList.h"
#include <queue>

class Dijkstra {
public:
  Dijkstra() {};

private:
  std::vector<unsigned int> distance_;
  std::vector<unsigned int> parent_;
};
