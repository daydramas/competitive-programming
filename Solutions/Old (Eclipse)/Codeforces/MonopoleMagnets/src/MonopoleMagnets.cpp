#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables
int n, m;
bool c[1005][1005];
bool b[1005][1005];
bool w[1005][1005];
bool v[1005][1005];
int X[] = {0, 0, -1, 1};
int Y[] = {1, -1, 0, 0};
//functions
void dfs(int a, int b) {
	v[a][b] = 1;
	bool CLR = 0;
	for (int i=a+1; i<=n; i++) {
		if (!w[i][b]) CLR = 1;
		if (CLR) {
			w[i][b] = 0;
		}
	}
	CLR = 0;
	for (int i=a-1; i>=1; i--) {
		if (!w[i][b]) CLR = 1;
		if (CLR) {
			w[i][b] = 0;
		}
	}
	CLR = 0;
	for (int i=b+1; i<=m; i++) {
		if (i!=b && !w[a][i]) CLR = 1;
		if (i!=b && CLR) {
			w[a][i] = 0;
		}
	}
	CLR = 0;
	for (int i=b-1; i>=1; i--) {
		if (i!=b && !w[a][i]) CLR = 1;
		if (i!=b && CLR) {
			w[a][i] = 0;
		}
	}
	for (int k=0; k<4; k++) {
		int x=a+X[k], y=b+Y[k];
		if (x >= 1 && x <= n && y >= 1 && y <= m) {
			if (!v[x][y] && c[x][y]) {
				dfs(x, y);
			}
		}
	}
}
int main() {
	//local variables

	//input
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		string str; cin >> str;
		for (int j=0; j<m; j++) {
			c[i][j+1] = (str[j] == '#');
			w[i][j+1] = 1;
			b[i][j+1] = 0;
			v[i][j+1] = 0;
		}
	}

	//main
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (c[i][j] && !v[i][j]) {
				b[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	bool ok = true;
	for (int i=1; i<=n; i++) {
		bool t = false;
		for (int j=1; j<=m; j++) {
			if (w[i][j]) t=true;
		}
		if (!t) ok = false;
	}
	for (int i=1; i<=m; i++) {
		bool t = false;
		for (int j=1; j<=n; j++) {
			if (w[j][i]) t=true;
		}
		if (!t) ok = false;
	}
	//output
	if (ok) {
		ll cnt = 0;
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
			if (b[i][j]) cnt++;
		}
		cout << cnt<<endl;
	} else cout <<"-1"<<endl;
	return 0;
}
