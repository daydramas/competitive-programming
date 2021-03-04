#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string b; cin >> b;
		int lst = -1;
		for(int i=0; i<n; i++) {
			int v = b[i] - '0';
			if(lst == -1) {
				cout << 1;
				lst = 1 + v;
			} else {
				if(v + 1 != lst) {
					cout << 1;
					lst = 1 + v;
				} else {
					cout << 0;
					lst = v;
				}
			}
		}
		cout << '\n';
	}

}