#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, a[N], p[N][N];
long long x, s[N], dp[N][N];

template<class T> bool down(T& a, const T& b) {
	return (a > b ? a = b, 1 : 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	memset(dp, 0x3F3F, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		dp[i][i] = 0;
		p[i][i] = i;
	}
	for (int i = n; i >= 1; --i)
		for (int j = i + 1; j <= n; ++j) {
			x = s[j] - s[i - 1];
			for (int k = p[i][j - 1]; k <= p[i + 1][j]; ++k)
				if (down(dp[i][j], dp[i][k] + dp[k + 1][j] + x))
					p[i][j] = k;
		}
	cout << dp[1][n] << '\n';
}