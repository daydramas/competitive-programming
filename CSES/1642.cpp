#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

const int N = 5005;

int n, x, a[N];

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

struct P {
	int x, y;
};

gp_hash_table<int, P, custom_hash> ht;

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j < i; ++j)
			if (ht.find(x - a[i] - a[j]) != ht.end()) {
				const P& t = ht[x - a[i] - a[j]];
				printf("%d %d %d %d\n", i, j, t.x, t.y), exit(0);
			}
		for (int j = i + 1; j <= n; ++j)
			ht[a[i] + a[j]] = {i, j};
	}
	printf("IMPOSSIBLE\n");
}