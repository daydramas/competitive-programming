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

// global variables
int N, K;
vector<int> adj[100001];
int depth[100001][3];
int cnt = 0;
//functions
void dfs1(int src, int pa) {
	depth[src][1] = depth[pa][1] + 1;
	if (adj[src].size() > 1) {
		for (int dest : adj[src]) {
			if (dest != pa) {
				dfs1(dest, src);
//				cout <<"depth[" << src<<"] = min ("<<depth[dest][2]+1<<", "<<depth[src][2]<<");"<<endl;
				depth[src][2] = min(depth[src][2], depth[dest][2] + 1);
//				cout <<"depth[" << src<<"] = min ("<<depth[dest][2]+1<<", "<<depth[src][2]<<endl;
			}
		}
	} else {
//		cout <<"size:" << adj[src].size() << ", "<<src << endl;
		depth[src][2] = 0;
	}
}
void dfs2(int src, int pa) {
	if (src != K)
		depth[src][2] = min(depth[src][2], depth[pa][2] + 1);
	for (int dest : adj[src]) {
		if (dest != pa) {
			dfs2(dest, src);
		}
	}
}
void dfs3(int src, int pa) {
	if ((depth[src][1] >= depth[src][2]) && (depth[pa][1] < depth[pa][2])) {
		cnt++;
	}
	for (int dest : adj[src]) {
		if (dest != pa) {
			dfs3(dest, src);
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("atlarge.in");
	ofstream fout("atlarge.out");

	// input
	fin >> N >> K;
	for (int i = 1; i < N; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		depth[i][1] = -1;
		depth[i][2] = 1000000000;
	}
	depth[0][1] = -1;
	depth[0][2] = -1;

	// main
	if (adj[K].size() == 1)
		cnt = 1;
	else {
		dfs1(K, 0);
		dfs2(K, 0);
		dfs3(K, 0);
	}
//	for(int i=1; i<=N; i++) {
//		cout << depth[i][1] << " " << depth[i][2] << endl;
//	}
	// output
	fout << cnt << endl;
	return 0;
}
