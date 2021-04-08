#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

const int N = 200010;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
gp_hash_table<long long, int, custom_hash> ht;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if ((a[i] %= n) < 0) a[i] += n;
	}
	long long ans = 0, pp = 0;
	ht[0]++;
	for (int i = 1; i <= n; ++i) {
		if ((pp += a[i]) >= n) pp -= n;
		ans += ht[pp], ht[pp]++;
	}
	printf("%lld\n", ans);
}