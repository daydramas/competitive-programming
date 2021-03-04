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
		vector<int> a(n); EACH(x, a) cin >> x;
		int c=0, i=0, j=0, ans=0;
		vector<int> freq(1000001,0);
		while(i<n && j<n) {
			int nc = c;
			if(!freq[a[j]]) nc += a[j];
			if(nc <= k) {
				freq[a[j]]++;
				j++;
				c = nc;
				ans = max(ans, j-i);
			}
			else {
				freq[a[i]]--;
				if(!freq[a[i]]) c -= a[i];
				i++;
			}
		}
		cout << ans << '\n';
	}

}