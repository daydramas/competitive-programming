```cpp
/*
 ID: dongliu3
 TASK: stall4
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N, M;
int W[210][210];
bool mark[210];
int p[210], p2[210];
int cnt = 0;

// functions
bool ok(int id) {
	if (mark[id]) return 0;
	mark[id] = true;
	for (int i=1; i<=N; i++) {
		if (W[i][id] && (p[i]==-1 || ok(p[i]))) {
			p[i] = id;
			p2[id] = i;
			return 1;
		}
	}
	return 0;
}
int main() {
	// local variables

	// fstream
	ifstream fin("stall4.in");
	ofstream fout("stall4.out");

	// input
	fin >> N >> M;
	for (int i=1; i<=N; i++) {
		int sz; fin >> sz;
		for (int j=1; j<=sz; j++) {
			int a; fin >> a;
			W[i][a] = 1;
		}
	}
	// main
	memset(p, -1, sizeof(p)); // cow to stall
	memset(p2, -1, sizeof(p2)); // stall to cow
	for (int i=1; i<=M; i++) if (p2[i] == -1) {
		memset(mark, false, sizeof(mark));
		cnt += ok(i);
	}
	// output
	fout << cnt << endl;
	return 0;
}
```