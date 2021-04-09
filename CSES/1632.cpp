#include <bits/stdc++.h>
using namespace std;
 
const int N = 200010;
 
struct P {
	int x, y;
} aa[N];
 
multiset<int> m;
int k, n, ans = 0;
 
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &aa[i].x, &aa[i].y);
	sort(aa, aa + n, [&](const P& i, const P& j) {
		return i.y < j.y;
	});
	for (int i = 0; i < k; ++i) m.insert(0);
	for (int i = 0; i < n; ++i) {
		const auto& it = m.upper_bound(aa[i].x);
		if (it != m.begin()) {
			m.erase(prev(it));
			m.insert(aa[i].y);
			ans++;
		}
	}
	printf("%d\n", ans);
}