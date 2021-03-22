#include <bits/stdc++.h>
using namespace std;

int n;
int t[2] = {2, 5};
int a[1000][1000], dp[2][1000][1000];
char dir[2][1000][1000];
string path;

int get(int k, int i, int j) {
	int x = a[i][j], y = t[k], z = 0;
	while (x % y == 0)
		x /= y, ++z;
	return z;
}

bool ckmin(int& a, const int& b) {
	return (a > b ? a = b, 1 : 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	int zero = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (!a[i][j]) {
				zero = i;
				a[i][j] = 10; // inf while loop w/o this
			}
		}
	
	memset(dp, 69, sizeof(dp));

	dp[0][0][0] = dp[1][0][0] = 0;
	for (int k = 0; k < 2; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i)
					if (ckmin(dp[k][i][j], dp[k][i - 1][j]))
						dir[k][i][j] = 'D';
				if (j) 
					if (ckmin(dp[k][i][j], dp[k][i][j - 1]))
						dir[k][i][j] = 'R';
				dp[k][i][j] += get(k, i, j);
			}
	
	int k, i = n - 1, j = n - 1;
	if (zero != -1 && min(dp[0][i][j], dp[1][i][j]) > 1) {
		cout << 1 << '\n';
		for (int i = 0; i < zero; ++i)
			cout << 'D';
		for (int i = 1; i < n; ++i)
			cout << 'R';
		for (int i = zero; i < n - 1; ++i)
			cout << 'D';
		cout << '\n';
		return 0;
	}
	cout << min(dp[0][i][j], dp[1][i][j]) << '\n';
	if (dp[0][i][j] < dp[1][i][j]) {
		k = 0;
	} else {
		k = 1;
	}
	while (i != 0 || j != 0) {
		if (dir[k][i][j] == 'R') {
			j--; path.push_back('R');
		} else {
			i--; path.push_back('D');
		}
	}
	reverse(begin(path), end(path));
	cout << path << '\n';
}