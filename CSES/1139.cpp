#include <bits/stdc++.h>
using namespace std;
 
const int N = 200010;
const int M = 2 * N;
 
int hh[N], nn[M], tt[M], ei = 0;
 
inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}
 
int n, v[N], aa[N];

struct D {
	set<int> s;
	
	D() {}
	D(const set<int>& t) : s(t) {}

	void mergeInto(D* x) {
		for (const int& i : x->s)
			s.insert(i);
		x->s.clear();
	}

	D* merge(D* x) {
		if (s.size() > x->s.size()) {
			this->mergeInto(x);
			return this;
		} else {
			x->mergeInto(this);
			return x;
		}
	} 
} *d[N];
 
void dfs(int x, int p) {
	d[x] = new D({v[x]});
	for (int j = hh[x], y; j; j = nn[j])
		if ((y = tt[j]) != p) {
			dfs(y, x);
			d[x] = d[x]->merge(d[y]);
		}
	aa[x] = d[x]->s.size();
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", v + i);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		link(x, y); link(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d ", aa[i]);
	printf("\n");
}