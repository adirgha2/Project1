
/* Ananya Dirghangi
 * Challenge 01: Rotating Arrays
 * 01/18/2019
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {

	istringstream line1,line2;
	string line;

	while(getline(cin,line)){
		line1.str(line);
		int numelems, numrots;
		char direction;

		line1 >> numelems >> numrots >> direction; //reads in first line

		line1.clear();

		getline(cin, line); 
		line2.str(line);
		vector<int> arr;
		arr.resize(numelems); //resizes array according to the number of elements in the second line

		for(int i = 0; i < numelems; i++){  
			line2 >> arr[i]; //stores values of array
		}

		line2.clear();

		if(direction == 'L'){
			for(int j = 0; j < numrots; j++){ //left rotation
				rotate(arr.begin(), arr.begin()+1, arr.end());
			}
		}else if(direction == 'R'){
			for(int k = 0; k < numrots; k++){
				rotate(arr.begin(), arr.end()-1, arr.end()); //right rotation
			}

		}

		for(unsigned int l = 0 ; l < arr.size(); l++){ //outputs rotated array
			cout << arr[l];
			if(l != (arr.size()-1)){
				cout << " ";
			}
		}

		cout << endl;
	}

	return 0;
}

