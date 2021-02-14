#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, k; cin >> n >> k;
	ll asum = 0;
	ll a[50], b[50];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		asum += a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+n);
	for (int i=0; i<k; i++) {
		if (a[i] < b[n-i-1]) {
			asum += b[n-i-1]-a[i];
		}
	}
	cout << asum << endl;
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
