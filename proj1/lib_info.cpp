#include <iostream>
#include "lib_info.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int timeToInt(string time);
string convertUnderscores(string line);
string IntToTime(int time);

int main(int argc, char *argv[]){

	ifstream fin;
	fin.open(argv[1]);
	string line, name, title,  artist, album, genre;
	istringstream buffer;
	string stringtime;
	int time, track;
	map<string, Artist *> artistData;
	map<string, Artist *>::iterator it;
	map<string, Album *> albums;
	map<string, Album *>::iterator ait;
	map<int, Song *> songs;
	map<int, Song *>::iterator sit;

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

		Artist *newArtist = new Artist;
		newArtist->name = name;
		newArtist->time = time;

		it = artistData.find(name);
		if (it  == artistData.end()){
			artistData[name] = newArtist;
//			artistData.insert(make_pair(name, newArtist));
		//	cout << "New artist: " << name<< endl;

		} else {
		//	cout << "Old Artist: "<< name << endl;
		}

		Album *newalbum = new Album;
		newalbum->name = album;
		newalbum->time = 0;

		ait = albums.find(album);
		if (ait == albums.end()) {
			albums[album] = newalbum;
		//albums.insert(make_pair(album, newalbum));
			//cout << "newalbum: "<< album << endl;
		}else{
			//cout << "oldalbum: " << album << endl;
		}
	
	sit = songs.find(track);
	if (sit == songs.end()) {
		songs[newsong->track] = newsong;
	}
	}
	

	for (it = artistData.begin(); it != artistData.end(); it++){
		for (ait = albums.begin(); ait != albums.begin(); ait++) {
			cout<< it->second->name <<endl;
			cout << ait->second->name  << endl;
		}
	}
	cout << "end";
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


string IntToTime(int time) {
	int hour = time / 60;
	int min = time % 60;	
	string stringtime = to_string(hour) + ":" + to_string(min);
	return stringtime;
}
