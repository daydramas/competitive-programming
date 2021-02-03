/*
============================================================================
 Name:		Telephone
 Link:		http://usaco.org/index.php?page=viewproblem2&cpid=1090
 Author:	Dong Liu
 Date:		2021-02-03
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

	int n, k;
	cin >> n >> k;
	VI a(n+1), b[k+1], c[k+1];
	FOR(i,1,n) { 
		cin >> a[i];
		b[a[i]].PB(i);
	}
	FOR(i,1,k) {
		string s; cin >> s;
		FOR(j,1,k) if(s[j-1] == '1')
			c[i].PB(j);
	}
	VI dist(n+1, 1e9);
	dist[1] = 0;
	priority_queue<PI> pq;
	pq.push({-0, 1});
	while(SZ(pq)) {
		PI x = pq.top(); 
		x.F = -x.F; pq.pop();
		if(x.F > dist[x.S]) continue;
		EACH(y,c[a[x.S]]) EACH(z,b[y]) {
			int nd = x.F + abs(z - x.S);
			if(dist[z] > nd) {
				dist[z] = nd;
				pq.push({-nd, z});
			}
		}
	}
	cout << ( dist[n] == 1e9 ? -1 : dist[n] ) << '\n';

}