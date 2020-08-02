  
/*
 ID: dongliu3
 TASK: maze1
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define x first
#define y second

// global variables
int N, M;
string grid[220];
int dist[220][80];
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

// functions
bool valid(int i, int j) {
	return (i>=0 && i<=N && j>=0 && j<=M);
}
void dfs(int i, int j, int d) {
	if (d >= dist[i][j]) return;
	dist[i][j] = d;
	for (int k=0; k<4; k++) {
		int nx = i+X[k], ny = j+Y[k];
		if (grid[nx][ny] == ' ' && valid(nx+X[k], ny+Y[k]))
			dfs(nx+X[k], ny+Y[k], d+1);
	}
}
int main() {
	// local variables
	vector<pii> start;

	// fstream
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	// input
	fin >> M >> N; M *= 2; N *= 2;
	getline(fin, grid[0]);
	for (int i=0; i<=N; i++) getline(fin, grid[i]);
	for (int i=1; i<=N; i+=2) for (int j=1; j<=M; j+=2)
		dist[i][j] = 100000000;
	for (int i=0; i<=N; i++) {
		if (grid[i][0] == ' ') start.push_back(pii(i, 1));
		if (grid[i][M] == ' ') start.push_back(pii(i, M-1));
	}
	for (int j=0; j<=M; j++) {
		if (grid[0][j] == ' ') start.push_back(pii(1, j));
		if (grid[N][j] == ' ') start.push_back(pii(N-1, j));
	}
	// main
	for (pii s : start) dfs(s.x, s.y, 1);

	// output
	int cnt = 0;
	for (int i=1; i<=N; i+=2) for (int j=1; j<=M; j+=2)
		cnt = max(cnt, dist[i][j]);

	fout << cnt << endl;
	return 0;
}