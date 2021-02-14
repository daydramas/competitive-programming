#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>

//global variables

//functions
void solve() {
	int n; pii p[101];
	cin >> n;
	for (int i=1; i<=n; i++) cin >> p[i].first >> p[i].second;
	bool ok = true; int cnt = 0, cnt2 = 0;
	for (int i=1; i<=n; i++) {
		cnt = p[i].first, cnt2 = p[i].second;
		if (cnt < cnt2) ok = false;
		if (i>1 && cnt-p[i-1].first < cnt2-p[i-1].second) ok=false;
		if (i>1 && p[i].first < p[i-1].first) ok=false;
		if (i>1 && p[i].second < p[i-1].second) ok=false;
	}
	cout << (ok?"YES":"NO") << endl;
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
