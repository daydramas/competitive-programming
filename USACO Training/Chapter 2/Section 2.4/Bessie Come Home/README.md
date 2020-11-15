```cpp
/*
 ID: dongliu3
 TASK: comehome
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define INF 1000000000

// global variables
int P;
vector<pii> adj[60];
int dist[60];

// functions
int getID(char ch) {
	if (islower(ch)) {
		return ch - 'a';
	}
	return ch - 'A' + 26;
}
int main() {
	// local variables

	// fstream
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	// input
	fin >> P;
	for (int i = 0; i < P; i++) {
		char a, b;
		int d;
		fin >> a >> b >> d;
		int a2 = getID(a), b2 = getID(b);
		adj[a2].push_back(pii(b2, d));
		adj[b2].push_back(pii(a2, d));
	}
	for (int i = 0; i < 52; i++) {
		dist[i] = INF;
	}
	// main
	queue<int> Q;
	Q.push(51);
	dist[51] = 0;
	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		for (pii d : adj[f]) {
			int nd = dist[f] + d.second;
			if (nd < dist[d.first]) {
				dist[d.first] = nd;
				Q.push(d.first);
			}
		}
	}
	// output
	int ans = INF;
	char ansc;
	for (int i = 26; i < 51; i++) {
		if (dist[i] < ans) {
			ans = dist[i];
			ansc = 65 + (i-26);
		}
	}
	fout<< ansc << " " << ans << endl;
	return 0;
}
```