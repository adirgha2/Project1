#include <iostream>
#include "lib_info.h"
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
//Read in lines. Convert each time to an integer and test.
	
	ifstream fin;
	fin.open(argv[1]);
//	fin>>		

string convertUnderscores(string line){
	replace(line.begin(), line.end(), '_',' ');
	return line;
}

	return 0;
}
