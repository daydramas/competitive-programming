```cpp
/*
 ID: dongliu3
 TASK: holstein
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int V, G;
int v[30];
int g[20][30];
bool use[20];
int ans = 1000000000;
vector<int> ansv;
// functions
bool compV(vector<int> a, vector<int> b) {
	for (int i=0; i<a.size(); i++) {
		if (a[i] < b[i]) {
			return false;
		}
		if (b[i] < a[i]) {
			return true;
		}
	}
	return false;
}
void dfs(int gi) {
	if (gi == G+1) {
		vector<int> used;
		for (int i=1; i<=G; i++)
			if (use[i]) used.push_back(i);
		cout << endl;
		for (int i=1; i<=V; i++) {
			int sum = 0;
			for (int j : used) {
				sum += g[j][i];
			}
			if (sum < v[i]) return;
		}
		if (ans > used.size()) {
			ans = used.size();
			ansv = used;
		} else if (ans == used.size()) {
			if (compV(ansv, used)) {
				ansv = used;
			}
		}
		return;
	}
	dfs(gi+1);
	use[gi] = true;
	dfs(gi+1);
	use[gi] = false;
}
int main() {
	// local variables

	// fstream
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");

	// input
	fin >> V;
	for (int i=1; i<=V; i++) fin >> v[i];
	fin >> G;
	for (int i=1; i<=G; i++) {
		use[i] = false;
		for (int j=1; j<=V; j++) fin >> g[i][j];
	}
	// main
	dfs(1);
	// output
	fout << ans << " ";
	for (int i=0; i<ansv.size(); i++) {
		fout << ansv[i];
		if (i != ansv.size()-1) fout << " ";
	}
	fout << endl;
	return 0;
}
```