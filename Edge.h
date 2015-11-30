#pragma once

template <typename T, typename W>
struct Edge {
  Edge(T source, T sink, W weight) : source_(source), sink_(sink), weight_(weight) {};
  
  const T source_;	 
  const T sink_;
  W weight_;
};
