#include <iostream>
#include "lib_info.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int timeToInt(string time);
string convertUnderscores(string line);
//void Song::newSong(string title, int track, int time);
/* map<string, string> artistData;
 * map<string, string>::iterator it;
 * 
 * while(cin >> title){
 *	it = artistData.find(artist);
 *	if (it != artistData.end()){
 *		cout << "Old Artist: " << it->first << endl;"
 *		}else{
 *			Artist newArtist = new Artist;
 *			artistData.insert(make_pair(artist, album));
 *			cout << "New Artist: " << it->first << endl;
 *			}
 *	}
 *
 *
 */
/*printSong(string title, int track, int time){
	cout << title << " " <<



	}
	*/

int main(int argc, char *argv[]){

	ifstream fin;
	fin.open(argv[1]);
	string line, name, title,  artist, album, genre;
	istringstream buffer;
	string stringtime;
	int time, track;

	while (getline(fin, line)){
		buffer.clear();
		buffer.str(line);
		buffer >> title >> stringtime >> name >> album >> genre >> track;		
		title = convertUnderscores(title);
		time = timeToInt(stringtime);
		name = convertUnderscores(name);	
	Song *newsong = new Song;
	newsong->title = title;
	newsong->track = track;
	newsong->time = time;
	
//	cout << newsong->title << " " << newsong->track<< " " << newsong->time << " " << endl;		


 map<string, Song *> artistData;
  map<string, Song *>::iterator it;
  
 	it = artistData.find(name);
 	if (it != artistData.end()){
<<<<<<< HEAD
			cout << "Old Artist: "<< it->first << endl;
 		} else {
		Artist *newArtist = new Artist;
		newArtist->name = name;
		newArtist->time = time;
		artistData.insert(make_pair(name, newsong));
		cout << "New artist: " << newArtist->name << endl;
=======
 		cout << "Old Artist: " << it->first << endl;
 		}
	else{
 			Artist *newArtist = new Artist;
 			artistData.insert(make_pair(artist, album));
 			cout << "New Artist: " << it->second << endl;
 			}
>>>>>>> c4aa6f8f6388f37d87a6f38c660a90eb08c14a78
>>>>>>> 054c910314779f81343ad309aad41a773d08d5be
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


