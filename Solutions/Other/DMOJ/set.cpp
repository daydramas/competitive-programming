/**
 * Unique Elements
 * https://dmoj.ca/problem/set
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N	int(3e4)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, ans, a[N];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	ans = 1;
	for(int i=1; i<n; i++) {
		ans += (a[i] != a[i-1]);
	}
	cout << ans << '\n';
}