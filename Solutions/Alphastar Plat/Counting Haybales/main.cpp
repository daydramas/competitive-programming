#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n, q;

struct lsegt {
    using T = long long;
    T st[(maxn+5)*4], mn[(maxn+5)*4], lz[(maxn+5)*4];
    T ID=0; T comb(T i, T j) { return i+j; }
    void init() {
        for(int i=0; i<maxn*2; i++) st[i]=lz[i]=ID, mn[i]=0; }
    void pull(int i) {
        mn[i] = min(mn[i*2], mn[i*2+1]);
        st[i] = comb(st[i*2],st[i*2+1]); }
    void push(int i, int l, int r) {
        st[i]+=(r-l+1)*lz[i];
        mn[i]+=lz[i];
        if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
        lz[i]=0;
    }
    void upd(int L, int R, T v, int i=1, int l=0, int r=maxn) {
        push(i,l,r); if(R<l || L>r) return;
        if(L<=l && R>=r) { lz[i]=v; push(i,l,r); return; }
        int m=(l+r)/2; upd(L,R,v,i*2,l,m);
        upd(L,R,v,i*2+1,m+1,r); pull(i);
    }
    T sum(int L, int R, int i=1, int l=0, int r=maxn) {
        push(i,l,r); if(R<l || L>r) return ID;
        if(L<=l && R>=r) return st[i]; int m=(l+r)/2;
        return comb(sum(L,R,i*2,l,m), sum(L,R,i*2+1,m+1,r));
    }
    T rmq(int L, int R, int i=1, int l=0, int r=maxn) {
        push(i,l,r); if(R<l || L>r) return 1e9;
        if(L<=l && R>=r) return mn[i]; int m=(l+r)/2;
        return min(rmq(L,R,i*2,l,m), rmq(L,R,i*2+1,m+1,r));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    // cout << "q="<<q<<"\n";
    lsegt S;
    S.init(); for(int i=0; i<n; i++) {
        int a; cin >> a; S.upd(i,i,a);
    }
    while(q--) {
        char ch; cin >> ch;
        // cout <<"q="<<q<<" | ch="<<ch<<"\n";
        if(ch == 'P') {
            int a,b,c; cin >> a >> b >> c;
            S.upd(--a,--b,c);
        } else if(ch == 'M') {
            int a,b; cin >> a >> b;
            cout << S.rmq(--a,--b) <<"\n";
        } else if(ch == 'S') {
            int a,b; cin >> a >> b;
            cout << S.sum(--a,--b) <<"\n";
        }
    }
}