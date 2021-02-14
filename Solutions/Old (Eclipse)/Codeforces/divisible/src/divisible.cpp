#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n, k; cin >> n >> k;
//	ll ans = (k/(n-1))*(n-1) + (k%n);
	ll ans = k;
	if (k%(n-1) == 0) {
		ans += (k/(n-1))-1;
	} else ans += (k/(n-1));
//	cout << "k/n: "<<k/n<<endl;
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
