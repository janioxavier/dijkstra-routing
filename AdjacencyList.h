#pragma once

#include "Graph.h"
#include <list>
#include <vector>

template <typename T, typename W>
class AdjacencyList : public Graph<T, W> {
public:
  AdjacencyList() : vertices_(0), directed_(false), edges_(0) {};

  explicit AdjacencyList(unsigned int vertices)
    : vertices_(vertices), edges_(0), directed_(false) {};

  AdjacencyList(unsigned int vertices, unsigned int edges)
    : vertices_(vertices), edges_(edges), directed_(false) {};

  AdjacencyList(unsigned int vertices, unsigned int edges, bool directed)
    : vertices_(vertices), edges_(edges), directed_(directed) {};

  ~AdjacencyList() {};

  void add_edge(T source, T sink) override {
    adjacent_vertices_[source].push_back(Edge<T, W>{source, sink});
    if (!directed_) {
      adjacent_vertices_[sink].push_back(Edge<T, W>{sink, source});
    }
  };

  void add_edge(T source, T sink, T weight) override {
    adjacent_vertices_[source].push_back(Edge<T, W>{source, sink});
    if (!directed_) {
      adjacent_vertices_[sink].push_back(Edge<T, W>{sink, source});
    }
  };

  unsigned int edges() const override {
    return edges_;
  };

  std::list<Edge<T, W>> adjacent_vertices(unsigned int source) const {
    return adjacent_vertices_[source];
  }

  constexpr bool is_directed() const override {
    return directed_;
  };

  unsigned int vertices() const override {
    return vertices_;
  };
private:
  std::vector<std::list<Edge<T, W>>> adjacent_vertices_;
  const bool directed_;
  unsigned int edges_;
  unsigned int vertices_;
};
