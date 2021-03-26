#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n, m;
vector<string> g, h;
int out[N][N];

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	g.resize(n);

	for (string& x : g) {
		cin >> x;
		h.push_back(x);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (g[i][j] == '*') {
				int length = 100;
				for (int k = 0, x, y, l; k < 4; ++k) {
					x = i + X[k], y = j + Y[k], l = 0;
					while (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '*')
						x += X[k], y += Y[k], l++;
					length = min(length, l);
				}
				for (int k = 0, x, y; k < 4; ++k) {
					x = i, y = j;
					for (int l = 0; l < length; ++l) {
						x += X[k], y += Y[k];
						h[x][y] = '.';
					}
				}
				if (length) {
					out[i][j] = length;
					h[i][j] = '.';
				}
				out[i][j] = length;
			}
	bool okay = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (h[i][j] == '*')
				okay = false;
	if (okay) {
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (out[i][j])
					ans.push_back({i, j});
		cout << ans.size() << '\n';
		for (pair<int, int> x : ans) {
			cout << x.first + 1 << ' ' << x.second + 1 << ' ' << out[x.first][x.second] << '\n';
		}
	} else {
		cout << "-1" << '\n';
	}
}