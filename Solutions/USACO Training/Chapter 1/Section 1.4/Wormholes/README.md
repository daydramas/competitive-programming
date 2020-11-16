# Wormholes
```cpp
/*
 ID: dongliu3
 TASK: wormhole
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int x[15], y[15];
int nright[15], partner[15];
// functions
bool cycle() {
	for (int start = 1; start <= N; start++) {
		int pos = start;
		for (int count = 0; count < N; count++)
			pos = nright[partner[pos]];
		if (pos != 0)
			return true;
	}
	return false;
}

int solve() {
	int i=1, total = 0;
	while(i <= N && partner[i]!=0) i++;
	if (i > N) { // all paired
		if (cycle()) // check cycle
			return 1;
		else
			return 0;
	}

	for (int j = i + 1; j <= N; j++) // try pairing
		if (partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;
		}
	return total;
}
int main() {
	// local variables

	// fstream
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	// input
	fin >> N;
	for (int i = 1; i <= N; i++) {
		fin >> x[i] >> y[i];
		nright[i] = 0, partner[i] = 0;
	}
	// main
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (x[j] > x[i] && y[i] == y[j]
					&& (nright[i] == 0 || x[j] < x[nright[i]])) {
				nright[i] = j;
			}
		}
	}
	// output
	fout << solve() << endl;
	return 0;
}
```