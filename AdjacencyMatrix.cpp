#include "AdjacencyMatrix.h"

void AdjacencyMatrix::init(int size) {
  adjacency_matrix_;
  for (int i = 0; i < size; i++) {
    adjacency_matrix_.push_back(std::vector<int>());
    for (int j = 0; j < size; j++) {
      adjacency_matrix_[i].push_back(inf);
    }
  }
}

void AdjacencyMatrix::add_edge(unsigned int source, unsigned int sink, int weight) {
  if (adjacency_matrix_[source][sink] == inf) {
    adjacency_matrix_[source][sink] = weight;
    edges_list_.push_back(Edge<int,int>(source,sink,weight));
    if (!directed_) {
      adjacency_matrix_[sink][source] = weight;
      edges_list_.push_back(Edge<int,int>(sink, source, weight));
      edges_++;
    }
    edges_++;
  }
}

void AdjacencyMatrix::add_edges(std::list<Edge<int,int> > edges_list) {
  for (std::list<Edge<int,int> >::iterator it = edges_list.begin();
       it != edges_list.end(); ++it) {
    Edge<int,int> e = *it;
    add_edge(e.source_, e.sink_, e.weight_);
  }
}

int AdjacencyMatrix::getCost(unsigned int source, unsigned int sink) {
  return adjacency_matrix_[source][sink];
}

bool AdjacencyMatrix::is_directed() const {
  return directed_;
}

unsigned int AdjacencyMatrix::getVertices() const {
  return vertices_;
}

unsigned int AdjacencyMatrix::getEdges() const {
  return edges_;
}

std::list<Edge<int,int> > AdjacencyMatrix::getEdges_list() const {
  return edges_list_;
}

std::list<Edge<int,int> > AdjacencyMatrix::getNegativeEdgeList() {
  std::list<Edge<int,int> > negative_edge_list (edges_list_);
  for (std::list<Edge<int,int> >::iterator it = negative_edge_list.begin();
       it != negative_edge_list.end(); ++it) {
    (*it).weight_ *= -1;
  }
  return negative_edge_list;
}

std::string AdjacencyMatrix::toString() {
  std::stringstream ss;
  if (directed_)
    ss << "Directed Graph\n";
  else
    ss << "Undirected Graph\n";
  ss << "Vertex: " << vertices_ << "\nEdges: " << edges_ << "\n";
  for (int i = 0; i < vertices_; i++)
    ss << "\t" << i;
  ss << "\n";
  for (int i = 0; i < vertices_; i++) {
    ss << i;
    for (int j = 0; j < vertices_; j++) {
      ss << "\t";
      int cost = adjacency_matrix_[i][j];
      if (cost == inf)
	ss << "-";
      else
	ss << cost;
    }
    ss << "\n";
  }
  return ss.str();
}

AdjacencyMatrix::~AdjacencyMatrix() {
}
