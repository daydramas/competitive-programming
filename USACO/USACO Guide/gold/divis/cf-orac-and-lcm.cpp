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
template <class T> void DBG(const T& t) { write(t, "]", '\n'); cout.flush(); }
template <class T, class... U> void DBG(const T& t, const U&... u) { write(t, ", "); DBG(u...); }
#define error(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)


const int MOD = 1000000007;
const int INF = 1000000000;
const int N   = 100005;

typedef long long LL;
const LL M    = 200000;

struct D {
	LL a, b; int d;
	D(LL a = M, LL b = M) : a(a), b(b), d(0) {}
	void add(LL c) {
		d++;
		if (c < a) b = a, a = c;
		else if (c < b) b = c;
	}
	LL get(int n) {
		if (d == n) { /*error(a, b);*/ return b;} 
		else if (d == n - 1) { /*error(a);*/ return a; }
		else return 0;
	}
};

int sieve[M + 1], w[M + 1];
vector<LL> primes;
D res[M];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	mem(sieve, 0);
	for (LL i = 2; i <= M; ++i) if (!sieve[i]) {
		primes.push_back(i);
		sieve[i] = i; w[i] = primes.size() - 1;
		for (LL j = i * i; j <= M; j += i)
			if (!sieve[j]) sieve[j] = i, w[j] = w[i];
	}
	int n;
	static int a[N];

	// error(primes.size());
	read(n);
	LL x;
	FOR(i, 1, n) {
		read(a[i]);
		x = a[i];
		// error(x);
		while (x != 1) {
			LL p = sieve[x];
			// print("prime: ", p);
			int j = w[x], c = 0;
			while (x % p == 0) x /= p, ++c;
			res[j].add(c);
		}
	}
	long long ans = 1;
	F0R(i, primes.size()) {
		int p = res[i].get(n);
//		if (p) write(primes[i], "^", p, '\n');
		while (p > 0) { ans *= primes[i]; p--; }
	}
	print(ans);
}