#pragma once

#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using std::string;
using std::ifstream;
using std::cout;

/**
 * Ler as linhas de um determinado arquivo.
 */    
class Reader {
    public:
    /**
     * Constroí o Reader com um objeto string.
     * @param filename nome do arquivo.
     */
    Reader(string filename);
    /**
     * Constroí o Reader com uma string.
     * @param filename nome do arquivo.
     */
    Reader(const char* filename);
    /**
     * Obtém uma linha do arquivo e aponta para a próxima
     * linha, enquanto tiver linha.
     * @return uma linha do arquivo no formato de uma
     *string.
     */
    string readLine();
    /**
     * Abre um dado arquivo
     * @param filename nome do arquivo.
     */
    void open(string filename);
    /**
     * @return true se ainda tiver linha, false
     *se encontrar EOF.
     */
    bool hasNextLine();
    /**
     * fecha o arquivo aberto.
     */
    void close();
    /**
     * Destroi o objeto Reader fechando o arquivo.
     */
    ~Reader();
    private:
    ifstream file_;  
};
