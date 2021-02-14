#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	ll n; cin >> n;
	if (n < 4) {
		cout <<"-1" <<endl;
	} else {
		int i=n; if (n%2 == 0) i--;
		while(i >= 1) {
			cout << i <<" ";
			i-=2;
		}
		i = 6;
		cout << "4 2 ";
		while(i <= n) {
			cout << i <<" ";
			i += 2;
		}
		cout << endl;
	}

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
