#include <iostream>
#include "lib_info.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
//Read in lines. Convert each time to an integer and test.
	
	ifstream fin;
	fin.open(argv[1]);
	string line, name, title,  artist, album, genre, track;
	istringstream buffer;
	int time;
//title>>time>>artist>>album>>genre>>track;
	
	while (getline(fin, line)){
		buffer.clear();
		buffer.str(line);
		buffer >> title >> time >> artist >> album >> genre >> track;
		cout << title << time << artist << album << genre << track;
	
	}
	cout <<"end";
	return 0;
}
