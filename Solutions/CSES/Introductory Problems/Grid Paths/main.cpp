/*
 ID: dongliu3
 TASK:
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
#define dbg(x) cout <<#x<<": "<<x<<"\n";
#define dbg2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define PI acos(-1.0)

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
void setIO(const string s="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (s.length()==0) return;

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

/* ============================ */

bool vis[7][7];
int p[49];

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, -1, 1};

bool valid(int x, int y) {
    return (x>=0 && x<7 && y>=0 && y<7);
}
int dfs(int x, int y, int d) {
    if (d==48) return (x==6 && y==0);
    if (x==6 && y==0) return (d==48);

    if (((x + 1 == 7 || (vis[x - 1][y] && vis[x + 1][y])) && y - 1 >= 0 && y + 1 < 7 && !vis[x][y - 1] && !vis[x][y + 1]) ||
        ((y + 1 == 7 || (vis[x][y - 1] && vis[x][y + 1])) && x - 1 >= 0 && x + 1 < 7 && !vis[x - 1][y] && !vis[x + 1][y]) ||
        ((x == 0 || (vis[x + 1][y] && vis[x - 1][y])) && y - 1 >= 0 && y + 1 < 7 && !vis[x][y - 1] && !vis[x][y + 1]) ||
        ((y == 0 || (vis[x][y + 1] && vis[x][y - 1])) && x - 1 >= 0 && x + 1 < 7 && !vis[x - 1][y] && !vis[x + 1][y]))
        return 0;
    int res = 0, nx, ny;
    vis[x][y] = 1;
    if (p[d]==-1 || p[d]==0) { // UP
        nx=x-1, ny=y;
        if (valid(nx, ny) && !vis[nx][ny]) res += dfs(nx, ny, d+1);
    }
    if (p[d]==-1 || p[d]==1) { // DOWN
        nx=x+1, ny=y;
        if (valid(nx, ny) && !vis[nx][ny]) res += dfs(nx, ny, d+1);
    }
    if (p[d]==-1 || p[d]==2) { // LEFT
        nx=x, ny=y-1;
        if (valid(nx, ny) && !vis[nx][ny]) res += dfs(nx, ny, d+1);
    }
    if (p[d]==-1 || p[d]==3) { // RIGHT
        nx=x, ny=y+1;
        if (valid(nx, ny) && !vis[nx][ny]) res += dfs(nx, ny, d+1);
    }
    vis[x][y] = 0;
    return res;
}


int main() {
    // cout <<"\n+------ Starting\n"; clock_t startT = clock();
    setIO(""); // setTC("", "XX");

    string path; cin >> path;
    for0(i, sz(path)) {
        if (path[i]=='?') p[i]=-1;
        else if (path[i]=='U') p[i]=0;
        else if (path[i]=='D') p[i]=1;
        else if (path[i]=='L') p[i]=2;
        else if (path[i]=='R') p[i]=3;
    }
    cout << dfs(0, 0, 0);

    // cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}
