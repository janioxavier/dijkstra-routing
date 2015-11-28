#pragma once

#include "Reader.h"
#include "Edge.h"
#include <cstdlib>
#include <list>
#include <set>
#include <string>
#include <sstream>
#include <vector>

/**
 * Manipula os dados de entrada de um dado arquivo, transformando-os
 * em uma lista de arestas e uma lista de vértices. Além disso armazena
 * o vértice de origem.
 */
class HandleInputToGraph {
 public:
  HandleInputToGraph(const char* filename): reader_(filename) {};
  HandleInputToGraph(string filename): reader_(filename) {};
  void init();
  int getSource() const;
  std::list<Edge<int, int, int> > getEdge_List_() const;
  std::set<int> getVertex_Set_() const;
  std::vector<std::string> split(std::string s, char delim);
  std::string toString();
  ~HandleInputToGraph();
 private:
  void initEdge_List();
  std::vector<int> readerLineToArray();
  std::vector<int> split_toInt(std::string s, char delim);
  void addEdge(std::vector<int> vector);
  Reader reader_;
  int source_;
  std::list<Edge<int, int, int> > edge_list_;
  std::set<int> vertex_set_;
};
