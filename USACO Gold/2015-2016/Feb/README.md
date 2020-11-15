<div align="center"> <a href="#cbarncpp">cbarn.cpp</a> | <a href="#cbarn2cpp">cbarn2.cpp</a> | <a href="#fencedincpp">fencedin.cpp</a> </div>

# [cbarn.cpp](#0)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines

// global variables
int N, c[100000];
int step[100000];
//functions
int getDist(int i, int j) {
	if (j > i)
		return j - i;
	else
		return N - i + j;
}
int main() {
	// local variables
	queue<int> Q;

	// fstream
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> c[i];
		step[i] = 0;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (c[i] == 0) {
			Q.push(i);
		}
	}
	// main
	long long ans = 0;
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (int i = (t - 1 + N) % N; i != t; i = (i - 1 + N) % N) {
			if (c[i]) {
				c[i]--, c[t]++;
				step[t] = step[i] + getDist(i, t);
				ans += step[t] * step[t] - step[i] * step[i];
				if (c[i] == 0) {
					Q.push(i);
				}
				break;
			}
		}
	}

	// output
	fout << ans << endl;
	return 0;
}

```

# [cbarn2.cpp](#1)
```cpp
/*
 ID: dongliu3
 TASK: cbarn2
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL
// global variables
int n, k;
ll r[101];
ll dp[101][8], d[101][101][8];
//functions
ll dist(ll a, ll b) {
	if (b >= a) {
		return b - a;
	}
	return b + n - a;
}
void setUp() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INF;
		}
	}
	for (int j = 0; j <= k; j++) {
		dp[n][j] = 0;
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = INF;
	}
}
void ROTATE() {
	int t = r[1];
	for (int i = 1; i < n; i++) {
		r[i] = r[i + 1];
	}
	r[n] = t;
}
int main() {
	// local variables

	// fstream
	ifstream fin("cbarn2.in");
	ofstream fout("cbarn2.out");

	// input
	fin >> n >> k;
	for (int i = 1; i <= n; i++) {
		fin >> r[i];
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			dp[i][j] = INF;
//		}
//	}
//	for (int j = 0; j <= k; j++) {
//		dp[0][j] = 0;
//	}
//	for (int j = 1; j <= n; j++) {
//		for (int l = 0; l <= k; l++) {
//			d[0][j][l] = 0;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			for (int l = 0; l <= k; l++) {
//				d[i][j][l] = INF;
//			}
//		}
//	}
	// main
	ll ans = INF;
//	int arr[6] = { 0, 1, 2, 3, 4, -1 };
//	rotate(arr + 1, arr + 2, arr + 6);
//	for (int i = 0; i <= 4; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
//	rotate(arr + 1, arr + 2, arr + 6);
//	for (int i = 0; i <= 4; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
	for (int i = 1; i <= n; i++) {
		setUp();
//		cout << i << endl;
//		for (int x = 1; x <= n; x++) {
//			cout << r[x] << " ";
//		}
		cout << endl;
		for (int K = 1; K <= k; K++) {
			for (int j = 1; j <= n; j++) {
				ll sum = 0;
//				cout << "dp[" << j << "][" << K << "] = " << dp[j][K] << endl;
				for (int j2 = (j + 1); j2 <= n + 1; j2++) {
//					cout << "sum: " << sum << " dp: " << dp[j2][K - 1] << endl;
					dp[j][K] = min(dp[j][K], dp[j2][K - 1] + sum);
					sum += (j2 - j) * r[j2];
				}
//				dp[j][K] = min(dp[j][K], dp[j2][K - 1] + sum);
//				cout << "dp[" << j << "][" << K << "] = " << dp[j][K] << endl;
			}
		}
//		cout << "\n";
		ans = min(ans, dp[1][k]);
		ROTATE();
	}
	fout << ans << endl;
	return 0;
}

```

# [fencedin.cpp](#2)
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
struct edge {
	int len, xy, xy2;
	edge(int len, int xy, int xy2) :
			len(len), xy(xy), xy2(xy2) {
	}
};
struct s2b {
	bool operator()(edge i, edge j) {
		return (i.len < j.len);
	}
} s2b;
// global variables
int A, B, n, m;
int a[2010], b[2010];
pii pa[2010][2010];
//int pa_n[2010][2010];
vector<edge> edges;

//functions
pii findPa(int i, int j) {
	if (pa[i][j] == pii(i, j)) {
		return pa[i][j];
	} else {
		pa[i][j] = findPa(pa[i][j].first, pa[i][j].second);
		return pa[i][j];
	}
}
void merge(pii a, pii b) {
	pii f1 = findPa(b.first, b.second);
	pa[f1.first][f1.second] = findPa(a.first, a.second);
}

int main() {
	// local variables

	// fstream
	ifstream fin("fencedin.in");
	ofstream fout("fencedin.out");

	// input
	fin >> A >> B >> n >> m;
	a[0] = 0, b[0] = 0, a[n + 1] = A, b[m + 1] = B;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m + 1; j++) {
			pa[i][j] = pii(i, j);
//			pa_n[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		fin >> a[i];
	}
	sort(a, a + n + 1);
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m; j++) {
			edges.push_back(
					edge(a[i] - a[i - 1], i * 3000 + j, i * 3000 + j + 1));
			//			cout << a[i] - a[i - 1] << " from " << i << " " << j << " and " << i
			//					<< " " << j + 1 << endl;
		}
	}
	int total_room = (n + 1) * (m + 1);
	for (int j = 1; j <= m; j++) {
		fin >> b[j];
	}
	sort(b, b + m + 1);
	for (int j = 1; j <= m + 1; j++) {
		for (int i = 1; i <= n; i++) {
			edges.push_back(
					edge(b[j] - b[j - 1], i * 3000 + j, (i + 1) * 3000 + j));
		}
	}
	sort(edges.begin(), edges.end(), s2b);
	long long ans = 0;
//	cout << edges.size() << endl;
	for (edge e : edges) {
		int x = e.xy / 3000, y = e.xy % 3000, x2 = e.xy2 / 3000, y2 = e.xy2
				% 3000;
		pii pa1 = findPa(x, y), pa2 = findPa(x2, y2);
		if (pa1 != pa2) {
			pa[x][y] = pa1;
			pa[x2][y2] = pa1;
			pa[pa2.first][pa2.second] = pa1;
//			pa_n[pa1.first][pa1.second] += pa_n[pa2.first][pa2.second];
			ans += e.len;
//			if (pa_n[pa1.first][pa1.second] == total_room)
//				break;
			//			merge(pii(e.x, e.y), pii(e.x2, e.y2));
		}
	}
	fout << ans << endl;
	// output
	return 0;
}

```

