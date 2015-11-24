#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>


using std::string;
using std::ifstream;
using std::cout;
    
class Reader {
    public:
    Reader(string filename);
    Reader(const char* filename);
    string readLine();
    bool hasNextLine();
    void close();
    ~Reader();
    private:
    ifstream file;  
};
