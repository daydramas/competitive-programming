#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[n];
	vector<int> a2;
	int s = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] >= 0) {
			if (s!=0) a2.push_back(s);
			s=0;
			a2.push_back(a[i]);
		} else s += a[i];
	}
	if (s!=0) a2.push_back(s);
	int ans = 0;
//	for (int i : a2) co/
	for (int i=0; i<a2.size(); i++) {
		int sum = 0; int mx = -100;
		for (int j=i; j<a2.size(); j++) {
			sum += a2[j]; mx = max(mx, a2[j]);
			ans = max(ans, sum-mx);
//			cout << sum <<" "<<mx<<endl;
		}
	}
	cout << ans << endl;
}
int main() {
	//local variables

	//input
	int t=1;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
