/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5
using ll = long long;

ll ans;

void dfs(string s, ll d) {}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	ans = 1e18;
	dfs(s, 0);
}