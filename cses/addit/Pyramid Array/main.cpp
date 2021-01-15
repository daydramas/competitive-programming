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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    Tree<int> t;
    int n; ll ans=0; cin >> n;
    vector<pair<int,int>> a(n);

    F0R(i,n) {
        cin >> a[i].f;
        a[i].s=i;
        t.insert(i);
    } sort(all(a));
    F0R(i,n) {
        auto x = a[i];
        int y = t.order_of_key(x.s);
        ans += min(y, n-i-y-1);
        // cout << min(y, n-i-y-1) <<"\n";
        t.erase(x.s);
    }
    cout << ans;

}