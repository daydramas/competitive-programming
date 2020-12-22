// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
// #define int long long

int n, m;
string g[maxn];
int ls[maxn];
long long ans[maxn][maxn], ANS[maxn][maxn];

using pi = pair<int,int>;
#define f first
#define s second
#define pb push_back
#define mp make_pair
vector<pi> h; // histograms
vector<int> h2[maxn];
vector<pair<pi,pi>> r; // rectangles

// uf (union find)
int D[maxn+5]; pi P[maxn+5]; int ID=-1e9;
void init() { for(int i=0; i<m; i++) D[i]=ID, P[i]={i,i}; }
int par(int x) { return D[x]<0 ? x : D[x]=par(D[x]); }
bool comb(int x, int y) {
    x=par(x), y=par(y); if(x==y) return 0;
    D[x]+=D[y], D[y]=x;
    P[x]={min(P[x].f,P[y].f), max(P[x].s,P[y].s)};
    return 1;
}
bool cmp(pair<pi,pi> a, pair<pi,pi> b) {
    return (a.s.f > b.s.f);
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("a.in","r", stdin);
    // freopen("a.out","w",stdout);
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> g[i];
    for(int j=0; j<m; j++) ls[j]=-1;
    // for(int i=n-1; i>=0; i--) {
    for(int i=0; i<n; i++) {
        init(); r.clear();
        // cout <<"\n for I="<<i<<"\n";
        for(int j=0; j<m; j++) {
            if(g[i][j]=='*') ls[j]=i;
            h2[i-ls[j]].pb(j);
            // cout <<"i="<<i<<" | link("<<ls[j]-i<<", "<<j<<")\n";
        }
        for(int X=n; X>0; X--) {
            for(auto x : h2[X]) {
                D[x] = -1;
                if((x-1)>=0 && D[x-1]!=ID) comb(x, x-1);
                if((x+1)<m && D[x+1]!=ID) comb(x, x+1);
            }
            for(int Y=0; Y<h2[X].size(); Y++) {
                int y=par(h2[X][Y]);
                if(Y) { int y0=par(h2[X][Y-1]); if(y0==y) continue; }
                r.pb({{i,P[y].f},{i+X,P[y].s+1}});
            }
            h2[X].clear();
        }
        int N = r.size(); sort(r.begin(),r.end(), cmp);
        for(int I=0; I<N; I++) {
            auto a=r[I].f, b=r[I].s;
            ans[b.f-a.f][b.s-a.s]++;
            bool found=false; int fx, fy;
            // if(b.f-a.f==3 && b.s-a.s==2) cout <<"FAIL :C | i="<<i<<"\n";
            for(int J=I+1; J<N; J++) {
                auto c=r[J].f, d=r[J].s;
                int x=min(b.f,d.f)-max(a.f,c.f);
                int y=min(b.s,d.s)-max(a.s,c.s);
                if(x<=0 || y<=0) continue; // not overlapping
                // ans[x][y]--;
                if(!found || fx*fy < x*y) {
                    found=1; fx=x,fy=y;
                    break;
                }
                // if(x==3 && y==2) {
                //     cout <<"i="<<i<<" | ovl: { ("<<a.f<<", "<<a.s<<"), ("<<b.f<<", "<<b.s<<") }, { ("<<c.f<<", "<<c.s<<"), ("<<d.f<<", "<<d.s<<") }"<<"\n";
                // }
            }
            if(found) ans[fx][fy]--;
        }
    }
    memset(ANS, 0, sizeof(ANS));
    // cerr <<"+------ bk1 | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    for(int i=n; i>=1; i--) {
        int ps=0;
        for(int j=m; j>=1; j--) {
            ps += ans[i][j];
            // ANS[i][j] = ans[i][j];
            ANS[i][j] += ANS[i+1][j];
            ANS[i][j] += ANS[i][j+1]-ANS[i+1][j+1]+ps;
            // int d=2;
            // for(int k=j+1; k<=m; k++, d++) {
            //     ANS[i][j] += ans[i][k]*d;
            // }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cout << ANS[i][j]<<" ";
        cout <<"\n";
    }
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}
