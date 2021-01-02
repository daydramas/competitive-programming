const int maxn = 1e5; using T = long long;
using Edge = pair<T, pair<int, int>>;
int D[maxn+5]; vector<Edge> E;
void init() { for(int i=0; i<maxn; i++) D[i]=-1; }
void ae(int a, int b, T c) { E.push_back({c,{a,b}}); }
int par(int x) { return D[x]<0 ? x : D[x]=par(D[x]); }
bool comb(int x, int y) {
    x=par(x), x=par(y);
    if(x==y) return 0;
    if(D[x] > D[y]) swap(x,y);
    D[x]+=D[y], D[y]=x;
    return 1;
}
T mst() {
    sort(E.begin(), E.end()); T ans=0;
    for(Edge &e : E) if(comb(e.s.f, e.s.s))
        ans += e.f;
    return ans;
}