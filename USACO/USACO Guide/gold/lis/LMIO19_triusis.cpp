#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n; long long M;
long long a[N];
vector<long long> lis = {(long long)-1e18};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> M;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = M * (i + 1) - a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) continue;
		int f = upper_bound(begin(lis), end(lis), a[i]) - begin(lis);
		if (f == (int)lis.size()) lis.push_back(a[i]);
		else lis[f] = a[i];
	}
	cout << n - lis.size() + 1 << '\n';
}