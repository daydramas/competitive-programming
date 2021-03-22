/**
 * CF Balanced Remainders
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int t, n, a[N];
	cin >> t;
	while(t--) {
		cin >> n;
		int c[3] = {0, 0, 0};
		for(int i=0; i<n; i++) {
			cin >> a[i];
			++c[a[i] % 3];
		}
		int ans = 0;
		while(*min_element(c, c + 3) != n / 3) {
			for(int i = 0; i < 3; i++) 
				if(c[i] > n / 3) c[i]--, c[(i + 1) % 3]++, ans++;
		}
		cout << ans << '\n';
	}
}