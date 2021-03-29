#include <bits/stdc++.h>
using namespace std;

#include <ext/rope>
using namespace __gnu_cxx;

int n, m; char c;

rope<char> x;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		x.push_back(c);
	}
	for (int i = 0, l, r; i < m; ++i) {
		cin >> l >> r; --l, --r;
		x.insert(x.mutable_end(), x.substr(l, r - l + 1));
		x.erase(l, r - l + 1);
	}
	for (char c : x)
		cout << c;
	cout << '\n';
}