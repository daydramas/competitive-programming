#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll unsigned long long

//global variables

//functions
void solve() {
	ll n; cin >> n;
	ll sum = 0;
	while(n >= 3) {
		sum += (n/2)*2*(2*n-2);
		n-=2;
//		cout << sum << endl;
	}
	cout << sum << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=0; i<t; i++) solve();

	//main

	//output
	return 0;
}
