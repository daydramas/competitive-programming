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

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, lz = 0, res = 0;
    Node(int lo,int hi): lo(lo), hi(hi) {}
    void upd(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) lz += x;
        else push(), l->upd(L, R, x), r->upd(L, R, x);
        if (lz) res=hi-lo;
        else res=(l?l->res:0)+(r?r->res:0);
    }
    void push() {
        if (!l) {
            int mid = lo+(hi-lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
    }
};


struct line { int i, y1, y2; };

int n;
map<int,vector<line>> M;
int main() {

    cin >> n;
    F0R(i,n) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        M[x1].pb({1, y1, y2});
        M[x2].pb({-1, y1, y2});
    }
    Node* root = new Node(-1e6, 1e6);
    ll ans=0, lst=-1e6;
    trav(X, M) trav(p, X.s) {
        ans += (X.f-lst) * root->res;
        // cout <<"("<<X.f<<"-"<<lst<<") * "<<root->res<<"\n";
        root->upd(p.y1, p.y2, p.i);
        // cout <<"upd("<<p.y1<<","<<p.y2<<","<<p.i<<")\n";
        lst=X.f;
    }
    cout << ans;
}