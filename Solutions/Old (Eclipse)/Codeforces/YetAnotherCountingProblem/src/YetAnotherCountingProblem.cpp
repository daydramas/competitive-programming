#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
void solve() {
	ll a, b, q; cin >> a >> b >> q;
	ll lcm = (a*b);
//	cout <<"lcm: "<<lcm<<endl;
	ll pre[40000];
	pre[0] = 0;
	for (ll i=1; i<=lcm; i++) {
		if ((i%a)%b != (i%b)%a) {
			pre[i] = pre[i-1]+1;
		} else pre[i] = pre[i-1];
//		cout << "pre["<<i<<"] = "<<pre[i]<<endl;
	}
//	cout << "pre[lcm]: "<<pre[lcm]<<endl;
	for (int i=1; i<=q; i++) {
		ll x, y; cin >> x >> y;
		ll ans = 0;
		ans -= pre[lcm]*((x-1)/lcm)+pre[(x-1)%lcm];
		ans += pre[lcm]*(y/lcm)+pre[y%lcm];
		cout << ans <<" ";
	}cout << endl;
}
int main() {
	//local variables

	//input
	ll t; cin >> t;
	for (int i=1; i<=t; i++) {
		solve();
	}
	//main

	//output

	return 0;
}
