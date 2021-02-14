#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n; cin >> n;
	ll a[8004];
	for (int i=1; i<=n; i++) cin >> a[i];
//	set<int> S;
	map<int, int> M;
	int cnt = 0;
//	ll sum = a[1];
	ll pre[8004]; pre[0] =0 ;
//	for (int i=2; i<=n; i++) {
//		pre[i] = pre[i-1]+a[i];
//		bool found = false;
//		for (int j=1; j<i; j++) {
//			if (pre[j] > a[i] && S.find(pre[j]-a[i]) != S.end()) {
//				found = true;
//				break;
//			}
//		}
//		if (found) cnt++;
//		S.insert(sum);
//		sum += a[i];
//	}
//	cout << cnt <<endl;
	pre[1] = a[1];
	M[0] = 0;
	for (int i=2; i<=n; i++) {
		pre[i] = pre[i-1]+a[i];
		M[pre[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		for (int j=n; j>=1; j--) {
//			if (pre[j] <= a[i]) break;
			ll val = pre[j]-a[i];
			if ((M[val] || val==0) && i-M[val] >= 2) {
				cnt++;
				cout <<"A: "<<a[i]<<" "<<i<<"-"<<M[val]<<endl;
				break;
			}
		}
	}
	cout << cnt << endl;

}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=0; i<t; i++ ) solve();

	//main

	//output

	return 0;
}
