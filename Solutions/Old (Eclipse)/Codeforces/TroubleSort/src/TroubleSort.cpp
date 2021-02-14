#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; int a[501], b[501];
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	int s = b[1];
	for (int i=2; i<=n; i++) if (b[i]!=s) {
		cout <<"Yes"<<endl;
		return;
	}
	bool ok = true;
	for (int i=1; i<n; i++) {
		if (a[i+1]<a[i]) ok = false;
	}
	if (!ok) cout <<"No"<<endl;
	else cout <<"Yes"<<endl;
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
