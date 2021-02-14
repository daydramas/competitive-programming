#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[200005];
	int m[200005];
	for (int i=1; i<=n; i++) {
		a[i] = 0, m[i] = 0;
	}
	set<int> S;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		m[a[i]]++;
		S.insert(a[i]);
	}
	int M = -1;
	for (int i=1; i<=n; i++) {
		M = max(M, m[i]);
	}
	int K = S.size();
	int ans = max(min(M-1, K), min(M, K-1));
	cout << ans << endl;

}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) {
		solve();

	}
	//main

	//output

	return 0;
}
