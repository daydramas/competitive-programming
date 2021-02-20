/**
 * CF Paired Payment
 * Created on 2021-02-18
 */

#include <array>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define N (1 << 17)
#define M 50

using ar = array<int, 2>; // {node, cost}
using AR = array<int, 4>; // {cost, node, edge, status}

int n, m, dp[N][M + 1][2];
vector<ar> g[N];

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
			for (int k = 0; k <= 1; k++)
				dp[i][j][k] = 1e9;
	dp[1][0][0] = 0;
	priority_queue<AR, vector<AR>, greater<AR>> pq;
	pq.push({0, 1, 0, 0});
	while (pq.size()) {
		AR s = pq.top();
		pq.pop();
		int c = s[0], x = s[1], e = s[2], b = s[3];
		if (dp[x][e][b] < c)
			continue;
		for (ar ed : g[x]) {
			int y = ed[0];
			int bb = !b;
			int nw = c + (bb ? 0 : (e + ed[1]) * (e + ed[1]));
			int ne = (bb ? ed[1] : 0);
			if (dp[y][ne][bb] > nw) {
				dp[y][ne][bb] = nw;
				pq.push({nw, y, ne, bb});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", dp[i][0][0] == 1e9 ? -1 : dp[i][0][0]);
	}
	printf("\n");
}