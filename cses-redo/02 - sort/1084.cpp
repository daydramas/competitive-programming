/*
============================================================================
 Name:		CSES Apartments
 Link:		https://cses.fi/problemset/task/1084/
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	static int n, m, k, i, j, a[N], b[N];

	cin >> n >> m >> k;
	for(i=0; i<n; i++) cin >> a[i];
	for(j=0; j<m; j++) cin >> b[j];
	sort(a, a+n); sort(b, b+m);
	int ans; ans = i = j = 0;
	while(i < n && j < m) {
		if(abs(a[i]-b[j]) <= k) ans++, i++, j++;
		else if(a[i] < b[j]) i++;
		else j++;
	}
	cout << ans << '\n';
}