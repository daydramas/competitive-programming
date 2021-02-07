#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines
struct edge {
	int b, f, c;
	edge(int b, int f, int c) : b(b), f(f), c(c) {}
};
#define Pair pair<int, int>
#define node pair<int, Pair>
// global variables
int N, M;
vector<edge> edges[1001];
int dp[1001][1001];
long long ans = 0;
//functions
void spath() {
	dp[1][1000] = 0;
	priority_queue<node, vector<node>, greater<node> > Q;
	Q.push(node(0, Pair(1, 1000)));
	while(!Q.empty()) {
		int src = Q.top().second.first;
		int cost = Q.top().first;
		int flow = Q.top().second.second;
		Q.pop();
//		cout << src << " : "<<cost<<" "<<flow<<endl;
		if(src == N) {
			ans = max(ans,
					(long long)(flow*(1000000)/ (double)cost));

		}
		for(edge e : edges[src]) {
			int dest = e.b;
			int nflow = min(flow, e.f);
			int ncost = dp[src][flow] + e.c;
			if(dp[dest][nflow]>ncost || dp[dest][nflow] == 0) {
				dp[dest][nflow] = ncost;
				Q.push(node(ncost, Pair(dest, nflow)));
			}
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("pump.in");
	ofstream fout("pump.out");

	// input
	fin >> N >> M;
	for(int i=1; i<=M; i++) {
		int a,b,f,c; fin >> a >> b >> c >> f;
		edges[a].push_back(edge(b, f, c));
		edges[b].push_back(edge(a, f, c));
	}

	// main
	spath();

	// output
	fout << ans << endl;
	return 0;
}
