/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-08
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F           first
#define S           second
#define PB          push_back
#define ALL(x)      begin(x), end(x)
#define SZ(x)       int((x).size())
#define FOR(i,a,b)  for(int i=(a); i<=(b); i++)
#define F0R(i,x)    FOR(i,0,(x)-1)
#define ROF(i,a,b)  for(int i=(b); i>=(a); i--)
#define R0F(i,x)    ROF(i,0,(x)-1)
#define REP(x)      F0R(_,x)
#define EACH(a,x)   for(auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	REP(t) {
		int n, k; cin >> n >> k;
		vi a(n); EACH(x, a) cin >> x;
		sort(ALL(a));
		int ans = 0;
		while(a.size() && a.back() >= k) {
			ans++; a.pop_back();
		}
		int i=0, j=SZ(a)-1;
		while(i<j) {
			if(a[i]+a[j] >= k) ans++, i++, j--;
			else i++;
		}
		cout << ans << '\n';
	}

}