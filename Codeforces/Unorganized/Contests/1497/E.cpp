#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define mem(a, x)                memset(a, x, sizeof(a))
#define FOR(i, a, b)    for (int i = (a); i <= (b); ++i)
#define F0R(i, x)          for (int i = 0; i < (x); ++i)
#define ROF(i, a, b)    for (int i = (b); i >= (a); --i)
#define R0F(i, x)     for (int i = (x) - 1; i >= 0; --i)
#define each(x, a)                     for (auto& x : a)

template <class T> bool ckmin(T& a, const T& b) { return (a > b ? a = b, 1 : 0); }
template <class T> bool ckmax(T& a, const T& b) { return (a < b ? a = b, 1 : 0); }
template <class T> void read(T &x) { cin >> x; }
template <class T, class... U> void read(T &x, U &...y) { read(x); read(y...); }
template <class T> void write(const T &x) { cout << x; }
template <class T, class... U> void write(const T &x, const U &...y) { write(x); write(y...); }
template <class T> void print(const T &x) { write(x, "\n"); }
template <class T, class... U> void print(const T &x, const U &...y) { write(x, " "); print(y...); }
template <class T> void DBG(const T& t) { cerr << t << endl; }
template <class T, class... U> void DBG(const T& t, const U&... u) { cerr << t << ' '; DBG(u...); }
#define error(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


const int MOD = 1000000007;
const int INF = 1000000000;
const int N   = 10000000;

int p[N + 1];

void init() {
	F0R(i, N + 1) p[i] = i;
	for (int i = 2; i * i <= N; ++i)
		for (int j = i * i; j <= N; j += i * i)
			while (p[j] % (i * i) == 0)
				p[j] /= i * i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	init();

	int t; read(t);
	while (t--) {
		int n, k; read(n, k);
		int a[n], x;
		F0R(i, n) {
			read(x);
			a[i] = p[x];
		}
		map<int, int> m;
		int ans = 1;
		F0R(i, n) {
			if (m.count(a[i])) {
				m.clear();
				m[a[i]] = 1;
				++ans;
			} else {
				m[a[i]] = 1;
			}
		}
		print(ans);
	}

}