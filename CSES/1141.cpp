#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N], ans = 0;
unordered_set<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	s.reserve(n);
	for (int i = 0, j = 0; i < n; ++i) {
		while (s.find(a[i]) != s.end())
			s.erase(a[j++]);
		s.insert(a[i]);
		ans = max(ans, i - j + 1);
	}
	printf("%d\n", ans);
}