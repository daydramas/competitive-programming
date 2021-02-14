#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n;
	cin >> n;
	ll ans = n;
	for (int i=1; ; i++) {
		n = n/2;
		ans += n;
		if (n == 0) break;
	}
	cout << ans << endl;
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
