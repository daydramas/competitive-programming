/*
 ID: dongliu3
 TASK: rectbarn
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

int R, C, P;
// int b[3003][3003];
vi b[3003];
int cnt[3003];

int main() {
    setIO("rectbarn");

    cin >> R >> C >> P;
    for0(i, P) {
        int x,y; cin >> x >> y;
        b[--x].pb(--y);
    }
    int ans=0;
    for0(i, R) {
        for0(j, C) ++cnt[j];
        for(int j : b[i]) cnt[j]=0;
        stack<ii> s;
        for0(j, C+1) {
            while(!s.empty() && s.top().S > cnt[j]) {
                int y=s.top().S; s.pop();
                int area = (s.empty() ? j*y : (j-s.top().F-1)*y);
                ans = max(ans, area);
            }
            s.push(mp(j, cnt[j]));
        }
    }
    cout<<ans<<"\n";
    return 0;
}
