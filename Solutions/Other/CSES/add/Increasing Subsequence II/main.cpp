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

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 2e5+5;
const int mod = 1e9+7;

struct BIT {

	int n; vector<ll> t;

	BIT(int n_) { n = n_; t.assign(n+1, 0); }

	void upd(int i, ll value) {
		for (; i<=n; i+=i&(-i)) t[i] = (t[i]+value) % mod;
	}

	ll qry(int i) {
		ll sum = 0;
		for(; i>0; i-=i&(-i)) sum = (sum+t[i]) % mod;
		return sum;
	}

};


int main() {
    int n; int a[maxn];
    map<int,int> m;
    cin>>n; F0R(i,n) { cin>>a[i]; m[a[i]]=1; }
    int c=0; trav(x,m) x.s=++c;
    BIT B(c+1); int ans=0;
    F0R(i,n) {
        int x = m[a[i]];
        int val = 1+B.qry(x-1);
        ans = (ans+val) % mod;
        B.upd(x,val);
    }
    cout << ans;
    // int n; pair<int,int> a[maxn];
    // cin >> n; BIT B(n+1);
    // F0R(i,n) { cin >> a[i].f; a[i].s=i; }
    // sort(a, a+n);
    // F0R(i,n) {
    //     int val = B.qry(a[i].s);
    //     B.upd(a[i].s+1, val+1);
    // }
    // cout << B.qry(n+1);

}