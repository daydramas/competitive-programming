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



int main() {

    // cout <<"\n+------ Starting\n"; clock_t startT = clock();
    setIO(""); // setTC("", "XX");

    int n, m; cin >> n >> m;
    vi a(n+1);
    for0(i,n) cin >> a[i];

    const int mod = 1e9 + 7;
    vector<vi> dp(n, vi(m+1, 0));
    if (a[0]) dp[0][a[0]]=1;
    else dp[0] = vi(m+1, 1);
    for1(i,n-1) for1(j,m) {
        if (a[i] && a[i]!=j) dp[i][j]=0;
        else {
            for(int k : {j-1,j,j+1}) {
                if (k>=1 && k<=m) {
                    dp[i][j] = (dp[i][j]+dp[i-1][k]) %mod;
                }
            }
        }
    }
    int res=0;
    for1(i,m) res= (res+dp[n-1][i])%mod;
    cout <<res;

    // cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}
