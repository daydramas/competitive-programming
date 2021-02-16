/*
 *
 * Created on 2021-02-15
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int n[4], a[4][N], m[4];
set<int> nope[4][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < 4; i++)
		cin >> n[i];
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= n[i]; j++)
			cin >> a[i][j];
	for (int i = 0; i < 3; i++) {
		cin >> m[i];
		for (int j = 0; j < m[i]; j++) {
			int x, y;
			cin >> x >> y;
			nope[i][x].insert(y);
		}
	}
	set<pair<int, int>> cur, nxt;
	for (int i = 1; i <= n[0]; i++)
		cur.insert({a[0][i], i});
	for (int i = 1; i < 4; i++) {
		nxt.clear();
		for (int j = 1; j <= n[i]; j++) {
			auto it = cur.begin();
			while (it != cur.end() &&
			       nope[i - 1][it->second].count(j))
				++it;
			if (it != cur.end())
				nxt.insert({it->first + a[i][j], j});
		}
		swap(nxt, cur);
	}
	if (cur.empty())
		cout << "-1" << '\n';
	else
		cout << cur.begin()->first << '\n';
}