#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n; cin >> n;
	ll a[200005];
	for (int i=0; i<n; i++) cin >> a[i];
	set<ll> S;
	bool ok = true;
	for (int i=1; i<=n; i++) {
		ll n2 = i+a[i%n];
		n2 = n2%n;
		if (n2 < 0) n2 += n;
//		cout << a[i] <<" " << n2 << endl;
		if (S.find(n2) != S.end()) {
			ok = false; break;
		} else S.insert(n2);
	}
	if (ok) cout <<"YES"<<endl;
	else cout <<"NO"<<endl;
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
