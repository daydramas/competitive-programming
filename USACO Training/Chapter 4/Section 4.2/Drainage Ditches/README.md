# Drainage Ditches
```cpp
/*
 ID: dongliu3
 TASK: ditch
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define x first
#define y second
#define MN 205
#define INF 1000000000

// global variables
int M, N;
int adj[MN][MN];
int pa[MN], flow[MN], vis[MN];

// functions

int main() {
	// local variables 

	// fstream
	ifstream fin("ditch.in");
	ofstream fout("ditch.out");

	// input
	fin >> M >> N;
	for (int i=1; i<=M; i++) {
		int a, b, c; fin >> a >> b >> c;
		adj[a][b] += c;
	}

	// main
	int src, maxflow, maxloc, pathcapacity, totalflow = 0, currnode, nextnode;

	while (true) {
		memset(flow, 0, sizeof(flow));
		memset(vis, false, sizeof(vis));
		memset(pa, -1, sizeof(pa));
		src = 1, flow[src] = INF;
		while (true) {
			maxflow = 0, maxloc = -1;
			for (int i=1; i<=N; i++) if (!vis[i] && flow[i]>maxflow)
				maxflow = flow[i], maxloc = i;
			if (maxloc == -1 || maxloc == N) break;
			vis[maxloc] = true;
			for (int i=1; i<=N; i++) if (adj[maxloc][i]) {
				if (flow[i] < min(maxflow, adj[maxloc][i])) {
					pa[i] = maxloc;
					flow[i] = min(maxflow, adj[maxloc][i]);
				}
			}
		}

		if (maxloc == -1) break;
		pathcapacity = flow[N];
		totalflow += pathcapacity;

		currnode = N;
		while(currnode != src) {
			nextnode = pa[currnode];
			adj[nextnode][currnode] -= pathcapacity;
			adj[currnode][nextnode] += pathcapacity;
			currnode = nextnode;
		}
	}
	// output
	fout << totalflow << endl;
	return 0;
}
```