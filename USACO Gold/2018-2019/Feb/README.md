<div align="center"> <a href="#0">cowland.cpp</a> | <a href="#1">dishes.cpp</a> | <a href="#2">paintbarn.cpp</a> </div>

# [cowland.cpp](#0)
```cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// structures / defines
#define MAX_N 100000
#define MAX_D 17
// global variables
int N; int Q;
int E[MAX_N];
vector<int> edges[MAX_N];
int tree[MAX_N], depth[MAX_N], lca[MAX_N][MAX_D], label[MAX_N], topchain[MAX_N];
int segtree[MAX_N*4];
// functions
void initLca() {
	for(int d=1; d<MAX_D; d++) {
		for(int i=0; i<MAX_N; i++) {
			lca[i][d] = lca[lca[i][d-1]][d-1];
		}
	}
}
int getLCA(int a, int b) {
  if(depth[a] < depth[b]) swap(a, b);
  for(int d = MAX_D-1; d >= 0; d--) {
    if(depth[a] - (1<<d) >= depth[b]) {
      a = lca[a][d];
    }
  }
  for(int d = MAX_D-1; d >= 0; d--) {
    if(lca[a][d] != lca[b][d]) {
      a = lca[a][d];
      b = lca[b][d];
    }
  }
  if(a != b) {
    a = lca[a][0];
    b = lca[b][0];
  }
  return a;
}
void setUpSegTree(int idx, int l, int r, int i, int v) {
	if(l == r) segtree[idx] = v;
	else {
		int m = (l+r)/2;
		if(i <= m) setUpSegTree(2*idx, l, m, i, v);
		else setUpSegTree(2*idx+1, m+1, r, i, v);
		segtree[idx] = segtree[idx*2] ^ segtree[idx*2+1];
	}
}
void setUpSegTree(int i, int v) {
	return setUpSegTree(1, 0, MAX_N-1, i, v);
}
void dfsHld(int curr, int topPtr, int par, int& l) {
	label[curr] = l++;
	setUpSegTree(label[curr], E[curr]);
	topchain[curr] = topPtr;
	int lc = -1, lct = -1;
	for(int out : edges[curr]) {
		if(out == par) continue;
		if(tree[out] > lct) {
			lc = out, lct = tree[out];
		}
	}
	if(lc < 0 || lct < 0) return;
	dfsHld(lc, topPtr, curr, l);
	for(int out : edges[curr]) {
		if(out == par || out == lc) continue;
		dfsHld(out, out, curr, l);
	}
}
void dfsSize(int curr, int par) {
	tree[curr]++;
	for(int out : edges[curr]) {
		if(out == par) continue;
		depth[out] = depth[curr]+1;
		lca[out][0] = curr;
		dfsSize(out, curr);
		tree[curr] += tree[out];
	}
}
void setUp() {
	dfsSize(0, -1);
	initLca();
	int l = 0;
	dfsHld(0, 0, -1, l);
}
int QsegTree(int idx, int l, int r, int lhs, int rhs) {
  if(l >= lhs && r <= rhs) return segtree[idx];
  int ret = 0;
  int m = (l+r)/2;
  if(m >= lhs) ret ^= QsegTree(2*idx, l, m, lhs, rhs);
  if(m+1 <= rhs) ret ^= QsegTree(2*idx+1, m+1, r, lhs, rhs);
  return ret;
}
int QsegTree(int l, int r) {
	return QsegTree(1, 0, MAX_N-1, l, r);
}
int pathQ(int child, int par) {
	int ans = 0;
	while(child != par) {
		if(topchain[child] == child) {
			ans ^= E[child];
			child = lca[child][0];
		} else if (depth[topchain[child]] > depth[par]) {
			ans ^= QsegTree(label[topchain[child]], label[child]);
			child = lca[topchain[child]][0];
		} else {
			ans ^= QsegTree(label[par]+1, label[child]);
			break;
		}
	}
	return ans;
}
int query(int a, int b) {
	int r = getLCA(a, b);
	return pathQ(a, r) ^ pathQ(b, r) ^ E[r];
}
int main() {
	// local variables

	// input
	ifstream fin("cowland.in");
	ofstream fout("cowland.out");

	fin >> N >> Q;
	for(int i=0; i<N; i++) {
		fin >> E[i];
	}
	for(int i=1; i<N; i++) {
		int a, b; fin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	setUp();
	// main
	for(int i=0; i<Q; i++) {
		int c,a,b; fin >> c >> a >> b;
		if(c == 1) {
			a--; E[a] = b;
			setUpSegTree(label[a], b);
		} else {
			a--; b--;
			fout << query(a, b) << endl;
		}
	}
	// output

	return 0;
}

```

# [dishes.cpp](#1)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// structures/defines

// global variables
int N;
vector<int> pile[100005];
//vector<vector<int> > pile;
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("dishes.in");
	ofstream fout("dishes.out");

	// input
	fin >> N;
	int lRemove = 0;
	int ans = N;
	int piles = 0;
	for (int i = 1; i <= N; i++) {
		int d;
		fin >> d;
		if (d < lRemove) {
			ans = i - 1;
			break;
		}
		int j = 0;
		for (; j < piles; j++) {
			if (d < pile[j].front()) {
				while (!pile[j].empty() && (d > pile[j].back())) {
					lRemove = max(lRemove, pile[j].back());
					pile[j].pop_back();
				}
				break;
			}
		}
		if (j == piles) {
			pile[piles].push_back(d);
			piles++;
		} else {
			pile[j].push_back(d);
		}

	}
	// output
	fout << ans << endl;
	return 0;
}

