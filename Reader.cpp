#include "Reader.h"

Reader::Reader(string fileName) {
    file_.open(fileName.c_str());  
}

Reader::Reader(const char * filename){
    file_.open(filename); 
}

Reader::~Reader() {
    close();
}

string Reader::readLine(){
    string line;
    std::getline(file_, line);
    return line;
}

void Reader::open(string filename) {
  file_.open(filename.c_str(), std::ifstream::in);
}

bool Reader::hasNextLine() {
    return file_.peek() != EOF;
}

void Reader::close() {
    file_.close();
}

