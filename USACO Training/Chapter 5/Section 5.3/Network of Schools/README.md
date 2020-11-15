# Network of Schools
```cpp
/*
 ID: dongliu3
 TASK: schlnet
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

/* ============================ */

int n;
vi adj[105], radj[105];
bool vis[105];
int mark[105];
vi ord;

void dfs(int src) {
    vis[src]=true;
    for (int des : adj[src]) 
        if (!vis[des]) dfs(des);
    ord.pb(src);
}
void rdfs(int src, int color) {
    vis[src]=true;
    mark[src]=color;
    for (int des : radj[src]) 
        if (!vis[des]) rdfs(des, color);
}

int main() {
	setIO("schlnet");

    cin >> n;
    for1(i, n) {
        int x;
        while(cin >> x && x) {
            adj[i].pb(x);
            radj[x].pb(i);
        }
    }

    int subtaskA=0, subtaskB=0;

    int cnt = 0;
    fill(vis+1, vis+n+1, false);
    for1(i, n) {
        if (!vis[i]) dfs(i);
    }
    fill(vis+1, vis+n+1, false);
    forr0(i, ord.size()) {
        if (!vis[ord[i]]) {
            rdfs(ord[i], ++cnt);
        }
    }

    if (cnt==1) {
        cout << "1\n0\n";
        return 0;
    }

    //subtask B
    int in[105], out[105];
    fill(in+1, in+n+1, 0);
    fill(out+1, out+n+1, 0);
    for1(i, n) {
        for (int j : adj[i]) {
            int a=mark[i], b=mark[j];
            if (a!=b) {
                in[b]++, out[a]++;
            }
        }
    }
    for1(i, cnt) {
        if(!in[i])  ++subtaskA; 
        if(!out[i]) ++subtaskB;
    }
    cout << subtaskA <<"\n"<< max(subtaskA, subtaskB) << "\n";
	return 0;
}
```