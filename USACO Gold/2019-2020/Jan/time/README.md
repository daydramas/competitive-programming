# time
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<int, int>
#define ppii pair<int, pii>
// global variables
int N, M, C;
int m[1001];
vector<int> edge[1001];
int dp[1001][3001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("time.in");
	ofstream fout("time.out");

	// input
	fin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		fin >> m[i];
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		fin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 3 * N; j++) {
			dp[i][j] = -1000000000;
		}
	}
	// main
	dp[1][0] = 0;
	queue< ppii> Q;
	Q.push(ppii(1, pii(0, 0)));
	while (!Q.empty()) {
		ppii f = Q.front();
		Q.pop();

		if (f.second.first == N * 3) {
			continue;
		}
		for (int i : edge[f.first]) {
			int nm = dp[f.first][f.second.first] + m[i];
//			cout << f.first << " " << i << endl;
//			cout << nm << endl;
			nm += C * f.second.first * f.second.first;
//			cout << "adding " << C * f.second.first * f.second.first << endl;
			nm -= C * (f.second.first + 1) * (f.second.first + 1);
//			cout << "subtracting "
//					<< C * (f.second.first + 1) * (f.second.first + 1) << endl;
			if (dp[i][f.second.first + 1] < nm) {
				dp[i][f.second.first + 1] = nm;
//				cout << "dp[" << i << "][" << f.second.first + 1 << "] = " << nm
//						<< endl;
				Q.push(ppii(i, pii(f.second.first + 1, nm)));
			}
//			cout << endl;
		}
	}
// output
	int ans = 0;
	for (int i = 0; i <= N * 3; i++) {
		ans = max(ans, dp[1][i]);
	}
	fout << ans << endl;
	return 0;
}

```