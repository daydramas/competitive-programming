# cownav
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define MN 21
struct node {
	string moves;
	int move, lx, ly, rx, ry, ld, rd;
	node(string moves, int move, int lx, int ly, int rx, int ry, int ld, int rd) :
			moves(moves), move(move), lx(lx), ly(ly), rx(rx), ry(ry), ld(ld), rd(
					rd) {
	}
};
// global variables
int N;
bool barn[MN][MN];
int dp[MN][MN][MN][MN][4][4];
int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };
//functions
bool outOfPosition(int x, int y) {
	return (x > N || x < 1 || y > N || y < 1);
}
void getNext(int *x, int *y, int d) {
	if (*x == N && *y == N) {
		return;
	}
	int nx = *x + X[d];
	int ny = *y + Y[d];
//	cout << "nx: " << nx << " ny: " << ny << endl;
	if (!barn[nx][ny] || outOfPosition(nx, ny)) {
		nx = *x, ny = *y;
	}
	*x = nx, *y = ny;
}
int main() {
	// local variables

	// fstream
	ifstream fin("cownav.in");
	ofstream fout("cownav.out");

	// input
	fin >> N;
	for (int i = N; i >= 1; i--) {
		string str;
		fin >> str;
//		cout << str << endl;
		for (int j = 1; j <= N; j++) {
			barn[i][j] = (str[j - 1] == 'E');
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							dp[i][j][k][l][m][n] = -1;
						}
					}
				}
			}
		}
	}
	// main
//	int a = 2, b = 2;
//	getNext(&a, &b, 3);
//	cout << "getNext(2, 2, 3) = " << a << " " << b << endl;
	dp[1][1][1][1][0][1] = 0;
	queue<node> Q;
	Q.push(node("", 0, 1, 1, 1, 1, 0, 1));
	int ans = 1000000001;
	while (!Q.empty()) {
		node f = Q.front();
		Q.pop();

//		if (f.moves == "FRFFLFFF") {
//			cout << f.move << endl;
//		}

		if (f.lx == N && f.rx == N && f.ly == N && f.ry == N) {
			ans = min(ans, dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd]);
			cout << dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd] << " " << f.moves
					<< endl;
		}
		int ta = dp[f.lx][f.ly][f.rx][f.ry][f.ld][f.rd] + 1;
		int lx, rx, ly, ry, ld, rd, nm = f.move + 1;
		//left
		ld = (f.ld + 1) % 4, rd = (f.rd + 1) % 4;
		if (-1 == dp[f.lx][f.ly][f.rx][f.ry][ld][rd]) {
			dp[f.lx][f.ly][f.rx][f.ry][ld][rd] = ta;
			Q.push(node(f.moves + "L", ta, f.lx, f.ly, f.rx, f.ry, ld, rd));
		}
		//right
		ld = (f.ld + 3) % 4, rd = (f.rd + 3) % 4;
		if (-1 == dp[f.lx][f.ly][f.rx][f.ry][ld][rd]) {
			dp[f.lx][f.ly][f.rx][f.ry][ld][rd] = ta;
			Q.push(node(f.moves + "R", ta, f.lx, f.ly, f.rx, f.ry, ld, rd));
		}
		//forward
		lx = f.lx, rx = f.rx, ly = f.ly, ry = f.ry, ld = f.ld, rd = f.rd;
		getNext(&lx, &ly, ld);
		getNext(&rx, &ry, rd);
		if (-1 == dp[lx][ly][rx][ry][ld][rd]) {
			dp[lx][ly][rx][ry][ld][rd] = ta;
			Q.push(node(f.moves + "F", ta, lx, ly, rx, ry, ld, rd));
		}
	}
// output
	fout << ans << endl;
	return 0;
}

```