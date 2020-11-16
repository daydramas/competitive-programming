# Fine Dining
```cpp
/*
 ID: dongliu3
 TASK: dining
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

#define INF 1000000000

int n, m, k;
vii adj[50005];
ii d[50005];

int main() {
    setIO("dining");

    fin >> n >> m >> k;
    for0(i, m) {
        int a,b,t; fin >> a >> b >> t;
        adj[a].pb({b,t});
        adj[b].pb({a,t});
    }
    for0(i, k) {
        fin >> d[i].F >> d[i].S;
    }
    int dist1[50005]; queue<int> Q;
    fill(dist1, dist1+n+1, INF); dist1[n]=0; 
    Q.push(n);
    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        for (ii e : adj[f]) {
            if (dist1[f]+e.S < dist1[e.F]) {
                dist1[e.F] = dist1[f]+e.S;
                Q.push(e.F);
            }
        }
    }
    int dist2[50005];
    fill(dist2, dist2+n+1, INF); dist2[0]=0; 
    for0(i, k) adj[0].pb({d[i].F, dist1[d[i].F]-d[i].S});
    Q.push(0);
    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        for (ii e : adj[f]) {
            if (dist2[f]+e.S < dist2[e.F]) {
                dist2[e.F] = dist2[f]+e.S;
                Q.push(e.F);
            }
        }
    }
    for1(i,n-1) fout << (dist1[i]>=(dist2[i]))<<"\n";
    
    return 0;
}

```