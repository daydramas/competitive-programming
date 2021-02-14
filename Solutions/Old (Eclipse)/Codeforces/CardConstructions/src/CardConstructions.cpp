#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n; cin >> n;
	ll ta = 0;
	for (ll i=1; ; i++) {
		ll n2 = (i*(3*i + 1))/2;
		if (n2 <= n) {
			ta = max(ta, i);
		} else break;

 	}
//	cout << "mx = "<<ta<<endl;
	ll ans = 0;
	for (ll i=ta; i>=1; i--) {
		ll n2 = (i*(3*i + 1))/2;
		while(n >= n2) {
			n -= n2;
			ans++;
		}
	}
	cout << ans << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) solve();
	//main

	//output

	return 0;
}
