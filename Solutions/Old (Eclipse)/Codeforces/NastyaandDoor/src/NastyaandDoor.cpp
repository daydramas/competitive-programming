#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
void solve() {
	int n, k; cin >> n >> k;
	long long a[200005];
	for (int i=1; i<=n; i++) cin >> a[i];
	long long s[200005];
	s[1] = 0;
	for (int i=2; i<n; i++) {
		s[i] = s[i-1] + (a[i] > a[i-1] && a[i] > a[i+1]);
	}
	s[n] = s[n-1];
	int ans = 0, ansi = 1;
//	for (int i=1; i<=n; i++) cout << s[i]<<" ";
//	cout << endl;
	for (int i=1; i<=n; i++) {
		if (i+k <= n+1) {
			if (s[i+k-2]-s[i] > ans){
				ans = s[i+k-2]-s[i];
//				cout << s[i+k] <<" "/<< s[i+1]<<endl;
				ansi = i;
			}
//			cout << s[i+k-1] <<" " << s[i]<<endl;
		}
	}
	cout << ans+1 <<" "<<ansi << endl;

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
