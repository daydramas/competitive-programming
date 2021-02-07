/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-07
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F			first
#define S			second
#define PB			push_back
#define ALL(x)		begin(x), end(x)
#define SZ(x)		int((x).size())
#define F0R(i,a)	for(int i=0; i<(a); i++)
#define FOR(i,a,b)	for(int i=(a); i<=(b); i++)
#define R0F(i,a)	for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b)	for(int i=(b); i>=(a); i--)
#define EACH(a,x)	for(auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vi a(n); EACH(x,a) cin >> x;
	int ans, A, B; ans = A = B = 0;
	F0R(i,n) {
		if(a[i] == A) {
			if(B != a[i]) ans++;
			B = a[i];
		} else if(a[i] == B) {
			if(A != a[i]) ans++;
			A = a[i];
		} else if(i+1<n && a[i+1] == A) {
			if(A != a[i]) ans++;
			A = a[i];
		} else if(i+1<n && a[i+1] == B) {
			if(B != a[i]) ans++;
			B = a[i];
		} else {
			if(A != a[i]) ans++;
			A = a[i];
		}
	}
	cout << ans << '\n';

}