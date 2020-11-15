# Sweet Butter
```cpp
/*
 ID: dongliu3
 TASK: butter
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000
#define pii pair<int, int>

// global variables
int N, P, C;
int cow[501];
int dist[801][801], e[801][801];
bool mark[801];
vector<pii> adj2[801];

// functions
void bellmanFord(int src) {
	dist[src][src] = 0;
	queue<int> Q; Q.push(src);
	fill(mark, mark+801, false);
	while(!Q.empty()){
		int f = Q.front(); Q.pop();
		for (pii j : adj2[f]) if (dist[src][j.first] > dist[src][f]+j.second) {
			dist[src][j.first] = dist[src][f]+j.second;
			if (!mark[j.first]) {
				Q.push(j.first);
				mark[j.first] = true;
			}
		}
		mark[f] = false;
	}

}
int main() {
	// local variables

	// fstream
	ifstream fin("butter.in");
	ofstream fout("butter.out");

	// input
	fin >> N >> P >> C;
	for (int i=1; i<=P; i++) for (int j=1; j<=P; j++)
		dist[i][j] = INF;
	for (int i=1; i<=P; i++) dist[i][i] = 0;
	for (int i=1; i<=N; i++) fin >> cow[i];
	for (int i=1; i<=C; i++) {
		int a, b, c; fin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
		adj2[a].push_back(pii(b, c));
		adj2[b].push_back(pii(a, c));
	}

	// main
	for (int i=1; i<=P; i++)
		bellmanFord(i);

	// output
	int ans = INF;
	for (int i=1; i<=P; i++) {
		int sum = 0;
		for (int j=1; j<=N; j++) sum += dist[i][cow[j]];
		ans = min(ans, sum);
	}
	fout << ans << endl;
	return 0;
}
```