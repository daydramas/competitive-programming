#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables
int N;
int A[20];
int ans = 0;
int v[20][20];

//functions
bool ok(int l, int r) {
	for (int i=l; i<r; i++) {
		if (A[i] > A[i+1]) return false;
	}
	return true;
}
void search(int l, int r) {
	if (v[l][r]) return;
	v[l][r] = true;
//	cout <<l <<" " <<r <<endl;
	if (ok(l, r)) {
		ans = max(ans, r-l+1);
		return;
	}
	int mid = (l+r)/2;
	search(l, mid);
	search(mid+1, r);
}
int main() {
	//local variables

	//input
	cin >> N;
	for (int i=1; i<=N; i++) cin >> A[i];
	memset(v, 0, sizeof(v));
	//main
	search(1, N);
	//output
	cout << ans << endl;
	return 0;
}
