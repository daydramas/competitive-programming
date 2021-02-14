#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define ll long long

//global variables

//functions
void solve() {
	int n;
	int a[200005];
	int b[200005];
	int in[200005];
	int cnt[200005];
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		in[a[i]] = i;
		cnt[i] = 0;

	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
		int dif = i-in[b[i]];
//		cout << i <<" - "<<in[b[i]]<<endl;
		dif =(dif+n+n)% n;
//		cout << dif << endl;
		cnt[dif]++;
	}
	int ans = 0;
	for (int i=0; i<n; i++) ans = max(ans, cnt[i]);
	cout << ans << endl;
}
int main() {
	//local variables

	//input
	solve();

	//main

	//output

	return 0;
}
