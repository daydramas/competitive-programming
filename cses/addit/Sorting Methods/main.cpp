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

#define ins insert
#define sz size
#define oof order_of_key
#define fbo find_by_order

const int maxn = 2e5+5;
int n, a[maxn], b[maxn];

ll ans1() {
    ll ret=0;
    Tree<int> T;
    FOR(i,1,n) {
        ret += T.sz()-T.oof(a[i]);
        T.ins(a[i]);
    }
    return ret;
}
int ans2() {
    int ret=0;
    bool c[maxn];
    FOR(i,1,n) c[i]=false;
    FOR(i,1,n) if(!c[i]) {
        int d=a[i];
        while(d!=i) c[d]=1, ret++, d=a[d];
        c[d]=true;
    }
    return ret;
}
int ans3() {
    vi res={0};
    FOR(i,1,n) {
        int lo = 0, hi = res.size()-1;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (res[mid] < a[i]) lo = mid;
            else hi = mid-1;
        }
        if (lo == res.size()-1) res.pb(0);
        res[lo+1] = a[i];
    }
    return n-res.size()+1;
}
int ans4() {
    int e=n+1;
    ROF(i,1,n) {
        if(b[i]<e) e=b[i];
        else return i;
    } return 0;
}
int main() {

    cin >> n;
    FOR(i,1,n) { cin >> a[i]; b[a[i]]=i; }

    cout << ans1() << " " << ans2() << " " << ans3() << " " << ans4();

}