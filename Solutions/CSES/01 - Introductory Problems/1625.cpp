/*
============================================================================
 Name:		CSES Grid Paths
 Link:		https://cses.fi/problemset/task/1625
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
*/

#include <iostream>
#include <string>
using namespace std;

#define N 7

int ans;
string s;
bool visited[9][9];

bool only(int i, int j) {
	int k = 0;
	if (i == 7 && j == 1)
		return 0;
	if (!visited[i - 1][j])
		k++;
	if (!visited[i + 1][j])
		k++;
	if (!visited[i][j - 1])
		k++;
	if (!visited[i][j + 1])
		k++;
	return k == 1;
}
void solve(int i, int j, int D) {
	if (D == 48 || (i == 7 && j == 1)) {
		ans += (D == 48);
		return;
	}
	bool u = !visited[i - 1][j];
	bool d = !visited[i + 1][j];
	bool l = !visited[i][j - 1];
	bool r = !visited[i][j + 1];

	if (u && d && !l && !r)
		return;
	if (!u && !d && l && r)
		return;

	visited[i][j] = 1;
	char dir = s[D++];
#define OK(DIR) if (dir == DIR || dir == '?')

	if (u && only(i - 1, j)) {
		OK('U')
		solve(i - 1, j, D);
		visited[i][j] = 0;
		return;
	}
	if (d && only(i + 1, j)) {
		OK('D')
		solve(i + 1, j, D);
		visited[i][j] = 0;
		return;
	}
	if (l && only(i, j - 1)) {
		OK('L')
		solve(i, j - 1, D);
		visited[i][j] = 0;
		return;
	}
	if (r && only(i, j + 1)) {
		OK('R')
		solve(i, j + 1, D);
		visited[i][j] = 0;
		return;
	}
	if (u)
		OK('U')
	solve(i - 1, j, D);
	if (d)
		OK('D')
	solve(i + 1, j, D);
	if (l)
		OK('L')
	solve(i, j - 1, D);
	if (r)
		OK('R')
	solve(i, j + 1, D);
	visited[i][j] = 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			visited[i][j] = i == 0 || i == 8 || j == 0 || j == 8;
	ans = 0;
	solve(1, 1, 0);
	cout << ans << '\n';
}