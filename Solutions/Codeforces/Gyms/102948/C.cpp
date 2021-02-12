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

const int X[] = {0,0,-1,1};
const int Y[] = {1,-1,0,0};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int r, c; cin >> r >> c;
	vector<string> grid(r);
	EACH(x,grid) cin >> x;
	bool safe = true;
	F0R(i,r) F0R(j,c) {
		F0R(k,4) {
			int x = i+X[k];
			int y = j+Y[k];
			if(x<0 || x>=r || y<0 || y>=c) continue;
			if(grid[i][j] == 'W' && grid[x][y]=='P') safe = false;
		}
	}
	cout << (safe ? "Yes" : "No") << '\n';
}