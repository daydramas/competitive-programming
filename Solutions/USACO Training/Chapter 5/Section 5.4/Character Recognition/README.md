# Character Recognition
```cpp
/*
 ID: dongliu3
 TASK: charrec
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
#define DBG(x) cout <<#x<<': '<<x<<endl;
#define DBG2(x,y) cout <<#x<<<<x<<' | '<<#y<<': '<<y<<endl;

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

#define INF 1000000000

/* ============================ */

int n;
int dict[27][20];
int DP[1300][80];
int A[1200];
ii ans[1200][30];

void readDict() {
    ifstream dictin("font.in");
    int n; dictin >> n;
    for0(i, 27) for0(j, 20) for0(k, 20) {
        char c; dictin >> c; 
        if (c == '1') dict[i][j] |= (1 << k);
    }
}

int dp(int line, int location) {
    if (line == n) return 0;
    if (DP[line][location] != -1) return DP[line][location];
    int tans = INF, C = -1, res;

    if (line + 19 <= n) {
        int bestDiff = INF, bestIdx = -1;
        int op = dp(line + 19, location + 1);
        if (op != INF) {
            for0(i, 27) for0(ignore, 20) {
                int ct = 0;
                for0(row, 20) {
                    if (row == ignore) continue;
                    int a = A[line + row - (ignore < row ? 1 : 0)], b = dict[i][row];
                    ct += __builtin_popcount(a ^ b);
                    if (ct >= bestDiff) break;
                }
                if (ct < bestDiff) {
                    bestDiff = ct;
                    bestIdx = i;
                }
            }
            if (op != INF && op + bestDiff < tans) {
                tans = op + bestDiff;
                C = 0;
                res = bestIdx;
            }
        }
    }

    if (line + 20 <= n) {
        int bestDiff = INF, bestIdx = -1;
        int op = dp(line + 20, location + 1);
        if (op != INF) {
            for0(i, 27) {
                int ct = 0;
                for0(row, 20) {
                    int a = A[line + row], b = dict[i][row];
                    ct += __builtin_popcount(a ^ b);
                    if (ct >= bestDiff) break;
                }
                if (ct < bestDiff) {
                    bestDiff = ct;
                    bestIdx = i;
                }
            }
            if (op != INF && op + bestDiff < tans) {
                tans = op + bestDiff;
                C = 1;
                res = bestIdx;
            }
        }
    }

    if (line + 21 <= n) {
        int bestDiff = INF, bestIdx = -1;
        int op = dp(line + 21, location + 1);
        if (op != INF) {
            for0(i, 27) for0(ignore, 21) {
                int ct = 0;
                for0(row, 20) {
                    int a = A[line + row + (ignore <= row ? 1 : 0)], b = dict[i][row];
                    ct += __builtin_popcount(a ^ b);
                    if (ct >= bestDiff) break;
                }
                if (ct < bestDiff) {
                    bestDiff = ct;
                    bestIdx = i;
                }
            }
            if (op + bestDiff < tans) {
                tans = op + bestDiff;
                C = 2;
                res = bestIdx;
            }
        }
    }

    if (C == -1) return DP[line][location] = INF;
    ans[line][location] = ii(C, res);

    return (DP[line][location] = tans);
}
int main() {
    setIO("charrec");

    readDict();

    cin >> n;
    for0(i, n) for0(j, 20) {
        char c; cin >> c;
        if (c == '1') A[i] |= (1<<j);
    }

    memset(DP, -1, sizeof(DP));
    dp(0, 0);

    int cur = 0, loc = 0;
    string ansP;
    while (cur != n) {
        ansP += (ans[cur][loc].S)?('a' + ans[cur][loc].S - 1):' ';
        cur += ans[cur][loc].F + 19;
        loc++;
    }
    
    cout << ansP << "\n";
    return 0;
}

```