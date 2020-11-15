```cpp
/*
 ID: dongliu3
 TASK: runround
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
long int N;

// functions
bool work(long int M) {
	map<char, long int> mark;
	string sM = to_string(M);
	long int index = 0;
	map <char, bool> yes;
	for (long int i=0; i<sM.size(); i++) {
		if (yes[sM[i]]) return false;
		if (sM[i] == '0') {
			return false;
		}
		yes[sM[i]] = true;
	}
	while(true) {
		mark[sM[index]]++;
		if (mark[sM[index]] == 2) {
			return false;
		}
		index = (index + (sM[index]-'0'))%sM.size();
		bool check = true;
		for (long int i=0; i<sM.size(); i++) {
			char ch = sM[i];
			if (mark[ch] != 1) {
				check = false;
				break;
			}
		}
		if (check && index == 0) break;
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("runround.in");
	ofstream fout("runround.out");

	// input
	fin >> N;
	// main
	N++;
	while(!work(N)) {
		N++;
	}
	// output
	fout << N << endl;
	return 0;
}
```