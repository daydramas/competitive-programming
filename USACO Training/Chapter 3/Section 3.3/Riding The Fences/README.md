# Riding The Fences
```cpp
/*
 ID: dongliu3
 TASK: fence
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int F;
vector<int> E[510];
int D[510];
int circuit[810], cindex;

// functions
void find_circuit(int src) {
	while(!E[src].empty()) {
		int d = E[src].back();
		E[src].pop_back();
		E[d].erase(find(E[d].begin(), E[d].end(), src));
		find_circuit(d);
	}
	circuit[cindex++] = src;
}
bool comp(int i, int j) { return (i>j); }
int main() {
	// local variables

	// fstream
	ifstream fin("fence.in");
	ofstream fout("fence.out");

	// input
	fin >> F;
	memset(D, 0, sizeof(D));
	for (int i=1; i<=F; i++) {
		int a, b; fin >> a >> b;
		D[a]++, D[b]++;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	// main
	int start = 501;
	for (int i=1; i<=500; i++) if (D[i]%2) start = min(start, i);
	for (int i=1; i<=500; i++) sort(E[i].begin(), E[i].end(), comp);
	if (start == 501) start = 1;
	cindex = 1; find_circuit(start);

	// output
	fout << start << endl;
	for (int i=F; i>=1; i--) fout << circuit[i] << endl;
	return 0;
}
```