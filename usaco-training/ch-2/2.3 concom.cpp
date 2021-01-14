/*
 ID: dongliu3
 TASK: concom
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
// global variables
int n;
vector<pii> own[101];
int owned[101];
bool mark[101];

// functions
void dfs(int a) {
	if (mark[a]) return;
	mark[a] = true;
	for (pii b : own[a]) {
		owned[b.first] += b.second;
		if (owned[b.first] >= 50) {
			dfs(b.first);
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("concom.in");
	ofstream fout("concom.out");

	// input
	fin >> n;
	for (int i=0; i<n; i++) {
		int a, b, c; fin >> a >> b >> c;
		own[a].push_back(pii(b, c));
	}
	// main & output
	for (int i=1; i<=100; i++) {
		fill(owned+1, owned+101, 0);
		fill(mark+1, mark+101, false);
		dfs(i);
		for (int j=1; j<=100; j++) {
			if (i!=j && owned[j] >= 50) fout << i << " " <<j <<endl;
		}
	}

	return 0;
}