#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using std::max; 
using std::cin;
using std::cout;
using std::vector;
using std::queue;
const int MX = 300;

int n, m;
vector<int> c[MX + 1];
int k[MX + 1], dp[MX + 1][MX + 5];

int dfs(int i, int v) {
	if (dp[i][v] != -1) return dp[i][v];
	if (v == 0) return dp[i][v] = 0;

	for (int j : c[i]) {
		dp[i][v] = max(dp[i][v], dfs(j, v - 1));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int s; 
		cin >> s >> k[i];
		c[s].push_back(i);
	}
	memset(dp, 0, sizeof(dp));
	cout << dfs(0, m + 1) << '\n';
}