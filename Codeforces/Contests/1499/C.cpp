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
template <class T> void DBG(const T& t) { cerr << t << "]" << endl; }
template <class T, class... U> void DBG(const T& t, const U&... u) { cerr << t << ' '; DBG(u...); }
#define error(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


const int MOD = 1000000007;
const int INF = 1000000000;
const int N   = 100005;

#include <set>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; read(t);
	while (t--) {
		int n; long long x;
		read(n);
		long long ans = 1e18, sum = 0;
		long long _min[2] = {1LL<<60, 1LL<<60};
		long long size[2] = {0, 0};
		F0R(i, n) {
			read(x);
			ckmin(_min[i % 2], x);
			sum += x;
			size[i % 2]++;
			if (i) {
				long long temp = sum;
				temp += (n - size[0]) * _min[0];
				temp += (n - size[1]) * _min[1];
				ckmin(ans, temp);
			}
		}
		print(ans);

	}
}