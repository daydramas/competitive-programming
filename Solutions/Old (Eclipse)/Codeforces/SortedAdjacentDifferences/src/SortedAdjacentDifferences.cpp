#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; cin >> n;
	ll a[100005];
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int mid = (1+n)/2;
	int l=mid, r=mid+1;
	vector<ll> ans;
	int last = 0;
	while(l>1 || r<n) {
		if (r>=n) {
			ans.push_back(a[l]);
			l--;
			last = 1;
			continue;
		}
		if (l<=1) {
			ans.push_back(a[r]);
			r++;
			last = 2;
			continue;
		}
		ll d1 = abs(a[l]-a[l-1]);
		ll d2 = abs(a[r+1]-a[r]);
		if (d1<d2) {
			ans.push_back(a[l]);
			l--;
			last = 1;
		} else {
			ans.push_back(a[r]);
			r++;
			last = 2;
		}
	}
	if (last == 1) {
		ans.push_back(a[r]);
		ans.push_back(a[l]);
	} else {
		ans.push_back(a[l]);
		ans.push_back(a[r]);
	}
	for (ll i : ans) cout << i <<" ";
	cout << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) solve();

	//main

	//output

	return 0;
}
