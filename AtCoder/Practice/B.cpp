/**
 * Interactive Sorting
 * https://atcoder.jp/contests/practice/tasks/practice_2
 * Created on 2021-02-14
 */

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define N 26

int comp[N][N];
string ans;

bool ask(char x, char y) {
	if (comp[x][y] != -1)
		return comp[x][y];
	cout << "? " << x << ' ' << y << '\n';
	cout.flush();
	char z;
	cin >> z;
	if (z == '>')
		comp[x][y] = 1, comp[y][x] = 0;
	else
		comp[x][y] = 0, comp[y][x] = 1;
	return comp[x][y];
}

void insert(char c) {
	int lo = 0, hi = ans.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (ask(c, ans[lo]))
			hi = mid - 1;
		else
			lo = mid;
	}
	string temp = ans;
	temp[lo] = c;
	for (int i = lo + 1; i < ans.size(); i++)
		temp[i] = ans[i - 1];
	temp += ans[ans.size() - 1];
	ans = temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, q;
	cin >> n >> q;
	memset(comp, -1, sizeof(comp));
	ans = "A";
	for (int i = 1; i < n; i++) {
		insert('A' + i);
	}
	cout << "! " << ans << '\n';
	cout.flush();
}