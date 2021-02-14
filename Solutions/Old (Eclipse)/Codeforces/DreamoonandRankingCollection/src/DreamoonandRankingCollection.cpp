#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int t, n, x, a[100];

//functions

int main() {
	//local variables

	//input
	cin >> t;
	for (int i=1; i<=t; i++) {
		cin >> n >> x;
		for (int j=0; j<n; j++) {
			cin >> a[j];
		}
		int ans = -1;
		map<int, int> mark;
		for (int j=0; j<n; j++) {
			mark[a[j]] = 1;
//			cout << "marking "<<a[j]<<endl;
			int nx = x;
			for (int k=1; ; k++) {
				if (!mark[k]) {
					nx--;
//					cout <<"using "<<k<<endl;
				}
				ans = max(ans, k);
				if (nx < 0) break;
			}
		}
		cout << ans -1 << endl;
	}
	//main

	//output

	return 0;
}
