#include <iostream>
#include "Reader.h"

using namespace std;

int main(int argc, char* argv[]) {

    string fileName("example.txt");
    Reader r(fileName.c_str());
    while(r.hasNextLine()){
        cout << r.readLine() << endl;
	} 
	cout << "Sucesso" << endl;   
  return 0;
}
