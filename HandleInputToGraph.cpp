#include "HandleInputToGraph.h"

std::list<Edge<int, int, int> > HandleInputToGraph::getEdge_List_() const{
  return edge_list_;
}

std::set<int> HandleInputToGraph::getVertex_Set_() const{
  return vertex_set_;
}

void HandleInputToGraph::init() {
  source_ = readerLineToArray().at(0);
  initEdge_List();
}

int HandleInputToGraph::getSource() const {
  return source_;
}

void HandleInputToGraph::initEdge_List(){
  while (reader_.hasNextLine()){
    std::vector<int> tokens = readerLineToArray();
    addEdge(tokens);
  }
}

void HandleInputToGraph::addEdge(std::vector<int> vector) {
  int source = vector.at(0);
  int sink = vector.at(1);
  vertex_set_.insert(source);
  vertex_set_.insert(sink);
  int weight = vector.at(2);
  edge_list_.push_back(Edge<int,int,int>(source, sink, weight));
  
}

std::vector<int> HandleInputToGraph::readerLineToArray(){
  return split_toInt(reader_.readLine(), ' ');
}

std::vector<std::string> HandleInputToGraph::split(std::string s, char delim) {
  std::vector<std::string> tokens;
  std::stringstream ss(s);
  std::string tok;
 
  while (getline(ss, tok, delim)){
    tokens.push_back(tok);
  }
  return tokens;
}

std::vector<int> HandleInputToGraph::split_toInt(std::string s, char delim) {
  std::vector<int> tokens;
  std::vector<std::string> tokens_string = split(s, delim);
  for (std::vector<std::string>::iterator it = tokens_string.begin();
       it != tokens_string.end(); ++it) {
    string value = *it;
    tokens.push_back(atoi(value.c_str()));
  }
  return tokens;
}

std::string HandleInputToGraph::toString() {
  std::stringstream ss;
  ss << "Source: " << source_ << "\n";
  ss << "Vertex:";
  for (std::set<int>::iterator it = vertex_set_.begin();
       it != vertex_set_.end(); ++it) {
    ss << " " << *it;
  }
  ss << "\nEdge List:\n";
  for (std::list<Edge<int,int,int> >::iterator it = edge_list_.begin(); 
       it != edge_list_.end(); ++it) {
    Edge<int,int,int> e = *it;
    ss <<  e.source_ << " ";
    ss <<  e.sink_ << " ";
    ss << e.weight_ << "\n";
  }
  return ss.str();
}

HandleInputToGraph::~HandleInputToGraph() {
  reader_.close();
  edge_list_.clear();
  vertex_set_.clear();
}
