```cpp
/*
 ID: dongliu3
 TASK: milk6
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000

// global variables
int N, M;
int a[1005], b[1005], c[1005];
int e[35][35], o[35][35], in[1005];
int original;
int ans, ansa[1005];
bool used[1005];

// functions
int networkflow() {

	int flow[100];
	bool vis[100];
	int pa[100];
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
			for (int i=1; i<=N; i++) if (e[maxloc][i]) {
				if (flow[i] < min(maxflow, e[maxloc][i])) {
					pa[i] = maxloc;
					flow[i] = min(maxflow, e[maxloc][i]);
				}
			}
		}

		if (maxloc == -1) break;
		pathcapacity = flow[N];
		totalflow += pathcapacity;

		currnode = N;
		while(currnode != src) {
			nextnode = pa[currnode];
			e[nextnode][currnode] -= pathcapacity;
			e[currnode][nextnode] += pathcapacity;
			currnode = nextnode;
		}
	}
	return totalflow;
}
bool ok() {
	int mark[35]; fill(mark, mark+N+1, 0);
	queue<int> Q; Q.push(1); mark[1] = 1;
	while(!Q.empty()) {
		int f = Q.front(); Q.pop();
		for (int i=1; i<=N; i++) if (!mark[i] && e[f][i]) {
			Q.push(i);
			mark[i] = 1;
		}
	}
	return (mark[N] == 0);
}
void dfs(int x, int y, int z) {
	if (y > original) return;
	if (x > in[0]) {
		if (z != original) return;
		for (int j=1; j<=N; j++) for (int k=1; k<=N; k++)
			e[j][k] = o[j][k];
		for (int j=1; j<=in[0]; j++) if (used[j]) {
			e[a[in[j]]][b[in[j]]] -= c[in[j]];
		}
		if (y<ans && ok()) {
			ans = y;
			for (int j=1; j<=in[0]; j++) ansa[j] = used[j];
		}
		return;
	}
	used[x] = true;  dfs(x+1, y+1, z+c[in[x]]);
	used[x] = false; dfs(x+1, y, z);
}
int main() {
	// local variables

	// fstream
	ifstream fin("milk6.in");
	ofstream fout("milk6.out");

	// input
	fin >> N >> M;
	for (int i=1; i<=M; i++) {
		fin >> a[i] >> b[i] >> c[i];
		e[a[i]][b[i]] += c[i], o[a[i]][b[i]] += c[i];
	}
	// main
	original = networkflow();
	int newsum = 0;
	for (int i=1; i<=M; i++) {
		for (int j=1; j<=N; j++) for (int k=1; k<=N; k++)
			e[j][k] = o[j][k];
		e[a[i]][b[i]] -= c[i];
		int newflow = networkflow();
		if (newflow < original) {
			in[++in[0]] = i;
			newsum += c[i];
		}
	}
	if (newsum == original) {
		fout << original << " " << in[0] << endl;
		for (int i=1; i<=in[0]; i++) fout << in[i] << endl;
		return 0;
	}
	ans = INF; dfs(1, 0, 0);

	// output
	fout << original << " " << ans << endl;
	for (int i=1; i<=in[0]; i++) if (ansa[i]) fout << in[i]<<endl;
	return 0;
}
```