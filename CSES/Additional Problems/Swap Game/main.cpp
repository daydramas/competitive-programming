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

using pi = pair<int, int>;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
__gnu_pbds::gp_hash_table<string,int,hash<string>> d({},{},{},{},{1<<16});

int main() {
    vector<pi> m;
    string o, t, r;

    F0R(i,9) { cin >> t; o += t; }
    r = "123456789";
    F0R(i,3) F0R(j,3) {
        if (i+1 < 3) m.pb({3*i+j, 3*(i+1)+j});
        if (j+1 < 3) m.pb({3*i+j, 3*i+j+1});
    }
    queue<pair<string,int>> Q; Q.push({o,0});
    while(1) {
        auto x=Q.front(); Q.pop();
        if (x.f == r) { cout << x.s; return 0; }
        trav(a, m) {
            swap(x.f[a.f], x.f[a.s]);
            if (!d[x.f]) {
                d[x.f] = x.s+1;
                Q.push({x.f, x.s+1});
            }
            swap(x.f[a.f], x.f[a.s]);
        }
    }
}