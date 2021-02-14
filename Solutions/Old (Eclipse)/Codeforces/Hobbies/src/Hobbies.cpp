#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[1025];
	set<int> S;
	int ex = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ex ^= a[i];
		S.insert(a[i]);
	}
	if (ex == 0) ex = 1;
	for (int ex=1; ex <=1024; ex++) {
		bool ok = true;
		for (int i=0; i<n; i++) {
			int val = ex ^ a[i];
			if (S.find(val) == S.end()) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << ex << endl;
			return;
		}
	}
	cout << "-1" << endl;
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
