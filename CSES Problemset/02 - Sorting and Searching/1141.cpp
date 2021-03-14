/**
 * CSES Playlist
 * Created on 2021-03-14
 */

#include <iostream>
#include <unordered_set>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	static int a[N];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	unordered_set<int> s;
	s.reserve(n);
	int ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (s.find(a[i]) != s.end())
			s.erase(a[j++]);
		s.insert(a[i]);
		ans = max<int>(ans, s.size());
	}
	cout << ans << '\n';
}