```cpp
/*
 ID: dongliu3
 TASK: fcolor
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

int n, m;
vi adj[200005],ch[200005];
int pa[200005],col[200005];
queue<int> Q;

void merge(int x, int y) {
    if(x>y) swap(x, y);
	for (int d: ch[y]) { pa[d]=x; ch[x].push_back(d); }
    adj[x].insert(adj[x].begin(), all(adj[y])); adj[y].clear();
    if(adj[x].size()>1) { Q.push(x);}
}

int main() {
    setIO("fcolor");

    fin >> n >> m;
    for0(i, m) {
        int a, b; fin >> a >> b;
        adj[a].pb(b);
    }
    for1(i, n) {
        ch[i].pb(i); pa[i]=i;
        if(adj[i].size()>1) Q.push(i);
    }
    while(!Q.empty()) {
        int f=Q.front(); 
        if (adj[f].size() <= 1) { Q.pop(); continue; }
        int x=adj[f].back(); adj[f].pop_back();
        int y=adj[f].back();
        if (pa[x]!=pa[y]) merge(pa[x], pa[y]);
    }
    int cnt=1;
    for1(i, n) {
        if(!col[pa[i]])col[pa[i]]=cnt++;
        fout << col[pa[i]]<<"\n";
    }
    return 0;
}

```