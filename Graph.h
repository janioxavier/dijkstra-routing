#pragma once

#include "Edge.h"

template <typename T, typename W>
class Graph {
public:
  Graph() {};
  virtual ~Graph() {};

  virtual void add_edge(T source, T sink) = 0;
  virtual void add_edge(T source, T sink, W weight) = 0;

  virtual unsigned int edges() const = 0;

  virtual bool is_directed() const = 0;

  virtual unsigned int vertices() const = 0;
};
