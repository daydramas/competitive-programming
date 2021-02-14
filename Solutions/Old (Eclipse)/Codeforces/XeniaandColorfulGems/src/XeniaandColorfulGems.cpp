#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
#define pii pair<ll, int>

//global variables

//functions
ll sq(ll a) {
	return a*a;
}
void solve() {
	ll r, g, b; cin >> r >> g >> b;

	vector<ll> rv, gv, bv;
	for (int i=0; i<r; i++) {
		ll x; cin >> x;
		rv.push_back(x);
	}
	for (int i=0; i<g; i++) {
		ll x; cin >> x;
		gv.push_back(x);
	}
	for (int i=0; i<b; i++) {
		ll x; cin >> x;
		bv.push_back(x);
	}
	sort(rv.begin(), rv.end());
	sort(gv.begin(), gv.end());
	sort(bv.begin(), bv.end());

	int rin, gin, bin;
	rin = gin = bin = 0;
	ll ans = -1;
	while(rin < r || gin < g || bin < b) {
		ll t = sq(rv[rin]-gv[gin]) + sq(rv[rin]-bv[bin]) +  sq(bv[bin]-gv[gin]);
//		ans = min(ans, t);
//		cout << rv[rin] <<" " << gv[gin] <<" " << bv[bin]<<endl;
		if (ans == -1) ans = t;
		else ans = min(ans, t);

		bool kr, kg, kb; kr = kg = kb = 1;
		if (rin == r-1) kr = 0;
		if (gin == g-1) kg = 0;
		if (bin == b-1) kb = 0;
		if (!kr && !kg && !kb) {
			break;
		}
		if (kr && !kg && !kb) {
			rin++;
			continue;
		}
		if (!kr && kg && !kb) {
			gin++;
			continue;
		}
		if (!kr && !kg && kb) {
			bin++;
			continue;
		}
		if (kr && kg && !kb) {
			if (rv[rin] < gv[gin]) {
				rin++;
			} else gin++;
			continue;
		}
		if (!kr && kg && kb) {
			if (gv[gin] < bv[bin]) {
				gin++;
			} else bin++;
			continue;
		}
		if (kr && !kg && kb) {
			if (rv[rin] < bv[bin]) {
				rin++;
			} else bin++;
			continue;
		}
		if (kr && kg && kb) {
			if (rv[rin] < bv[bin] && rv[rin] < gv[gin]) {
				rin++;
			} else if (gv[rin] < bv[bin] && rv[rin] > gv[gin]) {
				gin++;
			}else bin++;
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
