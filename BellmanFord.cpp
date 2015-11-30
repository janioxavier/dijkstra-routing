#include "BellmanFord.h"

BellmanFord::BellmanFord() {
}


bool BellmanFord::bellmanFord(std::list<Edge<int,int> > edgeList,
			      std::list<int> vertexList, int source) {
  init(vertexList, source);
  relaxEdges(edgeList, vertexList.size());
  return hasNegativeCycle(edgeList);
}

std::vector<int> BellmanFord::getDistance_() const {
  return distance_;
}

std::vector<int> BellmanFord::getPredecessor_() const {
  return predecessor_;
}

void BellmanFord::init(std::list<int> vertexList, int source) {
  for (int i = 0; i < vertexList.size(); i++) {
    distance_.push_back(INF);
    predecessor_.push_back(null);
  }
  distance_[source] = 0;
}

void BellmanFord::relaxEdges(std::list<Edge<int,int> > edgeList, int size) {
  for (int i = 0; i < size-1; i++) {
    for (std::list<Edge<int,int> >::iterator it = edgeList.begin();
	 it != edgeList.end(); ++it) {
      Edge<int,int> e = *it;
      int dist = distance_[e.source_] + e.weight_;
      if (dist < distance_[e.sink_]) {
	distance_[e.sink_] = dist;
	predecessor_[e.sink_] = e.source_;
      }
    }
  }
}

bool BellmanFord::hasNegativeCycle(std::list<Edge<int,int> > edgeList) {
  for (std::list<Edge<int,int> >::iterator it = edgeList.begin();
       it != edgeList.end(); ++it) {
    Edge<int,int> e = *it;
    if ((distance_[e.source_] + e.weight_) < distance_[e.sink_])
      return true;
  }
  return false;
}

std::string BellmanFord::toString() {
  std::stringstream ss;
  ss << "Vector Distance\n";
  for (int i = 0; i < distance_.size(); i++) {
    if (distance_[i] == INF)
      ss << "[" << i << "]" << " = -\n";
    else
      ss << "[" << i << "]" << " = " << distance_[i] << "\n";
  }
  ss << "Vector Predecessor\n";
  for (int i = 0; i < predecessor_.size(); i++) {
    ss << "[" << i << "]" << " = " << predecessor_[i] << "\n";
  }
  return ss.str();
}


BellmanFord::~BellmanFord() {
}

