#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, m; cin >> n >> m;
	if (n == 1){
		cout << 0 << endl;
		return;
	} else if (n == 2) {
		cout << m << endl;
	} else {
		cout << 2*m << endl;
	}
//	if (n%2) {
//		cout << m+m << endl;
//	} else {
//		ll ans = m+m;
//		if (((2*m)%n)==0) {
//			ans  -= (2*m)/n;
//		} else ans -= (2*m)/n+1;
//		cout << ans << endl;
//	}
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
