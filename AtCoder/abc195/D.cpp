#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, m, q;

struct Bag {
	int w, v;
	friend bool operator<(const Bag& a, const Bag& b) {
		if (a.v == b.v) return a.w < b.w;
		return a.w < b.w;
	}
} aa[N];

int bb[N];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &aa[i].w, &aa[i].v);
	for (int i = 0; i < m; ++i)
		scanf("%d", bb + i);
	
}