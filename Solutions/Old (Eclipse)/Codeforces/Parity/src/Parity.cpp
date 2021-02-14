#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n, k; cin >> n >> k;
	ll n2 = n%2;
	ll k2 = k%2;
	ll sum = (k-1);
	if (n-(sum) > 0 && (n-(sum))%2 == 1) {
		cout << "YES"<<endl;
		for (int i=1; i<k; i++) cout << "1 ";
		cout << n-(sum) << endl;
		return;
	}
	sum = (k-1)*2;
	if (n-(sum) > 0 && (n-(sum))%2 == 0) {
		cout << "YES"<<endl;
		for (int i=1; i<k; i++) cout << "2 ";
		cout << n-(sum) << endl;
		return;
	}
	cout << "NO"<<endl;
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
