#pragma once

#include "Reader.h"
#include "Edge.h"
#include <list>

using std::list;

/**
 * Manipula os dados de entrada, transformando-os
 * em uma lista de arestas e uma lista de vértices.
 */
class HandleInput {
 public:
  /**
   * Construtor que inicializa o reader com
   * dado um dado nome de arquivo.
   *
   * @param filename
 private:
  Reader reader;
  list edge_list_;
  list vertex_list_;
}
