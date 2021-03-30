#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

struct L {
	int x;
	L *next;
} *aa[N];

void link(int i, int j) {
	L *l = new L();
	l->x = j;
	l->next = aa[i];
	aa[i] = l;
};

int n;

const int MOD = 1000000007;
typedef long long ll;

struct mi {
 	int v; explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(ll _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }

mi dp[N][2];

void f(int x, int p) {
	dp[x][0] = dp[x][1] = 1;
	for (L *j = aa[x]; j; j = j->next)
		if (j->x != p) {
			f(j->x, x);
			dp[x][0] *= dp[j->x][0] + dp[j->x][1];
			dp[x][1] *= dp[j->x][0];
		}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		link(x, y); link(y, x);
	}

	f(1, 0);
	cout << int(dp[1][0] + dp[1][1]) << '\n';
}