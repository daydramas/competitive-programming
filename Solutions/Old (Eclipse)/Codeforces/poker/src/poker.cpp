#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
//	cout << min(n/k, m) << endl;
//	if (n/k >= m) {
//		cout << m << endl;
//	} else {
//		int r = m-(n/k);
//		int r2 = r/(k-1);
//		if (r%(k-1)) r2 += (k-1);
//		cout << -(n/k) + m<<endl;
//	}

	int w = (min(n/k, m));
	if (m > w) {
		int cnt = 0;
		if ((m-w)%(k-1)) cnt++;
		cout << w - (((m-w)/(k-1)) + cnt) << endl;
	} else {
		cout << w << endl;
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
