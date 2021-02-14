#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[1004];
	for (int i=1; i<=n; i++) cin >> a[i];
	ll l=0, r=n+1, l1=0, r1=0, l2=0, r2=0;
	int c = 0;
	int moves =0;
	while(abs(l-r) > 1) {
//		cout << c <<" " << l <<" " << r << endl;
		if (c == 0) {
			ll cur = 0;
			while(l+1 < r && cur <= r1) {
				cur += a[++l];
			}
			l1 = cur;
			l2 += cur;
		}
		else {
			ll cur = 0;
			while(l < r-1 && cur <= l1) {
				cur += a[--r];
			}
			r1 = cur;
			r2 += cur;
		}
		c = 1-c;
		moves++;
	}
	cout << moves << " " << l2 <<" " << r2 << endl;
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
