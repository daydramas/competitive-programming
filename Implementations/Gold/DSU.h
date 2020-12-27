const int maxn = 1e5;

int D[maxn+5];
void init() { for(int i=0; i<maxn; i++) D[i]=-1; }
int par(int x) { return D[x]<0 ? x : D[x]=par(D[x]); }
bool comb(int x, int y) {
    x=par(x), y=par(y); if(x==y) return 0;
    D[x]+=D[y], D[y]=x; return 1;
}