#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4;
#define vi vector<int>
#define pi pair<int,int>
#define f first
#define s second
#define vpi vector<pi>
#define pb push_back

int n, m, ans[maxn];
vpi g[maxn]; vpi e[maxn];

struct ms2l {
    set<pair<int,pi>> S;

    ms2l() {}
    void mergeInto(ms2l* x) {
        for(auto y : x->S) add(y);
    }
    void add(pair<int,pi> y) {
        if(S.count(y)) {
            S.erase(y);
        } else {
            S.insert(y);
        }
    }
    int min() {
        if(S.empty()) {
            return -1;
        } else {
            return S.begin()->f;
        }
    }
    ms2l* merge(ms2l* x) {
        if(S.size() > x->S.size()) {
            mergeInto(x);
            return this;
        } else {
            x->mergeInto(this);
            return x;
        }
    }
};
ms2l* M[maxn];

void dfs(int a, int c) {
    for(pi x : g[a]) {
        int b=x.f, i=x.s;
        if(b==c) continue;
        dfs(b, a);
        ans[i] = M[b]->min();
        M[a] = M[a]->merge(M[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b; --a, --b;
        g[a].pb({b,i-1}); g[b].pb({a,i-1});
    }
    for(int i=0; i<n; i++) {
        M[i] = new ms2l();
    }
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        M[a]->add({c, {a,b}});
        M[b]->add({c, {a,b}});
    }
    dfs(0,0);
    for(int i=0; i<n-1; i++) cout << ans[i] << '\n';
}