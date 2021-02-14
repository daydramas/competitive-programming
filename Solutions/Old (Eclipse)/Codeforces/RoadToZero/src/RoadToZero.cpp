#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
//global variables
void solve() {
	ll x, y; cin >> x >> y;
	ll a, b; cin >> a >> b;
	ll mx = max(x, y);
	ll mn = min(x, y);
	ll ans = min(mn*b, 2*a*mn) + (mx-mn)*a;
	ans = min(ans, a*(x+y));

	cout << ans << endl;
}
//functions

int main() {
	//local variables

	//input
	int t; cin >> t;

	for (int i=0; i<t; i++) solve();
	//main

	//output

	return 0;
}
