/*
 ID: dongliu3
 TASK: twofive
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
#define DBG2(x,y) cout <<#x<<": "<<x<<' | '<<#y<<': '<<y<<endl;

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

int memo[30][30];

int dp(int i, int j) {
    if (memo[i][j]) return memo[i][j];
    if (j>i) return 0;
    if (!(i%5)) {
        return 1;
    }
    forc(k, j+1, 25) {
        memo[i][j] += dp(i+1,k);
        cout <<"memo["<<i<<"]["<<j<<"] +="<<dp(i+1,k)<<endl;
        
    }
    return memo[i][j];
}

int main() {
    setIO("twofive");
    
    memset(memo, 0, sizeof(memo));
    // cout << dp(1, 1) << endl;
    cout << dp(19, 20) << endl;

    return 0;
}
