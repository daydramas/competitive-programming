#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>

//global variables
int m, n;
int l[100005];
pii l2[100005];
int ans[100005];

//functions

int main() {
	//local variables

	//input
	cin >> n >> m;
	int sum = 0;
	for (int i=1; i<=m; i++) {
		cin >> l[i];
		sum += l[i];
		l2[i] = pii(l[i], i);
	}
	sort(l2+1, l2+m+1);
	//main
	if (m > n || sum < n) {
		cout <<"-1"<<endl;
		return 0;
	}
	int delta = sum-n;
	int nextplace = n;
	bool ok = true;
	for (int i=m; i>=1; i--) {
//		nextplace -= min(delta, 1);
		ans[l2[i].second] = nextplace-l2[i].first+1;
//		if (ans[l2[i].second] < 1) ok = false;
		int np = min(delta, l2[i].first-1);
		nextplace -= (l2[i].first-np);
		delta -= np;
//		cout << np <<" " << nextplace<<endl;

	}
	if (ans[l2[1].second] != 1) ok = false;
	//output
	if (ok) {
		for (int i=1; i<=m; i++) cout << ans[i]<<" ";
		cout << endl;
	} else cout <<"-1"<<endl;
	return 0;
}
