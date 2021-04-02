#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-5

const int N = 200010;
const int INF = int(1e9);
int n, k, a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int lower = 1, found = -1, upper = INF;
	auto count = [&](int m) -> bool {
		int ret = 0;
		for (int i = 0; i < n; ++i)
			ret += (a[i] / m) - (a[i] % m == 0);
		return ret <= k;
	};
	while (lower <= upper) {
		int mid = (lower + upper) / 2;
		// printf("count(%.6f) = %d\n", mid, count(mid));
		if (count(mid))
			found = mid, upper = mid - 1;
		else lower = mid + 1;
	}
	printf("%d\n", found);
}