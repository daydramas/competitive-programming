#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define pii pair<int, int>

//global variables
int t, n, a[200005];
int mark[200005][2];
int BIT[200005][2];

//functions
void insert(int i, int in) {
	for (; i<=n; i+=i&(-i)) BIT[i][in] += 1;
}
int sum(int i, int in) {
	int sum = 0;
	for (; i>0; i-=i&(-i)) sum += BIT[i][in];
	return sum;
}
void binary(int in) {
//	if (in == 0) {
	set<int> S;
		for (int i=1; i<=n; i++) {
			if (S.find(a[i]) != S.end()) {
				break;
			}
			S.insert(a[i]);
			insert(a[i], in);
			if (sum(i, in) == i) {
				mark[i][in] = 1;
			}
//			else break;
		}
		return;
//	}
}
int main() {
	//local variables

	//input
	cin >> t;
	for (int i=1; i<=t; i++) {
		cin >> n;
		for (int j=1; j<=n; j++) cin >> a[j];
		memset(mark, 0, sizeof(mark));
		memset(BIT, 0, sizeof(BIT));
		binary(0);
		int start, end; start = 1, end = n;
		while(start < end) {
			swap(a[start], a[end]);
			start++, end--;
		}
		binary(1);
		int cnt = 0;
		vector<pii> v;
		for (int j=1; j<n; j++) {
			if (mark[j][0] && mark[n-j][1]) {
				cnt++;
				v.push_back(pii(j, n-j));
			}
		}
		cout << cnt << endl;
		for (pii a : v) cout << a.first <<" " <<a.second<<endl;
	}
	//main

	//output

	return 0;
}
