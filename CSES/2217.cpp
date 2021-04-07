#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, b[N], a[N], ans = 1;
bool pp[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), b[--a[i]] = i;
	for (int i = 1; i < n; ++i)
		if (b[i] < b[i - 1])
			ans++, pp[i] = 1;
	for (int j = 0, x, y; j < m; ++j) {
		scanf("%d%d", &x, &y); --x, --y;
		auto pull = [&](int i) {
			if (i <= 0 || i >= n) return;
			bool nx = (b[i] < b[i - 1]);
			ans += nx - pp[i], pp[i] = nx;
		};
		swap(b[a[x]], b[a[y]]);
		swap(a[x], a[y]);
		pull(a[x]), pull(a[x] + 1);
		pull(a[y]); pull(a[y] + 1);
		printf("%d\n", ans);
	}
}