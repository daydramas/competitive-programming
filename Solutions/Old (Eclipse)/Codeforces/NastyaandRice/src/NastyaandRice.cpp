#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long
//global variables

//functions
void solve() {
	ll n, a, b, c, d; cin >> n;
	cin >> a >> b >> c >> d;

	bool ok = true;
	if (n*(a-b) > (c+d)) ok = false;
	if (n*(a+b) < (c-d)) ok = false;
	if (ok) {
		cout << "Yes"<<endl;
	} else cout <<"No"<<endl;
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
