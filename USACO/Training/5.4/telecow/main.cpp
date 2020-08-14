/*
 ID: dongliu3
 TASK: telecow
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

/* Defines */

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) 
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define DBG(x) cout <<#x<<': '<<x<<endl;
#define DBG2(x,y) cout <<#x<<': '<<x<<' | '<<#y<<': '<<y<<endl;

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

/* Typdefs */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

/* IO */

void setIO(const string &PROB = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (PROB.length() != 0) {
        ifstream infile(PROB + ".in");
        if (infile.good()) {
            freopen((PROB + ".in").c_str(), "r", stdin);
            freopen((PROB + ".out").c_str(), "w", stdout);
        }
    }
}

#define INF 1000000000

/* ============================ */

int n, m, c1, c2, t;
int adj[205][205];
int bu[205][205];
int depth[205];

bool con() {
    memset(depth, 0, sizeof(depth));
    queue<int> Q;
    Q.push(0);
    depth[0] = 1;
    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        for1(c, t) {
            if (adj[f][c] && !depth[c]) {
                depth[c] = depth[f]+1;
                Q.push(c);
            }
        }
    }
    return (depth[t]);
}

int flow(int cur, int mx) {
    if(cur==t) return mx;

    for1(i, t) if (adj[cur][i] && depth[i]==depth[cur]+1) {
        int nf = flow(i, min(adj[cur][i], mx));
        if (nf) {
            adj[cur][i] -= nf;
            adj[i][cur] += nf;
            return nf;
        }
    }
    return 0;
}

int dinic() {
    int ta = 0;
    while(con()) ta += flow(0, INF);
    return ta;
}

int main() {
    setIO("telecow");

    cin >> n >> m >> c1 >> c2;
    for1(i, m) {
        int a, b; cin >> a >> b;
        adj[a+n][b] = adj[b+n][a] = INF;
    }
    t = 2*n+1;
    adj[0][c1] = adj[c2+n][t] = INF;
    for1(i, n) {
        adj[i][i+n] = (i!=c1 && i!=c2)?1:INF;
    }
    for1(i, t) for1(j, t) {
        bu[i][j] = adj[i][j];
    }

    int ans = dinic();
    cout << ans <<"\n";

    vi ans2;
    for1(i, n) if (i!=c1 && i!=c2 && !adj[i][i+n]) {
        for1(j, t) for1(k, t) adj[j][k]=bu[j][k];
        adj[i][i+n] = 0;
        if (dinic() == ans-1) {
            ans2.pb(i);
            bu[i][i+n] = 0;
            if (!(--ans)) break;
        }
    }
    for (int a : ans2) {
        cout << a;
        if (a != ans2.back()) cout << " ";
    }
    cout << "\n";
    return 0;
}
