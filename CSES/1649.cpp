#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n, q, tt[(N + 1) << 1];

void pull(int i) {
	tt[i] = min(tt[i << 1], tt[i << 1 | 1]);
}

void update(int i, int x) {
	tt[i += n] = x;
	for (i >>= 1; i; i >>= 1)
		pull(i);
}

int query(int l, int r) {
	int ret = 0x3f3f3f3f;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = min(ret, tt[l++]);
		if (r & 1) ret = min(ret, tt[--r]);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &q);
	memset(tt, 0x3f, sizeof(tt));
	for (int i = 0; i < n; ++i)	
		scanf("%d", tt + n + i);
	for (int i = n - 1; i > 0; --i)
		pull(i);
	for (int i = 0, a, b, c; i < q; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			update(--b, c);
		} else {
			printf("%d\n", query(--b, --c));
		}
	}
}