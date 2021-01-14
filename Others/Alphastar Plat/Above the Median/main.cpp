#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

using T = long long; T B[(maxn*2)+5];
void init() { for(int i=0; i<=maxn; i++) B[i]=0; }
void upd(int i) { for(i+=maxn; i<maxn*2; i+=i&(-i)) B[i]++; }
T qry(int i) { T R=0; for(i+=maxn; i; i-=i&(-i)) R+=B[i];
	return R; }

int n; T x;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    init(); cin >> n >> x; upd(0);
    T s=0, r=0; while(n--) {
        T a; cin >> a; s+=(a>=x?1:-1);
        r += qry(s); upd(s);
    }
    cout << r <<"\n";
}