# The Tamworth Two
```cpp
  
/*
 ID: dongliu3
 TASK: ttwo
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define x first
#define y second

struct state {
	pii fj, cw; int fjd, cwd;
	state(pii fj, pii cw, int fjd, int cwd) : fj(fj), cw(cw), fjd(fjd), cwd(cwd) {}
};
// global variables
string grid[10];
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};
bool visited[10][10][10][10][4][4];
// functions
bool valid(int i, int j) {
	return (i>=0 && i<10 && j>=0 && j<10 && grid[i][j]!='*');
}
int main() {
	// local variables
	pii C, F;
	// fstream
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	// input
	for (int i=0; i<10; i++) fin >> grid[i];
	for (int i=0; i<10; i++) for (int j=0; j<10; j++) {
		if (grid[i][j] == 'C') C = pii(i, j);
		else if (grid[i][j] == 'F') F = pii(i, j);
	}
	memset(visited, false, sizeof(visited));
	// main
	state S = state(F, C, 0, 0);
	int cnt = 0;
	while(S.fj != S.cw) {
		int nx, ny;
		if (visited[S.fj.x][S.fj.y][S.cw.x][S.cw.y][S.fjd][S.cwd]){
			break;
		}
		visited[S.fj.x][S.fj.y][S.cw.x][S.cw.y][S.fjd][S.cwd] = true;
		//fj
		nx = S.fj.x + X[S.fjd], ny = S.fj.y + Y[S.fjd];
		if (valid(nx, ny)) {
			S.fj = pii(nx, ny);
		} else {
			S.fjd = (S.fjd+1)%4;
		}
		//cw
		nx = S.cw.x + X[S.cwd], ny = S.cw.y + Y[S.cwd];
		if (valid(nx, ny)) {
			S.cw = pii(nx, ny);
		} else {
			S.cwd = (S.cwd+1)%4;
		}
		cnt++;
	}
	// output
	if (S.fj == S.cw) fout << cnt << endl;
	else fout << "0" << endl;
	return 0;
}
```