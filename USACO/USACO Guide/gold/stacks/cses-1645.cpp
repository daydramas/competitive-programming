#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	stack<int> s; int i = 0;
	for (int x : a) {
		while (s.size() && a[s.top()] >= x)
			s.pop();
		cout << (s.size() ? s.top() + 1 : 0) << ' ';
		s.push(i++);
	}
	cout << '\n';
}