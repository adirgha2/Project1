#include <iostream>
#include "lib_info.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int timeToInt(string time);
string convertUnderscores(string line);
/*printSong(string title, int track, int time){
	cout << title << " " <<



	}
	*/


int main(int argc, char *argv[]){
	//Read in lines. Convert each time to an integer and test.

	ifstream fin;
	fin.open(argv[1]);
	string line, name, title,  artist, album, genre, track;
	istringstream buffer;
	string stringtime;
	int time;

	while (getline(fin, line)){
		buffer.clear();
		buffer.str(line);
		buffer >> title >> stringtime >> artist >> album >> genre >> track;		
		title = convertUnderscores(title);
		time = timeToInt(stringtime);

		Song *newsong = new Song;	
 
  map<string, string> artistData;
  map<string, string>::iterator it;
  
 	it = artistData.find(artist);
 	if (it != artistData.end()){
 		cout << "Old Artist: " << it->first << endl;
 		}
	else{
 			Artist *newArtist = new Artist;
 			artistData.insert(make_pair(artist, album));
 			cout << "New Artist: " << it->second << endl;
 			}
	}
	cout <<"end";


	return 0;
}

int timeToInt(string time){
	int hour, min;
	char discard;
	istringstream buffer;
	buffer.str(time);
	buffer >> hour >> discard >> min;
	int intTime = (hour * 60) + min;
	return intTime;
}

string convertUnderscores(string line){
	replace(line.begin(), line.end(), '_',' ');
	return line;
}


