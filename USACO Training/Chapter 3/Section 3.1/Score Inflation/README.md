```cpp
/*
 ID: dongliu3
 TASK: inflate
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MAXN (int) 1e4+5
#define pii pair<int, int>

// global variables
int M, N;
int D[MAXN];
pii Q[MAXN];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");

	// input
	fin >> M >> N;
	for (int i=1; i<=N; i++) fin >> Q[i].first >> Q[i].second;
	for (int i=0; i<=M; i++) D[i] = 0;

	// main
	for (int i=0; i<=M; i++)
	for (int j=1; j<=N; j++)
		if (i+Q[j].second <= M) D[i+Q[j].second] = max(D[i+Q[j].second], D[i]+Q[j].first);

	// output
	int ans = 0;
	for (int i=0; i<=M; i++) ans = max(ans, D[i]);
	fout << ans << endl;
	return 0;
}
```