#include <iostream>
//#include "lib_info.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Song { 
	public:
		string title;
		int time;
		int track;
};

class Album {
	public:
		map <int, Song *> songs;
		string name;
		int time;
		int nsongs;
};

class Artist {
	public:
		map <string, Album *> albums;
		string name;
		int time;
		int nsongs;
};

int timeToInt(string time);
string convertUnderscores(string line);
string IntToTime(int time);

int main(int argc, char *argv[]){

	ifstream fin;
	fin.open(argv[1]); //open file
	string line, artistname, title,  artist, album, genre, stringtime;
	istringstream buffer;
	int time, track;
	Artist *newArtist;
	Album *newalbum;
	Song *newsong;
	map<string, Artist *> artistData;
	map<string, Artist *>::iterator it;
	map<string, Album *> albums;
	map<string, Album *>::iterator ait;
	//map<int, Song *> songs;
	map<int, Song *>::iterator sit;

	while (getline(fin, line)){
		buffer.clear();
		buffer.str(line);
		buffer >> title >> stringtime >> artistname >> album >> genre >> track;		
		title = convertUnderscores(title);
		album = convertUnderscores(album);
		time = timeToInt(stringtime);
		artistname = convertUnderscores(artistname);	


		it = artistData.find(artistname);
	if (it == artistData.end()){ //if not found
			newArtist = new Artist;
			newArtist->name = artistname;
			newArtist->time = 0;
			newArtist->nsongs = 0;
			artistData.insert(make_pair(artistname, newArtist));
		} else {
			newArtist = it->second;
		}

		ait = newArtist->albums.find(album);
		if (ait == albums.end()) {
			newalbum = new Album;
			newalbum->name = album;
			newalbum->time = 0;
			newalbum->nsongs = 0;
		newArtist->albums.insert(make_pair(album, newalbum));
		}else{
			newalbum = ait->second;	
		}
		
		newsong = new Song;
		newsong->title = title;
		newsong->track = track;
		newsong->time = time;

		newalbum->songs.insert(make_pair(track,newsong));
		newalbum->time += newsong->time;
		newArtist->time += newsong->time;
		newArtist->nsongs +=1;
		newalbum->nsongs +=1;
		
	}
	fin.close();
	

for(it = artistData.begin(); it != artistData.end(); it++) {
	printf("%s: %d, %s\n", it->first.c_str(), it->second->nsongs, IntToTime(it->second->time).c_str());

  for(ait = it->second->albums.begin(); ait != it->second->albums.end(); ait++) {

    printf("        %s: %d, %s\n", ait->first.c_str(), ait->second->nsongs, IntToTime(it->second->time).c_str());  

    for(sit = ait->second->songs.begin(); sit != ait->second->songs.end(); sit++) {

      printf("                %d. %s: %s\n", sit->first, sit->second->title.c_str(), IntToTime(sit->second->time).c_str());

    }

  }

} 
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


string IntToTime(int time) {
	int hour = time / 60;
	int min = time % 60;	
	string stringtime = to_string(hour) + ":" + to_string(min);
	return stringtime;
}
