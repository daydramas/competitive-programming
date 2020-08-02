/*
 ID: dongliu3
 TASK: barn1
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int M, S, C;
vector<int> stall;
int cnt = 0;
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	// input
	fin >> M >> S >> C;
	for (int i=1; i<=C; i++) {
		int x; fin >> x;
		stall.push_back(x);
	}
	// main
	sort(stall.begin(), stall.end());
	for (int i=0; i<C; i++) {
		stall[i] = stall[i+1]-stall[i]-1;
	}
	stall.pop_back();
	sort(stall.begin(), stall.end());
	cnt = C;
	for (int i=0; i<(C-M); i++) {
		cnt += stall[i];
	}
	// output
	fout << cnt << endl;
	return 0;
}