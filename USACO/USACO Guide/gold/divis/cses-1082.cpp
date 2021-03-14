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

typedef __uint128_t LL;

const LL MOD  = 1000000007;

LL add(const LL& x, const LL& y) {
	return (x % MOD + y % MOD) % MOD;
}
LL mul(const LL& x, const LL& y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}

LL sum(LL lo, LL hi, LL di) {
	if (lo > hi) return 0;
	LL nu = (hi - lo) / di + 1;
	LL av = (lo + hi);
	if (nu % 2 == 0) nu /= 2;
	else av /= 2;
	return (nu * av / di) % MOD;
}

inline void read(LL& a) {
	int c;
	a = 0;
	do { c = getchar_unlocked(); } while(c < '0');
	do {
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar_unlocked();
	} while(c >= '0');
}

void print(LL a) {
	if (a == 0)
		return;
	print(a / 10);
	putchar_unlocked('0' + a % 10);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	LL n; read(n);
	LL ans = 0;
	for (LL i = 1; i * i <= n; ++i) {
		// error(i);
		ans = add(ans, i);
		// print("adding", i);
		ans = add(ans, mul(i, (n / i) - i));
		// print("adding", mul(i, (n / i) - i));
		ans = add(ans, sum(i * i + i, n / i * i, i));
		// print("adding", sum(i * i + i, n / i * i, i));
	}
	print(ans);
	putchar_unlocked('\n');
}