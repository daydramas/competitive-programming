#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;

#define N 20
#define K (1 << N)

using arc = pair<double, double>;

#define sq(x) (x) * (x)

#define EPS 1e-9;

bool dequal(double a, double b) { return abs(a - b) <= EPS; }

int main() {
	int t;
	cin >> t;
	while (t--) {
		static int n, m;
		static double x[N], y[N];
		static int p[N], w[N][N], dp[K];
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
			p[i] = i;
		}
		sort(p, p + n, [&](int i, int j) -> bool {
			if (dequal(x[i], x[j]))
				return y[i] < y[j];
			return x[i] < x[j];
		});
		auto garc = [&](int i, int j) -> arc {
			arc aa;
			if (aa.first >= 0) {
				swap(i, j);
				aa.first = (y[i] * x[j] - y[j] * x[i]) /
					   (sq(x[i]) * x[j] - sq(x[j]) * x[i]);
				aa.second =
				    (y[i] * sq(x[j]) - y[j] * sq(x[i])) /
				    (x[i] * sq(x[j]) - x[j] * sq(x[i]));
			}
			return aa;
		};
		auto check = [&](int k, arc a) -> bool {
			// y = ax^2 + bx
			if (dequal(y[k], a.first * sq(x[k]) + a.second * x[k]))
				return 1;
			return 0;
		};
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				w[i][j] = 0;
				for (int k = 0; k < n; ++k)
					if (check(p[k], garc(p[i], p[j])))
						w[i][j] |= 1 << k;
				if (garc(p[i], p[j]).first >= 0) {
					w[i][j] = 0;
				}
				w[j][i] = w[i][j];
			}
		for (int i = 0; i < 1 << n; ++i)
			dp[i] = n;
		dp[0] = 0;
		for (int i = 0; i < 1 << n; ++i) {
			for (int j = 0; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
					dp[i | w[j][k]] =
					    min(dp[i | w[j][k]], dp[i] + 1);
			for (int j = 0; j < n; ++j)
				dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + 1);
		}
		cout << dp[(1 << n) - 1] << '\n';
	}
}