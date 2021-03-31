#include <bits/stdc++.h>
using namespace std;

const int N = 1500010;

int n, m, a[N], c[N];
set<int> s;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	int ans = n;
	auto ins = [&](int x) {
		if (!c[x]) s.insert(x);
		c[x]++;
	};
	auto rem = [&](int x) {
		if (c[x] == 1) s.erase(x);
		c[x]--;
	};
	auto chk = [&]() {
		if (s.empty()) return;
		ans = min(ans, *s.begin());
	};
	for (int i = 0; i < n; ++i)
		ins(i);
	for (int i = 0; i < m; ++i)
		rem(a[i]);
	chk();
	for (int i = m; i < n; ++i) {
		rem(a[i]);
		ins(a[i - m]);
		chk();
	}
	printf("%d\n", ans);
}