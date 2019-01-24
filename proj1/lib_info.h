#include <iostream>
#include <map>
using namespace std;

struct Song { 
	public:
		string title;
		int time;
		int track;
};

struct Album {
	public:
		map <int, Song *> songs;
		string name;
		int time;
		int nsongs;
};

struct Artist {
	public:
		map <string, Album *> albums;
		string name;
		int time;
		int nsongs;
};

