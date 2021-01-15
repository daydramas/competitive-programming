#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int N, comps, *D;
    void clear() { comps=N; D = new int[N+1];
        for(int i=0; i<=N; i++) D[i]=-1; }
    void init(int N) { this->N = N; clear(); }
    int get(int x) { return D[x]<0 ? x : D[x]=get(D[x]); }
    int size(int x) { return -D[get(x)]; }
    bool same(int x, int y) { return get(x)==get(y); }
    bool comb(int x, int y) {
        x=get(x), y=get(y); if(x==y) return 0;
        D[x]+=D[y], D[y]=x; comps--; return 1; }
};

int n, m;
DSU D;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m; D.init(n);
    int largest = 1;
    while(m--) {
        int x, y; cin >> x >> y;
        D.comb(x, y);
        largest = max(largest, D.size(x));
        cout << D.comps << ' ' << largest << '\n';
    }
}