/*
 ID: dongliu3
 TASK: wissqu
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
// #define S second
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

struct node {
    int x, y, ch;
    node(int x, int y, int ch) : x(x), y(y), ch(ch) {}
};

string S;
int a[4][4], vis[4][4]; // (i)(j)
int c[5][4][4]; // (type)(i)(j)
int type[5];
vector<node> ans;

int X[] = {0, 1, 0, -1, 0, -1, -1, 1, 1};
int Y[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
bool v(int a, int b) { return a>=0 && a<4 && b>=0 && b<4; }
void add(int color, int x, int y, int val) {
    for0(i,9) if(v(x+X[i], y+Y[i])) {
        c[color][x+X[i]][y+Y[i]] += val;
    }
}
void init() {
    memset(c, 0, sizeof(c));
    memset(vis, 0, sizeof(vis));
    memset(type, 0, sizeof(type));
    for0(i,4) for0(j,4) {
        a[i][j] = (int)(S[4*i+j]-'A');
        type[a[i][j]]++;
        add(a[i][j], i, j, 1);
    }
    type[2]--;
}
bool dfs() {
    if (ans.size() == 16) return true;
    for0(t, 5) if (type[t]) { type[t]--;
        for0(i,4) for0(j,4) if (!vis[i][j] && a[i][j]!=t && c[t][i][j]==0) {
            vis[i][j] = 1;
            ans.push_back(node(i+1, j+1, t));
            add(a[i][j], i, j, -1); add(t, i, j, 1);
            if (dfs()) return true;
            vis[i][j] = 0;
            ans.pop_back();
            add(a[i][j], i, j, 1); add(t, i, j, -1);
        }
        type[t]++;
    }
    return false;
}

int dfs_(int d) {
    if (d == 16) return 1;
    int cnt = 0;
    for0(t, 5) if(type[t]) { type[t]--;
        for0(i, 4) for0(j, 4) {
            if (!vis[i][j] && a[i][j]!=t && !c[t][i][j]) {
                vis[i][j] = 1;
                add(a[i][j], i, j, -1); add(t, i, j, 1);
                cnt += dfs_(d+1);
                vis[i][j] = 0;
                add(a[i][j], i, j, 1); add(t, i, j, -1);
            }
        }
        type[t]++;
    }
    return cnt;
}

int main() {
    setIO("wissqu");
    
    string T;
    while(getline(fin, T)) S += T;

    init();
    bool ok = false;
    for0(i,4) for0(j,4) {
        if (!vis[i][j] && a[i][j]!=3 && !c[3][i][j]) {
            vis[i][j] = 1;
            ans.push_back(node(i+1, j+1, 3)); 
            add(a[i][j], i, j, -1); add(3, i, j, 1);
            if (dfs()) { ok = true; break; }
            vis[i][j] = 0;
            ans.pop_back();
            add(a[i][j], i, j, 1); add(3, i, j, -1);
        }
    }
    
    for (node n : ans)
        fout << (char)(n.ch+'A') << " " << n.x << " " << n.y << endl;

    init();
    ll cnt = 0;
    for0(i,4) for0(j,4) {
        if (!vis[i][j] && a[i][j]!=3 && !c[3][i][j]) {
            vis[i][j] = 1;
            add(a[i][j], i, j, -1); add(3, i, j, 1);
            cnt += dfs_(1);
            vis[i][j] = 0;
            add(a[i][j], i, j, 1); add(3, i, j, -1);
        }
    }
    fout << cnt << endl;
    return 0;
}