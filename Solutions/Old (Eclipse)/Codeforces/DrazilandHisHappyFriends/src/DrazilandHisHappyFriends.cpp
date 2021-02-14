#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int n, m, n1, m1;
bool happy1[100], happy2[100];
//functions

int main() {
	//local variables

	//input
	cin >> n >> m;
	fill(happy1, happy1+n, false);
	fill(happy2, happy2+m, false);
	cin >> n1; for (int i=0; i<n1; i++) { int j; cin >> j; happy1[j] = true; }
	cin >> m1; for (int i=0; i<m1; i++) { int j; cin >> j; happy2[j] = true; }

	//main
	int mx = max(n, m)*max(n, m);
	for (int i=0; i<mx; i++) {
		happy2[i%m] |= happy1[i%n];
		happy1[i%n] |= happy2[i%m];
	}
	//output
	bool ok = true;
	for (int i=0; i<n; i++) ok &= happy1[i];
	for (int j=0; j<m; j++) ok &= happy2[j];
	cout << (ok?"Yes":"No") << endl;
	return 0;
}
