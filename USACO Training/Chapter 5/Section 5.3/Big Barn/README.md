```cpp
/*
 ID: dongliu3
 TASK: bigbrn
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
int n, t;
int x[1005], y[1005];
int dp[1005][1005];

int main() {
    setIO("bigbrn");
    
    cin >> n >> t;

    for1(i, n) for1(j, n) dp[i][j]=0;

    for0(i, t) {
        int x,y;
        cin >> x >> y;
        dp[x][y]++;
    }
    


    for1(i, n) for1(j, n) {
        dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }

    int ans=0;
    for0(i, n) for0(j, n) {
        int l=ans+1, r=min(n-i+1,n-j+1);
        while(l<r) {
            int m=(l+r)/2;
            // now to test if (i,j) to (i+m, j+m) is 0
            if (dp[i+m][j+m]+dp[i][j] == dp[i][j+m]+dp[i+m][j]) {
                l=m+1;
                ans = max(ans, m);
            } else {
                r=m;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

```