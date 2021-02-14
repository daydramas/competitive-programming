#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[100005], b[100005];
	int one = 100005, none = 100005;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == 1 && one == 100005) one = i;
		if (a[i] == -1 && none == 100005) none = i;
	}
	for (int j=1; j<=n; j++) {
		cin >> b[j];
	}
	bool ok = true;
	for (int i=n; i>=1; i--) {
		if (b[i] < a[i]) {
			if (none >= i) {
				ok = false;
				break;
			}
		}
		if (b[i] > a[i]) {
			if (one >= i) {
				ok = false;
				break;
			}
		}
	}
	cout << (ok?"YES":"NO")<<endl;
}
int main() {
	//local variables

	//input
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) solve();

	//main

	//output

	return 0;
}
