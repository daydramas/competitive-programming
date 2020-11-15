# Fence Loops
```cpp
/*
 ID: dongliu3
 TASK: fence6
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define MN 105
#define INF 1000000000
#define f first
#define s second
struct segment {
	int s, l, n[2];
	int N[10][2];
};

// global variables
int N;
int id[MN][2], e[MN][MN];
vector<pii> adj[MN*2];
int v[MN*2];
int ans;

// functions
void createEdge(int a, int b, int l) {
	adj[a].push_back(pii(b, l));
	adj[b].push_back(pii(a, l));
}
void dfs(int usrc, int src, int pa, int length) {
	if (length > ans) return;
	if (src == usrc && length != 0) {
		ans = min(ans, length);
		return;
	}
	for (pii dest : adj[src]) if (dest.first != pa && !v[dest.first]) {
		v[dest.first] = true;
		dfs(usrc, dest.first, src, length+dest.second);
		v[dest.first] = false;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("fence6.in");
	ofstream fout("fence6.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) id[i][0] = (i*2-1), id[i][1] = (i*2);

	for (int i=1; i<=N; i++)
	for (int j=1; j<=N; j++) e[i][j] = -1;

	for (int i=1; i<=N; i++) {
		int a, l, n[2], b;
		fin >> a >> l >> n[0] >> n[1];
		createEdge(id[a][0], id[a][1], l);
		for (int k=0; k<2; k++) for (int j=1; j<=n[k]; j++) {
			fin >> b;
			e[a][b] = k;
			if (e[b][a] != -1) createEdge(id[b][e[b][a]], id[a][k], 0);
		}
	}
	// main
	ans = INF;
	for (int i=1; i<=2*N; i++) {
		memset(v, false, sizeof(v));
		dfs(i, i, -1, 0);
	}

	// output
	fout << ans << endl;
	return 0;
}
```