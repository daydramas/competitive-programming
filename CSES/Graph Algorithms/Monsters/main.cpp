#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};
const string P = "DRUL";

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

int n, m;
string g[1005];
int d1[1005][1005], d2[1005][1005];
pii p1[1005][1005]; int p2[1005][1005];

bool valid(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}


int main() {
    setIO("");

    cin >> n >> m;
    F0R(i,n) cin >> g[i];
    F0R(i,n) F0R(j,m) d1[i][j]=d2[i][j]=MOD;
    queue<pii> Q; pii st;
    F0R(i,n) F0R(j,m) if (g[i][j]=='A') Q.push({i,j}), st={i,j}, d1[i][j]=0, p1[i][j]={i,j};
    while(!Q.empty()) {
        pii F=Q.front(); Q.pop();
        F0R(k,4) {
            int x=F.f+X[k], y=F.s+Y[k];
            if (valid(x,y) && d1[x][y]==MOD && g[x][y]!='#') {
                d1[x][y]=d1[F.f][F.s]+1;
                p1[x][y]={F.f,F.s};
                p2[x][y]=k;
                Q.push({x,y});
            }
        }
    }
    F0R(i,n) F0R(j,m) if (g[i][j]=='M') Q.push({i,j}), d2[i][j]=0;
    while(!Q.empty()) {
        pii F=Q.front(); Q.pop();
        F0R(k,4) {
            int x=F.f+X[k], y=F.s+Y[k];
            if (valid(x,y) && d2[x][y]==MOD && g[x][y]!='#') {
                d2[x][y]=d2[F.f][F.s]+1;
                Q.push({x,y});
            }
        }
    }
    F0R(i,n)F0R(j,m) {
        if (i==0 || i==n-1 || j==0 || j==m-1) {
            if (d1[i][j] < d2[i][j]) {
                cout <<"YES\n";
                str ans=""; pii c={i,j};
                while(c!=st) {
                    ans+=P[p2[c.f][c.s]];
                    // cout <<"("<<c.f<<", "<<c.s<<") => "<<"("<<p1[c.f][c.s].f<<", "<<p1[c.f][c.s].s<<")\n";
                    c=p1[c.f][c.s];
                }
                reverse(all(ans));
                cout << sz(ans)<<"\n"<<ans;
                return 0;
            }
        }
    }
    cout <<"NO\n";
}