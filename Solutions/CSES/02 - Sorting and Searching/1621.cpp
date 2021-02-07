/*
============================================================================
 Name:		CSES Distinct Numbers
 Link:		https://cses.fi/problemset/task/1621
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	static int n, a[N];
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

	sort(a, a+n);
	int ans = 1;
	for(int i=1; i<n; i++) ans += a[i] != a[i-1];
	cout << ans << '\n';
}