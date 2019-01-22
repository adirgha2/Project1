#include <iostream>
#include <map>
using namespace std;

struct Song { 
    string title;
    int time;
    int track;
		void printSong();
		string convertUnderscores(string line);
};

struct Album {
    map <int, Song > songs;
    string name;
    int time;
		void printSong();
};

struct Artist {
    map <string, Album > albums;
    void printArtist();
		string checkArtist(); //checks to see if Artist is in map
		string createArtist(); //creates an artist if nonexistent
		string name;
    int time;
    int nsongs;
};
