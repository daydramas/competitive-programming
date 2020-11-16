# Raucous Rockers
```cpp
/*
 ID: dongliu3
 TASK: rockers
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000

// global variables
int N, T, M;
int L[30], ans = 0;

// functions
void dfs(int i, int song, int done, int curr) {
	if (done > M || curr > T) return;
	if (i == N+1) {
		ans = max(ans, song);
		return;
	}
	dfs(i+1, song, done, curr);
	if (L[i] + curr <= T) dfs(i+1, song+1, done, curr+L[i]);
	else dfs(i+1, song+1, done+1, L[i]);
}
int main() {
	// local variables

	// fstream
	ifstream fin("rockers.in");
	ofstream fout("rockers.out");

	// input
	fin >> N >> T >> M;
	for (int i=1; i<=N; i++) fin >> L[i];

	// main
	dfs(1, 0, 1, 0);

	// output
	fout << ans << endl;

	return 0;
}
```