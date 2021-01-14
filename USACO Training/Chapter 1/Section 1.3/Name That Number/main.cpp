/*
 ID: dongliu3
 TASK: namenum
 LANG: C++
 */

#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;

// structures/defines

// global variables
string N;
string alpha = "ABCDEFGHIJKLMNOPRSTUVWXY";
vector<char> letter[10];
//map<string, bool> names;
string names[4618];
vector<string> foutarr;
// functions
int binarySearch(int p, int r, string num) {
   int lower = p;
   int upper = r;
   while (lower <= upper) {
	  int mid = lower + (upper - lower) / 2;
	  int res = -1;
	  if (num == (names[mid]))
		 res = 0;
	  if (res == 0)
		 return mid;
	  if (num > (names[mid]))
		 lower = mid + 1;
	  else
		 upper = mid - 1;
   }
   return -1;
}
void dfs(int in, string curr) {
	if (in == N.size()) {
		if (binarySearch(0, 4616, curr) != -1) {
			foutarr.push_back(curr);
		}
	}
	for (char i : letter[(N[in] - '0')]) {
		dfs(in+1, curr + i);
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream fin2("dict.txt");
	// input
	fin >> N;
	int alphaIN = 0;
	for (int i=2; i<=9; i++) {
		for (int j=0; j<3; j++) {
			letter[i].push_back(alpha[alphaIN++]);
		}
	}
	for (int i=0; i<4617; i++) {
		string str; fin2 >> str;
		names[i] = str;
	}
	// main
	dfs(0, "");
	// output
	for (string str : foutarr) {
		fout << str << endl;
	}
	if (foutarr.empty()) {
		fout << "NONE"<<endl;
	}
	return 0;
}