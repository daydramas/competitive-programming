/*
============================================================================
 Name:		Longest Path
 Link:		https://atcoder.jp/contests/dp/tasks/dp_g
 Author:	Dong Liu
 Date:		2021-02-06
============================================================================
 * first run toposort on the graph
 * dp[i] = max length of path ending at i
 * Transitions:
 	* dp[j] = max(dp[j], dp[i]+1);
	* ^ if there's an edge (i -> j) 
 * Answer: max(dp[i])
*/

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

#define F			first
#define S			second
#define PB			push_back
#define ALL(x)		begin(x), end(x)
#define SZ(x)		int((x).size())
#define F0R(i,a)	for(int i=0; i<(a); i++)
#define FOR(i,a,b)	for(int i=(a); i<=(b); i++)
#define R0F(i,a)	for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b)	for(int i=(b); i>=(a); i--)
#define EACH(a,x)	for (auto& a: x)

struct TopoSort {
	int N; vector<int> weight;
	vector<vector<int>> graph; 
	TopoSort(int N = 0) : N(N), weight(N+1), graph(N+1) {}
	void addEdge(int a, int b) {
		graph[a].push_back(b); 
		weight[b]++;
	}
	vector<int> sort(int N) {
		queue<int> q; vector<int> res;
		for(int i=1; i<=N; i++) if(!weight[i]) q.push(i);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			res.push_back(x);
			for(int y : graph[x]) if(!--weight[y]) q.push(y);
		}
		return res;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;

	TopoSort graph(n);
	while(m--) {
		int a, b; cin >> a >> b;
		graph.addEdge(a, b);
	}
	vector<int> ord = graph.sort(n);
	vector<int> dp(n+1);
	int ans = 0;
	EACH(x, ord) EACH(y, graph.graph[x]) {
		dp[y] = max(dp[y], dp[x] + 1);
		ans = max(ans, dp[y]);
	}
	cout << ans << '\n';
}