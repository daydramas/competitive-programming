#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>
#define x first
#define y second

//global variables
int X[] = {1, 1, -1, -1};
int Y[] = {-1, 1, 1, -1};
//functions

void solve() {
	int n, m; cin >> n >> m;
	int mark[200][200];
	for (int i=1; i<=n; i++)
	for (int j=1; j<=m; j++)
		mark[i][j] = 0;
	queue<pii> Q;
	if ((n*m)%2) { //odd
		mark[1][1] = 1;
		Q.push(pii(1, 1));
	} else { //even
		mark[1][1] = mark[1][2] = mark[2][1] = 1;
		Q.push(pii(1, 2));
		Q.push(pii(2, 1));
	}
	while(!Q.empty()) {
		pii f = Q.front(); Q.pop();
		for (int k=0; k<4; k++) {
			int nx = f.x+X[k], ny = f.y+Y[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (mark[nx][ny] == 0) {
					Q.push(pii(nx, ny));
					mark[nx][ny] = 1;
				}
			}
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (mark[i][j]) cout << 'B';
			else cout <<'W';
		}
		cout << endl;
	}
}
int main() {
	//local variables

	//input
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) solve();

	//main

	//output

	return 0;
}
