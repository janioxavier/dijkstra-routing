#pragma once

template <typename T, typename W>
struct Edge {
  Edge() {};
  Edge(T sink) : sink_(sink), weight_(NULL) {};
  Edge(T sink, W weight) : sink_(sink), weight_(weight) {};

  const T sink_;
  const W weight_;
};
