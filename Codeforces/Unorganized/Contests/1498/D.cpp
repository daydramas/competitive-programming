#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5;
ll divide(ll x, ll y) { return (x + y - 1) / y; }

int main() {

	int T, m;
	scanf("%d%d", &T, &m);

	static bool vv[M + 1], nn[M + 1];
	static int ans[M + 1];
	memset(vv, 0, sizeof(vv));
	memset(ans, -1, sizeof(ans));
	vv[0] = 1, ans[0] = 0;

	int a; ll x, y;
	for (int t = 1; t <= T; ++t) {
		for (int i = 0; i <= m; ++i)
			nn[i] = vv[i];

		scanf("%d%lld%lld", &a, &x, &y);
		auto next = [&](ll &n) {
			if (a == 1) n = n + divide(x, M);
			else n = divide(x * n, M);
		};
		for (int k = 0; k <= m; ++k) if (vv[k]) {
			ll n = k; next(n);
			for (int b = 1; b <= y; ++b) {
				if (n > m) break;
				if (vv[n]) break;
				nn[n] = 1, ans[n] = t;
				next(n);
			}
		}
		for (int i = 0; i <= m; ++i)
			vv[i] = nn[i];
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';
	cout << '\n';

}