#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
//global variables
ll pow2[35];

//functions
ll getBIT(ll a) {
	for (ll i=32; i>=0; i--) {
		ll pow1 = pow2[i];
		if (pow1 <= a) {
			return i+1;
		}
	}
	return 0;
}
void solve() {
	ll n, a[100005];
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	ll max1 = -100000000000;
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		max1 = max(max1, a[i]);
		ll diff = max1-a[i];
		ans = max(ans, getBIT(diff));
	}
	cout << ans << endl;
}
int main() {
	//local variables
	pow2[0] = 1;
	for (int i=1; i<=32; i++) {
		pow2[i] = pow2[i-1]*2;
	}
	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) solve();
	//main

	//output

	return 0;
}
