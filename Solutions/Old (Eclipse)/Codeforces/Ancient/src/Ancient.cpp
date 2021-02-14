#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
ll pwr[61];

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);

	if (a%b) {
		cout << "-1"<<endl;
		return;
	}
	if (a==b) {
		cout <<"0"<<endl;
		return;
	}
	ll n = a/b;
	ll nw = -1;
	for (int i=1; i<=60; i++) {
		if (n==pwr[i]) nw=i;
	}
	if (nw == -1) {
		cout << "-1"<<endl;
	} else {
		ll ans = nw / 3;
		ll rem = nw % 3;
		if (rem == 1 || rem==2) {
			ans++;
		}
		cout << ans << endl;
	}

}
int main() {
	//local variables
	pwr[0]=1;
	for (int i=1; i<=60; i++) {
		pwr[i] = pwr[i-1]*2;
//		cout << i <<" : " << pwr[i]<<endl;
	}
	//input
	int t; cin >> t;
	for (int i=0; i<t; i++) solve();

	//main

	//output

	return 0;
}
