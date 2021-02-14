#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n, m; cin >> n >> m;
	bool b = (n==1) || (m==1) || (n==2 && m==2);
	if (b) cout <<"YES"<<endl;
	else cout << "NO"<<endl;

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
