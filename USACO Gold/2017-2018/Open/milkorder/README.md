# milkorder
```cpp
#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define Pair pair<int, int>
// global variables
int N, M;
vector<Pair> observation[50000];
vector<int> after[100000];
int before[100000],
answer[100000];
//functions
bool ok(int X) {
	for (int i = 0; i < N; i++) {
		after[i].clear();
		before[i] = 0;
	}
	for (int i = 0; i <= X; i++) {
		for (Pair o : observation[i]) {
			after[o.first].push_back(o.second);
			before[o.second]++;
		}
	}
	priority_queue<int, vector<int>, greater<int> > Q;
	for (int i = 0; i < N; i++) {
		if (before[i] == 0) {
			Q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (Q.empty()) {
			return false;
		}
		int t = Q.top();
		Q.pop();
		answer[i] = t;
		for (int a : after[t]) {
			before[a]--;
			if (!before[a]) {
				Q.push(a);
			}
		}
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	// input
	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		int m;
		fin >> m;
		int px = -1;
		for (int j = 0; j < m; j++) {
			int x;
			fin >> x;
			x--;
			if (j) {
				observation[i].push_back(Pair(px, x));
			}
			px = x;
		}
	}
	// main
	int s = 0, b = M - 1, X = -1;
	while (s + 1 < b) {
		int m = (s + b) / 2;
		if (ok(m)) {
			X = m;
			s = m;
		} else {
			b = m;
		}
	}
	ok(s);

	// output
	for (int i = 0; i < N; i++) {
		fout << ++answer[i];
		if(i < N-1) fout << " ";
		else fout << endl;
	}
	return 0;
}

```