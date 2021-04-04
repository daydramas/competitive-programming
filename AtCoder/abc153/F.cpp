#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

#define sc scanf
#define pr printf

int n; long long d, a;

struct C {
	long long x, h;
} c[N];

long long bit[N];

long long query(int i) {
	long long ans = 0; ++i;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, long long x) {
	++i;
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}

int main() {
	sc("%d%lld%lld", &n, &d, &a);
	for (int i = 0; i < n; ++i)
		sc("%lld%lld", &c[i].x, &c[i].h);
	sort(c, c + n, [](const C& i, const C& j) {
		return i.x < j.x;
	});
	auto add = [&](long long p, long long f) {
		int lower = 0, upper = n - 1, l = -1, r = -1;
		while (lower <= upper) {
			int mid = (lower + upper) / 2;
			if (c[mid].x >= p - d) l = mid, upper = mid - 1;
			else lower = mid + 1;
		}
		lower = 0, upper = n - 1;
		while (lower <= upper) {
			int mid = (lower + upper) / 2;
			if (c[mid].x <= p + d) r = mid, lower = mid + 1;
			else upper = mid - 1;
		}
		update(l, f);
		update(r + 1, -f);
		// printf("update(%d, %d)\n", l, f);
		// printf("update(%d, %d)\n", r + 1, -f);
	};
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		long long f = query(i);
		if (f < c[i].h) {
			long long am = (c[i].h - f + a - 1) / a;
			ans += am;
			// printf("-> at position %d, with force %d * %d\n", c[i].x + d, a, am);
			add(c[i].x + d, a * am);
		}
	}
	printf("%lld\n", ans);
	
}