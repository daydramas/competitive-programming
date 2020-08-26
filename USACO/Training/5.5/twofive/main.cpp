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

int dp[6][6][6][6][6];

void setupDP() {
    for0(a, 6) for0(b, 6) for0(c, 6) for0(d, 6) for0(e, 6) {
        dp[a][b][c][d][e] = 0;
    }
    dp[5][5][5][5][5] = 1;
}

int solve(vector<int> &I, string &w, int d) {
    if (dp[I[0]][I[1]][I[2]][I[3]][I[4]]) {
        return dp[I[0]][I[1]][I[2]][I[3]][I[4]];
    }
    int cnt=0;
    for0(i, 5) {
        if (I[i]<5 && (i==0 || I[i]<I[i-1])) {
            if (w[(i*5)+I[i]]==0 || w[(i*5)+I[i]]==('A'+d)) {
                I[i]++; cnt+=solve(I, w, d+1); I[i]--;
            }   
            if (w[(i*5)+I[i]]==('A'+d)) break;
        }
    }
    return (dp[I[0]][I[1]][I[2]][I[3]][I[4]]=cnt);
}
int solve(string &str) {
    setupDP();
    vector<int> v(5, 0);
    return solve(v, str, 0);
}
int main() {
    setIO("twofive");

    char ch; cin >> ch;
    
    if (ch=='N') {
        int n; cin >> n;
        string w(25, 0);
        for0(i, 25) for0(l, 25) {
            w[i] = ('A'+l);
            int cnt = solve(w);
            if (n > cnt) n-=cnt;
            else break; 
        }
        cout << w << "\n";;
    }

    if (ch=='W') {
        int n=0;
        string w; cin >> w;
        string t(26, 0);
        for0(i, 25) {
            for0(l, (w[i]-'A')) {
                t[i] = ('A'+l);
                n += solve(t);
            }
            t[i] = w[i];
        }
        cout << n+1 <<"\n";
    }
    return 0;
}