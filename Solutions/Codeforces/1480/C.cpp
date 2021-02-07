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

int n, qrys = 0;
int a[100005];


void query(int mid) {
	if(a[mid]) return;
	if(mid <= 0) return;
	if(mid > n) return;
	cout << "? " << mid << '\n';
	cout.flush();
	cin >> a[mid];
	qrys++;
}
int qry(int mid) {
	query(mid + 1);
	query(mid);
	query(mid - 1);
	if(a[mid] > a[mid+1]) return 1;
	if(a[mid] > a[mid-1]) return -1;
	// if(a[mid] < a[mid + 1] && a[mid] < a[mid + 1]) return 1;
	return 0;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	memset(a, 0, sizeof(a));
	cin >> n;
	int lo = 1, hi = n;
	a[0] = a[n+1] = 1e9;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int v = qry(mid);
		if(v == 0) {
			cout << "! " << mid << '\n';
			cout.flush();
			exit(0);
		} else if (v == 1) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}

	}
	


}