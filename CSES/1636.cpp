#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1000010;

// ModInt (modular arithmetic operations)

const int MOD = 1000000007;

struct mi {
	int x; explicit operator int() const { return x; }
	mi() { x = 0; }
	mi(long long x) : x(x % MOD) { if (x < 0) x += MOD; }
	friend bool operator==(const mi& a, const mi& b) { return a.x == b.x; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.x < b.x; }
	mi& operator+=(const mi& y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
	mi& operator-=(const mi& y) { if ((x -= y.x) < 0) x += MOD; return *this; }
	mi& operator*=(const mi& y) { x = int((long long) x * y.x % M); return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, long long p) { mi ans(1); for (; p; p >>= 1, a *= a) if (p & 1) ans *= a; return ans; }
	friend mi inv(const mi& a) { return pow(a, M - 2); }
	mi operator-() const { return mi(-x); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

int n, x, a;
mi dp[M];

int main() {
	scanf("%d%d", &n, &x);
	dp[0] = 1;	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (int j = a; j <= x; ++j)
			dp[j] += dp[j - a];
	}
	printf("%d\n", int(dp[x]));
}