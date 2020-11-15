```cpp
  
/*
 ID: dongliu3
 TASK: gift1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// define/structures

// global variables
int N;
string names[10];
int money[10];
map<string, int> idx;
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	// input
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> names[i];
		idx[names[i]] = i;
		money[i] = 0;
	}
	// main
	for(int i=0; i<N; i++) {
		string giver; fin >> giver;
		int amount, people; fin >> amount >> people;
		int amount_recieved;
		if(people == 0) amount_recieved = 0;
		else amount_recieved = amount/people;
		money[idx[giver]] -= amount_recieved * people;
		for(int j=0; j<people; j++) {
			string reciever; fin >> reciever;
			money[idx[reciever]] += amount_recieved;
		}
	}
	// output

	for(int i=0; i<N; i++) {
		fout << names[i] << " " << money[i] << endl;
	}
	return 0;
}
```