```cpp
/*
 ID: dongliu3
 TASK: milk
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
// global variables
int N, M;
vector<pii> sell;
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	// input
	fin >> N >> M;
	for (int i=0; i<M; i++) {
		int a, b; fin >> a >> b;
		sell.push_back(pii(a, b));
	}
	// main
	int cost = 0;
	sort(sell.begin(), sell.end());
	for (pii i : sell) {
		cost += min(N, i.second) * i.first;
		N -= min(N, i.second);
	}
	// output
	fout << cost << endl;
	return 0;
}
```