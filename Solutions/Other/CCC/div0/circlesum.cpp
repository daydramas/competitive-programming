/**
 * circlesum
*/

#include <iostream>
using namespace std;

#define N	100

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("circlesum.in", "r", stdin);
	freopen("circlesum.out", "w", stdout);

	static int n, a[N * 2], best, best_cur, cur;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	best = 0;
	for(int i=0; i<n; i++) {
		cur = 0;
		best_cur = 0;
		for(int j=i; j<i+n; j++) {
			best_cur = max(best_cur,
			cur = cur + a[j]);
		}
		best = max(best, best_cur);
	}
	cout << best << '\n';

}