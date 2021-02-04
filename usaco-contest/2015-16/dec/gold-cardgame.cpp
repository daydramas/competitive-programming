/*
============================================================================
 Name:		High Card Low Card (Gold)
 Link:		http://usaco.org/index.php?page=viewproblem2&cpid=573
 Author:	Dong Liu
 Date:		2021-02-04
 Status:	*x*x**x*x*xx*x*
 Tags:		Greedy
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

#define F			first
#define S			second
#define PB			push_back
#define ALL(x)		begin(x), end(x)
#define SZ(x)		int((x).size())
#define F0R(i,a)	for(int i=0; i<(a); i++)
#define FOR(i,a,b)	for(int i=(a); i<=(b); i++)
#define R0F(i,a)	for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b)	for(int i=(b); i>=(a); i--)
#define EACH(a,x)	for (auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int n; cin >> n;
	VI total(n+n), e1(n/2), e2(n/2), b1, b2;
	EACH(x, e1) { cin >> x; total[--x] = 1; }
	EACH(x, e2) { cin >> x; total[--x] = 1; }
	R0F(i,n+n) if(!total[i]) {
		if(SZ(b1)*2 < n) b1.PB(i);
		else b2.PB(i);
	}
	int ans = 0;
	sort(ALL(e1)); sort(ALL(e2));
	sort(ALL(b1)); sort(ALL(b2));
	int i=0, j=0;
	while(i < n/2 && j < n/2) {
		if(e1[i] > b1[j]) j++;
		else ans++, i++, j++;
	}
	i=0, j=0;
	while(i < n/2 && j < n/2) {
		if(e2[i] < b2[i]) j++;
		else ans++, i++, j++;
	}
	cout << ans << '\n';
}