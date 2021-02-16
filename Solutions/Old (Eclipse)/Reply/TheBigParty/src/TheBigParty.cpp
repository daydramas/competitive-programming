#include <bits/stdc++.h>
using namespace std;

// structures and defines
#define pii pair<int, int>
#define ppb pair<pii, bool>
#define MAXN 1000000000

// global variables
ifstream fin ("input.in");

// functions
void solve(int t) {

	int N, M, X, C[1000];
	vector<pii> adj[1000];

	int dist[1000][101][2];

	fin >> N >> M >> X;
	for (int i=0; i<N; i++) fin >> C[i];
	for (int i=0; i<M; i++) {
		int a, b, c; fin >> a >> b >> c;
		adj[a].push_back(pii(b, c));
		adj[b].push_back(pii(a, c));
	}

	for (int i=0; i<N; i++) for (int j=0; j<=X; j++)
		dist[i][j][0] = dist[i][j][1] = MAXN;

	dist[0][0][0] = 0;
	queue<ppb> Q; Q.push(ppb(pii(0, 0), false));
	while(!Q.empty()) {
		ppb F = Q.front(); Q.pop();
		pii f = F.first;
		if (f.second < X && !F.second && dist[f.first][f.second][0]+C[f.first] < dist[f.first][f.second+1][1]) {
			dist[f.first][f.second+1][1] = dist[f.first][f.second][0]+C[f.first];
			Q.push(ppb(pii(f.first, f.second+1), true));
		}
		// visit
		for (pii d : adj[f.first]) {
			int nd = dist[f.first][f.second][F.second] + d.second;
			if (nd < dist[d.first][f.second][0]) {
				dist[d.first][f.second][0] = nd;
				Q.push(ppb(pii(d.first, f.second), false));
			}
		}

	}
	cout<<"Case #"<<t<<": " << min(dist[0][X][0], dist[0][X][1]) << endl;
}
int main() {
	// local variables
	int T;

	// input
	fin >> T;

	// main
	for (int i=1; i<=T; i++) {
		solve(i);
	}

	// output

	return 0;
}