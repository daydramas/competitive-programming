/**
 * problem-name
 * problem-link
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, ans, n, a[N], h[N], v[N];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			h[i] = v[i] = 0;
			cin >> a[i];
		}
		ans = 0;
		for(int i=2; i<=n-1; i++) {
			h[i] = (i == 1 || a[i] > a[i-1]) && (i == n || a[i] > a[i+1]);
			v[i] = (i == 1 || a[i] < a[i-1]) && (i == n || a[i] < a[i+1]);
			ans += (int) h[i] + v[i];
		}
		for(int i=1; i<=n; i++) {
			int tans = ans;
			if(i != 1) {
				int na = a[i-1];
				if(i>1 && i <n) {
					int nh = (i == 1 || na > a[i-1]) && (i == n || na > a[i+1]) - h[i];
					int nv = (i == 1 || na < a[i-1]) && (i == n || na < a[i+1]) - v[i];
					tans += nh + nv;
				}
				if(i > 2) {
					int nh = (a[i-1] > na) && (i == 2 || a[i-1] > a[i-2]) - h[i-1];
					int nv = (a[i-1] < na) && (i == 2 || a[i-1] < a[i-2]) - v[i-1];
					tans += nh + nv;
				}
				if(i < n-1) {
					int nH = (a[i+1] > na) && (i == n-1 || a[i+1] > a[i+2]) - h[i+1];
					int nV = (a[i+1] < na) && (i == n-1 || a[i+1] < a[i+2]) - v[i+1];
					tans += nH + nV;
				}
				ans = min(ans, tans);
			}
			if(i != n) {
				tans = ans;
				int na = a[i+1];
				if(i>1 && i <n) {
					int nh = (i == 1 || na > a[i-1]) && (i == n || na > a[i+1]) - h[i];
					int nv = (i == 1 || na < a[i-1]) && (i == n || na < a[i+1]) - v[i];
					tans += nh + nv;
				}
				if(i < n-1) {
					int nh = (a[i+1] > na) && (i == n-1 || a[i+1] > a[i+2]) - h[i+1];
					int nv = (a[i+1] < na) && (i == n-1 || a[i+1] < a[i+2]) - v[i+1];
					tans += nh + nv;
				}
				if(i > 2) {
					int nH = (a[i-1] > na) && (i == 2 || a[i-1] > a[i-2]) - h[i-1];
					int nV = (a[i-1] < na) && (i == 2 || a[i-1] < a[i-2]) - v[i-1];
					tans += nH + nV;
				}
				ans = min(ans, tans);
			}
		}
		cout << ans << '\n';
	}
}