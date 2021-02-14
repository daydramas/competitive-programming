#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n, m;
	cin >> n >> m;
	int matrix [51][51];
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		bool ok = true;
		for (int j=1; j<=m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j]) ok = false;
		}
		if (ok) cnt++;
	}
	int cnt2 = 0;
	for (int i=1; i<=m; i++) {
		bool ok = true;
		for (int j=1; j<=n; j++) {
			if (matrix[j][i]) ok = false;
		}
		if (ok) cnt2++;
	}
	cnt = min(cnt, cnt2);
	if (cnt%2) {
		cout <<"Ashish"<<endl;
	} else {
		cout <<"Vivek"<<endl;
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
