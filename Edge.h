#pragma once

template <typename S, typename T, typename W>
struct Edge {
  Edge() {};
  Edge(T sink) : sink_(sink), weight_(NULL) {};
  Edge(T sink, W weight) : sink_(sink), weight_(weight) {};
  Edge(S source, T sink, W weight) : source_(source), sink_(sink), weight_(weight) {};
  
  const S source_;	 
  const T sink_;
  const W weight_;
};
