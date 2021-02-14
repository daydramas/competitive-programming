#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
bool comp(ll i, ll j) {
	return i > j;
}
void solve() {
	ll n, x, a[100005];
	cin >> n >> x;
	for (int i=1; i<=n; i++) cin >> a[i];
	ll sum = 0;
	vector<ll> need;
	int ans = 0;
	for (int i=1; i<=n; i++) {
		ll dif = a[i]-x;
		if (dif >= 0) {
			ans++;
			sum += a[i]-x;
		} else {
			need.push_back(dif);
		}
	}
	sort(need.begin(), need.end(), comp);
	for (ll i : need) {
		if (sum + i >= 0) {
			sum += i;
			ans++;
		} else break;
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
