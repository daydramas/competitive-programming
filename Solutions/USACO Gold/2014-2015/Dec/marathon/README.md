# marathon
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

typedef pair<int, int> pii;

const int maxn = 1 << 17;
int n, q;
pii checkpoint[maxn];
int delta[2 * maxn];
int dist[2 * maxn];

int qa, qb;
int DistBetween(int a, int b) {
	return abs(checkpoint[a].first - checkpoint[b].first) + abs(checkpoint[a].second - checkpoint[b].second);
}

void build_ST(int rt, int a, int b) {
	if (a > b) return;
	if (a == b) {
		if (a < n - 1) delta[rt] = DistBetween(a, a + 1) + DistBetween(a + 1, a + 2) - DistBetween(a, a + 2);
		else delta[rt] = 0;
		if (a < n) dist[rt] = DistBetween(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	build_ST(rt * 2, a, mid);
	build_ST(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

int query_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return dist[rt];
	int mid = (a + b) / 2;
	return query_dist(rt * 2, a, mid) + query_dist(rt * 2 + 1, mid + 1, b);
}

int query_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return 0;
	if (qa <= a && b <= qb) return delta[rt];
	int mid = (a + b) / 2;
	return max(query_delta(rt * 2, a, mid), query_delta(rt * 2 + 1, mid + 1, b));
}

void update_dist(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n) dist[rt] = DistBetween(a, a + 1);
		else dist[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_dist(rt * 2, a, mid);
	update_dist(rt * 2 + 1, mid + 1, b);
	dist[rt] = dist[rt * 2] + dist[rt * 2 + 1];
}

void update_delta(int rt, int a, int b) {
	if (a > qb || b < qa) return;
	if (qa <= a && b <= qb) {
		if (a >= 1 && a < n - 1) delta[rt] = DistBetween(a, a + 1) + DistBetween(a + 1, a + 2) - DistBetween(a, a + 2);
		else delta[rt] = 0;
		return;
	}
	int mid = (a + b) / 2;
	update_delta(rt * 2, a, mid);
	update_delta(rt * 2 + 1, mid + 1, b);
	delta[rt] = max(delta[rt * 2], delta[rt * 2 + 1]);
}

int main() {
	// fstream
	ifstream fin ("marathon.in");
	ofstream fout ("marathon.out");

	fin >> n >> q;
	for (int i = 1; i <= n; i++) {
		fin >> checkpoint[i].first >> checkpoint[i].second;
	}
	build_ST(1, 1, n);
	for (int i = 0; i < q; i++) {
		char c[2];
		fin >> c;
		if (c[0] == 'Q') {
			fin >> qa >> qb;
			qb--;
			int tot = query_dist(1, 1, n);
			qb--;
			int del = query_delta(1, 1, n);
			fout << tot - del << endl;
		}
		else {
			int ix, pa, pb;
			fin >> ix >> pa >> pb;
			checkpoint[ix].first = pa;
			checkpoint[ix].second = pb;
			for (int j = ix - 1; j <= ix; j++) {
				qa = j; qb = j;
				update_dist(1, 1, n);
			}
			for (int j = ix - 2; j <= ix; j++) {
				qa = j; qb = j;
				update_delta(1, 1, n);
			}
		}
	}
}

```