```

# [paintbarn.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// structures/defines
#define MAX 215
// global variables
int N, K;
int layer[MAX][MAX];
int actual[MAX][MAX];
int topDP[MAX], bottomDP[MAX], leftDP[MAX], rightDP[MAX];
//functions
int rectangle(int a, int b, int x, int y) {
	return actual[a + x][b + y] - actual[a][b + y] - actual[a + x][b]
			+ actual[a][b];
}
int main() {
	// local variables

	// fstream
	ifstream fin("paintbarn.in");
	ofstream fout("paintbarn.out");
	// input
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			layer[i][j] = 0;
			actual[i][j] = 0;
		}
		topDP[i] = bottomDP[i] = leftDP[i] = rightDP[i] = 0;
	}
	fin >> N >> K;
	int before = 0;
	for (int i = 1; i <= N; i++) {
		int a, b, c, d;
		fin >> a >> b >> c >> d;
		layer[a][b]++;
		layer[a][d]--;
		layer[c][b]--;
		layer[c][d]++;
	}
	// main
	int abc = 0;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			if (i > 0) {
				layer[i][j] += layer[i - 1][j];
			}
			if (j > 0) {
				layer[i][j] += layer[i][j - 1];
			}
			if (i && j) {
				layer[i][j] -= layer[i - 1][j - 1];
			}
			if (layer[i][j] == K) {
				before++;
				actual[i + 1][j + 1] = -1;
//				cout << "actual[" << i << "][" << j << "] = " << actual[i][j]
//						<< endl;
			} else if (layer[i][j] == K - 1) {
				abc++;
				actual[i + 1][j + 1] = 1;
//				cout << "actual[" << i << "][" << j << "] = " << actual[i][j]
//						<< endl;
			}
//			if (i + 1 <= 200) {
//				layer[i + 1][j] += layer[i][j];
//			}
//			if (j + 1 <= 200) {
//				layer[i][j + 1] += layer[i][j];
//			}
//			if (i + 1 <= 200 && j + 1 <= 200) {
//				layer[i + 1][j + 1] -= layer[i][j];
//			}
		}
//		cout << endl;
	}
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
//			if (i) {
			actual[i][j] += actual[i - 1][j];
//			}
//			if (j > 0) {
			actual[i][j] += actual[i][j - 1];
//			}
//			if (i > 0 and j > 0) {
			actual[i][j] -= actual[i - 1][j - 1];
//			}
//			fout << actual[i][j] << " ";
//			if (i + 1 <= 200) {
//				actual[i + 1][j] += actual[i][j];
//			}
//			if (j + 1 <= 200) {
//				actual[i][j + 1] += actual[i][j];
//			}
//			if (i + 1 <= 200 && j + 1 <= 200) {
//				actual[i + 1][j + 1] -= actual[i][j];
//			}
		}
//		fout << endl;
	}
	int ans = 0;
//	cout << "calculating the 4 DPs..." << endl;
	for (int i = 0; i <= 200; i++) {
		for (int len = 1; len + i <= 200; len++) {
			int tmax, bmax, lmax, rmax;
			tmax = bmax = lmax = rmax = 0;
			for (int j = 1; j <= 200; j++) {
				ans = max(ans,
						topDP[j] = max(topDP[j],
								tmax = max(0,
										tmax + rectangle(j - 1, i, 1, len))));
				ans = max(ans,
						leftDP[j] = max(leftDP[j],
								lmax = max(0,
										lmax + rectangle(i, j - 1, len, 1))));
				ans = max(ans,
						rightDP[j] = max(rightDP[j],
								rmax = max(0,
										rmax + rectangle(i, 200 - j, len, 1))));
				ans = max(ans,
						bottomDP[j] = max(bottomDP[j],
								bmax = max(0,
										bmax + rectangle(200 - j, i, 1, len))));
			}
		}
	}
//	cout << "calculating prefix sum..." << endl;
	for (int i = 2; i <= 200; i++) {
		topDP[i] = max(topDP[i], topDP[i - 1]);
		leftDP[i] = max(leftDP[i], leftDP[i - 1]);
		rightDP[i] = max(rightDP[i], rightDP[i - 1]);
		bottomDP[i] = max(bottomDP[i], bottomDP[i - 1]);
//		cout << topDP[i] << " " << bottomDP[200 - i] << " " << leftDP[i] << " "
//				<< rightDP[200 - i] << endl;
	}
// output
//	cout << "calculating ans..." << endl;
	for (int i = 1; i < 200; i++) {
		ans = max(ans, topDP[i] + bottomDP[200 - i]);
//		cout << "1" << topDP[i] << " " << bottomDP[200 - i] << endl;

//		ans = max(ans, topDP[200 - i] + bottomDP[i]);
		ans = max(ans, leftDP[i] + rightDP[200 - i]);
//		cout << "2 " << leftDP[i] << " " << rightDP[200 - i] << endl;
//		ans = max(ans, leftDP[200 - i] + rightDP[i]);
	}
	fout << ans + before << endl;
//	cout << before << " " << ans << endl;
	return 0;
}

```

