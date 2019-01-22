#include <iostream>
#include <map>
using namespace std;

<<<<<<< HEAD
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
};

class Artist {
  public:
    map <string, Album *> albums;
    string name;
=======
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
>>>>>>> 68db9f591d4b6be505438fd147646beeb67d1342
    int time;
    int nsongs;
};
