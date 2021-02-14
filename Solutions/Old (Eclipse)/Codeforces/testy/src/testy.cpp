#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {

}
int main() {
	//local variables

	//input
//	int t; cin >> t;
//	for (int i=0; i<t; i++) solve();
	int dp[70];
	for (int i=0; i<=69; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i=0; i<=69; i++) {
		if (i+2 <= 69) dp[i+2] += dp[i];
		if (i+5 <= 69) dp[i+5] += dp[i];
	}
	cout << dp[69]<<endl;;
	//main

	//output

	return 0;
}
