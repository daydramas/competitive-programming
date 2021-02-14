#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
ll getpow(ll a) {
	for (ll j=30; j>=0; j--) {
		if ((1<<j) <= a) return j;
	}
	return 0;
}
void solve() {
	ll n; cin >> n;
	ll p = getpow(n)+1;
	for (ll p2=p; p2>=1; p2--) {
		ll d = n-(1<<(p2-1));
		d = min(d, p2-1);

	}
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
