#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, k; cin >> n >> k;
	string str; cin >> str;
	sort(str.begin(), str.end());
	string ans = "";
	if (str[0] == str[k-1]) {
		if (str[k] == str[n-1]) {
			ans += str[0];
			int m = n-k;
			int num = m/k;
			if (m%k != 0) {
				num++;
			}
			for (int i=0; i<num; i++) ans += str[k];
		} else {
			ans += str[0];
			for (int i=k; i<n; i++) ans += str[i];
		}
	} else {
		ans += str[k-1];
	}
	cout << ans << endl;
}
int main() {
	//local variables
	int t; cin >> t;
	for (int i=1; i<=t; i++) {
		solve();

	}
	//input

	//main

	//output

	return 0;
}
