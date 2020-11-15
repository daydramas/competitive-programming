# The Castle
```cpp
/*
 ID: dongliu3
 TASK: castle
 LANG: C++
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// structures/defines
#define pii pair<int, int>
#define pb push_back
#define MX 55
#define x first
#define y second
struct cell {
	int edges;
	pii parent; int sz;
	unordered_map<int, bool> wall;
	bool visited;
};
// global variables
int N, M;
cell castle[MX][MX];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
char D[] = {'S', 'E', 'N', 'W'};
int rooms, lrooms;
// functions
bool valid(pii a) {
	return (a.x >= 1 && a.x <= N && a.y >= 1 && a.y <= M);
}
int dfs1(pii src, pii pa) {
	castle[src.x][src.y].parent = pa;
	castle[src.x][src.y].sz = 1;
	castle[src.x][src.y].visited = true;
	for (int i=0; i<4; i++) {
		if (castle[src.x][src.y].wall[i]) continue;
		int x1 = src.x + X[i];
		int y1 = src.y + Y[i];
		if (pii(x1, y1) == pa || !valid(pii(x1, y1)) || castle[x1][y1].visited) continue;
		castle[src.x][src.y].sz += dfs1(pii(x1, y1), pa);
	}
	return castle[src.x][src.y].sz;
}
int main() {
	// local variables

	// fstream
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	// input
	fin >> M >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			int desNum; fin >> desNum;
			castle[i][j].wall[0] = false, castle[i][j].wall[1] = false, castle[i][j].wall[2] = false, castle[i][j].wall[3] = false;
			castle[i][j].edges = 0, castle[i][j].visited = false;
			if (desNum >= 8) {
				desNum -= 8;
				castle[i][j].edges++;
				castle[i][j].wall[0] = true;

			}
			if (desNum >= 4) {
				desNum -= 4;
				castle[i][j].edges++;
				castle[i][j].wall[1] = true;
			}
			if (desNum >= 2) {
				desNum -= 2;
				castle[i][j].edges++;
				castle[i][j].wall[2] = true;
			}
			if (desNum >= 1) {
				desNum -= 1;
				castle[i][j].edges++;
				castle[i][j].wall[3] = true;
			}
		}
	}
	// main
	rooms = 0; lrooms = 0;
	int ans1 = 0;
	pii ans = pii(0, N+1); char d = 'S';
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			if (castle[i][j].visited) continue;
			lrooms = max(lrooms, dfs1(pii(i, j), pii(i, j)));
			rooms++;
//			cout << rooms << " " << lrooms << endl;
		}
	}
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=1; k<3; k++) {

				if (!castle[i][j].wall[k]) continue;

				int nx = i+X[k];
				int ny = j+Y[k];
				if (!valid(pii(nx,ny))) continue;
				pii pa1 = castle[i][j].parent;
				pii pa2 = castle[nx][ny].parent;
				if (pa1 == pa2) {
					continue;
				}
				int sm = castle[pa1.x][pa1.y].sz+castle[pa2.x][pa2.y].sz;
				if (sm > ans1) {
					ans1 = sm;
					ans = pii(i, j);
					d = D[k];
				} else if (sm == ans1 && j < ans.y) {
					ans1 = sm;
					ans = pii(i, j);
					d = D[k];
				} else if (sm == ans1 && j == ans.y && i > ans.x) {
					ans1 = sm;
					ans = pii(i, j);
					d = D[k];
				} else if (sm == ans1 && j == ans.y && i == ans.x && d != 'N' && D[k] == 'N') {
					ans1 = sm;
					ans = pii(i, j);
					d = D[k];
				}

			}
		}
	}
	// output
	fout << rooms << endl << lrooms << endl<<ans1<< endl << ans.x << " " << ans.y<<" "<<d;
	fout << endl;
	return 0;
}
```