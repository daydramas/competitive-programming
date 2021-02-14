/**
 * CSES Chessboard and Queens
 * https://cses.fi/problemset/task/1624/
 */

#include <iostream>
#include <string>
using namespace std;

const int n = 8;
const int d = n * 2;

int cnt;
bool col[n], d1[d], d2[d];
string g[n];

void place(int r) {
	if (r == n) {
		++cnt;
		return;
	}
	for (int c = 0; c < n; c++) {
		if (g[r][c] == '*')
			continue;
		if (col[c] || d1[r - c + n - 1] || d2[r + c])
			continue;
		col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
		place(r + 1);
		col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < n; i++) {
		col[i] = 0;
		d1[i * 2] = d1[i * 2 + 1] = 0;
		d2[i * 2] = d2[i * 2 + 1] = 0;
		cin >> g[i];
	}
	cnt = 0;
	place(0);
	cout << cnt << '\n';
}