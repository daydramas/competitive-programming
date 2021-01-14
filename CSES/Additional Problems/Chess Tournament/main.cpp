#include "bits/stdc++.h"
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

using pii = pair<int,int>;

priority_queue<pii> pq;
pii fro() {
    pii x = pq.top(); pq.pop();
    return x;
}

int main() {

    int n; vector<pii> a,t;


    cin >> n;
    FOR(i,1,n) {
        int x; cin >> x;
        if (x!=0) pq.push({x,i});
    }
    while(!pq.empty()) {
        pii x = fro(); t.clear();
        while(x.f--) {
            if (pq.empty()) { puts("IMPOSSIBLE"); return 0; }
            pii y = fro(); t.pb(y);
        }
        trav(y, t) {
            a.pb({x.s, y.s});
            if (y.f!=1) pq.push({y.f-1, y.s});
        }
    }
    cout<<a.size()<<"\n";
    trav(x,a) cout << x.f <<" "<<x.s<<"\n";

}