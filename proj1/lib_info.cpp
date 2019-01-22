#include <iostream>
#include "lib_info.h"
#include <fstream>
<<<<<<< HEAD
#include <sstream>
=======
#include <algorithm>
>>>>>>> 68db9f591d4b6be505438fd147646beeb67d1342

using namespace std;

int main(int argc, char *argv[]){
//Read in lines. Convert each time to an integer and test.
	
	ifstream fin;
	fin.open(argv[1]);
<<<<<<< HEAD
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
=======
//	fin>>		

string convertUnderscores(string line){
	replace(line.begin(), line.end(), '_',' ');
	return line;
}

>>>>>>> 68db9f591d4b6be505438fd147646beeb67d1342
	return 0;
}
