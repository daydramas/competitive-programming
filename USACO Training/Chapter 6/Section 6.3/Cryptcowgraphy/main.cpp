/*
 ID: dongliu3
 TASK: cryptcow
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
#define X first
#define Y second
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
string goal = "Begin the Escape execution at the Break of Dawn";

string S;

string operation(string S2, int a, int b, int c) {
    return S2.substr(0, a)+S2.substr(b+1, c-b-1)+S2.substr(a+1, b-a-1)+S2.substr(c+1, sz(S2)-c-1);
}

int main() {
    setIO("cryptcow");

    string t; S="";
    while(getline(fin, t)) S += t;
    
    // if uneven amounts of "C" "O" "W"
    vi cc, co, cw;
    for0(i, sz(S)){
        if (S[i]=='C') cc.pb(i);
        if (S[i]=='O') co.pb(i);
        if (S[i]=='W') cw.pb(i);
    }
    if (sz(cc)!=sz(co) || sz(cc)!=sz(cw)) { fout <<"0\n0\n"; return 0; }
    
    
    cout << S << endl;
    operation(S, cc[0], co[0], cw[0]);

    cout << S << endl;

    return 0;
}
