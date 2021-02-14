#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	ll sum = 0;
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		int j=0;
		while(j < m) {
			if (s[j] == '.') {
				if ((2*x) > y && (j != m-1 && s[j+1] == '.')) {
					sum += y;
					j++;
				} else sum += x;
			}
			j++;
		}
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
