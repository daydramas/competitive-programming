# Canada Tour
```cpp
/*
 ID: dongliu3
 TASK: tour
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

int n, m;
bool adj[105][105];
map<string, int> key;
int dp[105][105];

int main() {
    setIO("tour");

    cin >> n >> m;
    for1(i, n) {
        string x; cin >> x;
        key[x] = i;
    }
    for1(i, n) for1(j, n) {
        adj[i][j]=false;
    }
    for1(i, m) {
        string x, y; cin >> x >> y;
        int a = key[x], b = key[y];
        if (a<b) adj[a][b] = true;
        else adj[b][a] = true;
    }

    // memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    int ans=1;
    
    for1(i, n) {
        forc (j, i+1, n) {
            for1(k, j-1) {
                if (adj[k][j]) {
                    if (k==i && i!=1) continue;
                    if(dp[i][k]>0 && dp[i][k]+1>dp[i][j])
						dp[i][j]=dp[i][k]+1;
                }
            }
           dp[j][i]=dp[i][j];
        }
        if(i==n) ans=max(ans, dp[n][n]-1);
		else if(adj[i][n]) ans=max(ans,dp[i][n]);
    }
    cout << ans << "\n";
    return 0;
}
```