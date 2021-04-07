#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int M = 2 * N;

int hd[N], nx[M], to[M], ei = 0;

inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}

int n, ss[N];

int subtree(int x, int p = 0) {
	ss[x] = 1;
	for (int j = hd[x], y; j; j = nx[j])
		if ((y = to[j]) != p)
			ss[x] += subtree(y, x);
	return ss[x];
}

int centroid(int dd, int x, int p = 0) {
	for (int j = hd[x], y; j; j = nx[j])
		if ((y = to[j]) != p && ss[y] > dd)
			return centroid(dd, y, x);
	return x;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y), link(y, x);
	}
	printf("%d\n", centroid(subtree(1) / 2, 1));
}