#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int n, k;
vector<int> adj[200005];
int sz[200005], dpt[200005];
int odr[200005];
int bus[200005];
long long ans = 0;
//functions
void dfs(int i, int pa) {
	sz[i] = 1;
	for (int j : adj[i]) {
		if (j == pa) continue;
		dpt[j] = dpt[i]+1;
		dfs(j, i);
		sz[i] += sz[j];
	}
}
bool cmp(int i, int j) {
	return (sz[i]-dpt[i]) < (sz[j]-dpt[j]);
}
void dfs2(int i, int pa, long long sum) {
	if (bus[i]) {
		ans += sum;
	} else {
		sum += 1;
	}
	for (int j : adj[i]) {
		if (j == pa) continue;
		dfs2(j, i, sum);
	}
}
int main() {
	//local variables

	//input
	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i=1; i<=n; i++) {
		sz[i] = 0, dpt[i] = 0;
	}
	//main
	dfs(1, -1);
	for (int i=1; i<=n; i++) odr[i] = i;
	sort(odr+1, odr+n+1, cmp);
	for (int i=1; i<=k; i++) {
		bus[odr[i]] = 1;
	}
	dfs2(1, -1, 0);
	//output
	cout << ans << endl;
	return 0;
}
