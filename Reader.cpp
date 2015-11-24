#include "Reader.h"

Reader::Reader(string fileName) {
    file.open(fileName.c_str());  
}

Reader::Reader(const char * filename){
    file.open(filename); 
}

Reader::~Reader() {
    close();
}

string Reader::readLine(){
    string line;
    std::getline(file, line);
    return line;
}

bool Reader::hasNextLine() {
    return !file.eof();
}

void Reader::close() {
    file.close();
}
