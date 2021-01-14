/*
 ID: dongliu3
 TASK: timeline
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

int n, m, c;
int s[100005], cnt[100005];
vii adj[100005];

int main() {
    setIO("timeline");
    
    fin >> n >> m >> c;
    for1(i, n) fin >> s[i];
    for1(i, c) {
       int a, b, x; fin >> a >> b >> x;
       adj[a].pb({b,x}); 
       cnt[b]++;
    }
    queue<int> Q;
    for1(i, n) {
        if (!cnt[i]) Q.push(i);
    }
    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        for (ii ed : adj[f]) {
            s[ed.F] = max(s[ed.F], s[f]+ed.S);
            if (--cnt[ed.F] == 0) {
                Q.push(ed.F);
            }
        }
    }
    for1(i, n) fout << s[i]<<"\n";
    return 0;
}
