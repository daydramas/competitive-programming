/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-06
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

ll cdiv(ll a, ll b) {
	ll c = a/b;
	if(a % b) c++;
	return c;
}

vector<ll> a, b, o;

bool comp(int x,  int y) {
	return a[x] < a[y];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	
	while(t--) {
		ll A, B, n; cin >> A >> B >> n;
		a = b = o = vector<ll>(n);
		EACH(x, a) cin >> x;
		EACH(x, b) cin >> x;
		F0R(i,n) o[i] = i;
		sort(ALL(o), comp);
		bool yes = true;
		F0R(j,n) {
			int i = o[j];
			ll K = b[i] / A;
			if(b[i] % A) K++;
			B = B - (K-1) * a[i];
			if(B <= 0) { yes = false; break; }
			B -= a[i];
		}
		cout << (yes ? "YES" : "NO") << '\n';
	}

}