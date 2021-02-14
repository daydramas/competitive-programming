#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>

//global variables
int n;
int a[100005];

//functions

int main() {
	//local variables

	//input
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
//		cout << a[i]<<endl;
	}

	// main
	vector<pii> V;
	int ans = 0;
	for (int i=1; i<=n; i++) {
		for (pii j : V) {
			cout << j.first<<" "<<a[i]<<endl;
//			if (j.first+a[i] != 0) {
//				ans++;
//			}
//			else {
			V.push_back(pii(j.first+a[i], j.second+1));
//			}
		}
		V.push_back(pii(a[i], 1));
	}
	for (pii j : V) {
		if (j.first != 0) ans++;
	}
	// output
	cout << ans << endl;
	return 0;
}
