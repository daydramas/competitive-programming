# fencedin
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