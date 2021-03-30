#include <bits/stdc++.h>
using namespace std;

int lis = 0;
vector<pair<int, int>> a;
set<int> s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	a.resize(n);
	for (auto& x : a) cin >> x.first >> x.second;
	sort(begin(a), end(a), greater<pair<int, int>>());
	// finding the LIS of a reversed array = finding the LDS
	for (auto& x : a) {
		if (s.upper_bound(x.second) == s.end()) lis++;
		else s.erase(s.upper_bound(x.second));
		s.insert(x.second);
	}
	cout << lis << '\n';
}