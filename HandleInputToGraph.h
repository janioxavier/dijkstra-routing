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
 HandleInputToGraph(const char* filename): reader_(filename), filename_(std::string (filename)), source_(-1) {};
 HandleInputToGraph(string filename): reader_(filename), filename_(filename), source_(-1) {};
  int getSource() const;
  std::list<Edge<int,int> > getEdge_List() const;
  std::set<int> getVertex_Set() const;
  std::list<int> getVertex_List() const;
  std::vector<std::string> split(std::string s, char delim);
  bool fileChanged();
  void update();
  void init();
  std::string toString();
  ~HandleInputToGraph();
 private:
  void initEdge_List();
  std::vector<int> readerLineToArray();
  std::vector<int> split_toInt(std::string s, char delim);
  void addEdge(std::vector<int> vector);
  Reader reader_;
  std::string filename_;
  int source_;
  std::list<Edge<int,int> > edge_list_;
  std::set<int> vertex_set_;
};
