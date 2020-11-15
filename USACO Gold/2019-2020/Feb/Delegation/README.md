```cpp
/*
 ID: dongliu3
 TASK: deleg
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
#define DBG(x) cout <<#x<<": "<<x<<endl;
#define DBG2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;

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

ifstream fin;
ofstream fout;

void setIO(const string &PROB = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (PROB.length() != 0) {
        ifstream infile(PROB + ".in");
        if (infile.good()) {
            fin.open(PROB + ".in");
            fout.open(PROB + ".out");
        }
    }
}

/* ============================ */

int n;
vi adj[100005];
int s[100005];
vi vs[100005];

void dfs(int sc, int pa) {
    s[sc] = 1;
    for (int ch : adj[sc]) if (ch!=pa) {
        dfs(ch, sc);
        s[sc] += s[ch];
        vs[sc].pb(s[ch]);
    }
    if (s[sc]!=n) vs[sc].pb(n-s[sc]);
}
bool ok(int k) {
    if ((n-1)%k) return 0;
    int c[100005]; memset(c, 0, sizeof(c));
    for1(sc, n) {
        int cnt = 0;
        for(int d : vs[sc]) {
            int m = d%k; if (!m) continue;
            if (c[k-m]) { c[k-m]--; cnt--; }
            else { c[m]++, cnt++; }
        }
        if (cnt!=0) return 0;
    }
    return 1;
}
int main() {
    setIO("deleg");

    fin >> n;
    for1(i,n-1) {
        int x,y; fin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, -1);
    for(int k=1; k<n; k++) fout <<ok(k);
    fout<<"\n";
    return 0;
}

```