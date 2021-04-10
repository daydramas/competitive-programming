#include <bits/stdc++.h>
using namespace std;

string s[400];

#define x first
#define y second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;cin >> n;
		vector<pair<int,int>> pp;
		for (int i= 0 ; i < n; ++i) {
			cin >> s[i];
			for (int j = 0; j < n; ++j)
				if (s[i][j] == '*')
					pp.push_back({i, j});
		}
		pair<int, int> a = pp[0], b = pp[1];
		if (a.x == b.x) {
			if (a.x == 0) s[n - 1][a.y] = s[n - 1][b.y] = '*';
			else s[0][a.y] = s[0][b.y] = '*';
		} else if (a.y == b.y) {
			if (a.y == 0) s[a.x][n - 1] = s[b.x][n - 1] = '*';
			else s[a.x][0] = s[b.x][0] = '*';
		} else {
			int mx = min(a.x, b.x);
			int my = min(a.y, b.y);
			int mxx = max(a.x, b.x);
			int mxy = max(a.y, b.y);
			s[mx][my] = s[mx][mxy] = s[mxx][my] = s[mxx][mxy] = '*';
		}
		for (int i = 0; i < n; ++i)
			cout << s[i] << '\n';
		
	}
}