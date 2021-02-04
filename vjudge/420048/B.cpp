/**
 * B - Intervals
*/

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5
#define mp make_pair

int main() {

	static int n;
	static int a[N], b[N];
	pair<int, int> c[N];

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		c[i*2] = mp(a[i], -1);
		c[i*2+1] = mp(b[i], 1);
	}
	sort(c, c+n+n);
	int cnt = 0;
	int ps = -1;
	for(int i=0; i<n+n; i++) {
		if(c[i].second == -1) {
			cnt++;
			if(ps == -1) ps = c[i].first;
		} else {
			cnt--;
			if(cnt == 0) {
				cout << ps << ' ' << c[i].first << '\n';
				ps = -1;
			}
		}
	}
}