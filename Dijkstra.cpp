#include "Dijkstra.h"

void Dijkstra::dijkstra(AdjacencyMatrix graph, int source) {
  AdjacencyMatrix ng = getNegativeGraph(graph);
  int vertices = ng.getVertices();
  for (int i = 0; i < vertices; i++) {
    distance_.push_back(inf);
    parent_.push_back(-1);
  }
  distance_[source] = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int> >
    Q (distance_.begin(), distance_.end());
  Q.push(source);
  
  while(Q.empty()) {
    int u = Q.top();
    std::cout << "u = " << u << "\n";
    for (int v = 0; v < vertices; v++) {
      int alt = distance_[u] + ng.getCost(u, v);
      if (alt < distance_[v]) {
	distance_[v] = alt;
	parent_[v] = u;
	Q.push(v);
      }
    }
  }
}

std::vector<int> Dijkstra::getDistance() const {
  return distance_;
}

std::vector<int> Dijkstra::getParent() const {
  return parent_;
}

AdjacencyMatrix Dijkstra::getNegativeGraph(AdjacencyMatrix graph) {
  AdjacencyMatrix copygraph (graph.getVertices(), false);
  copygraph.add_edges (graph.getNegativeEdgeList());
  return copygraph;
}

std::string Dijkstra::toString() {
  std::stringstream ss;
  ss << "Vector Distance\n";
  for (int i = 0; i < distance_.size(); i++) {
    if (distance_[i] == inf)
      ss << "[" << i << "]" << " = -\n";
    else
      ss << "[" << i << "]" << " = " << distance_[i] << "\n";
  }
  ss << "Vector Predecessor\n";
  for (int i = 0; i < parent_.size(); i++) {
    ss << "[" << i << "]" << " = " << parent_[i] << "\n";
  }
  return ss.str();
}
