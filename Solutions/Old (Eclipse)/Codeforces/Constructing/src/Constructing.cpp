#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
#define pii pair<int, int>

//global variables

//functions
void solve() {
	int n; cin >> n;
	queue<pii> Q[200005];
//	Q.clear();
	Q[n].push(pii(1, n));

	int ans[n+5]; int in = 1;
	for (int i=n; i>=n; i++) {

	}

	for (int i=1; i<=n; i++) {
		cout << ans[i] <<" ";
	} cout << endl;
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
