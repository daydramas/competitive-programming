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

const int maxn = 205;
int n, m, s[maxn][maxn];

struct DSU {
    struct Node { int v; Node* p;
                    Node(int v, Node* p) v(v), p(p) : {} };
    vector<Node*> D(maxn+5); int n, comp;
    DSU(int _n) { n=_n, comp=n; FOR(i,1,n) D[i] = new Node(i, NULL); }
    int par(int x) { return D[x]->p ? x : D[x]->p=par(D[x]->v); }
    bool comb(int x, int y) {
        x=par(x), y=par(y); if(x==y) return 0;
        D[x]+=D[y], D[y]=x; comps--; return 1;
    }
    DSU* copy(int j) {
        DSU* res = new DSU(n); res->comps = comps;
        for(int i=0; i<maxn; i++) res->D[i]=D[i];
        return res;
    }
};

int main() {

    cin >> n >> m;
    FOR(i,1,m) FOR(j,1,n) cin >> s[i][j];
    DSU* D = new DSU(n);
    while(1) {
        int best = -1;
        FOR(i,1,m) {
            DSU* T = D.copy(m);
        }
        cout << best << "\n";
    }
}