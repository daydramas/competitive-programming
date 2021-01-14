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

void setIO(const string PROB = "") {
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
#define INF 2147483647

unordered_set<int> used;
string goal = "Begin the Escape execution at the Break of Dawn";

string decrypt(string s, int c, int o, int w) {
    string res(sz(s)-3, 0);
    int idx = 0;
    for0 (i, c) res[idx++] = s[i];
    forc(i, o+1, w-1) res[idx++] = s[i];
    forc(i, c+1, o-1) res[idx++] = s[i];
    forc(i, w+1, sz(s)-1) res[idx++] = s[i];
    return res;
}

bool freCheck(string s) {
    int cnt[200][2];
    memset(cnt, 0, sizeof(cnt));
    for0(i, sz(goal)) cnt[goal[i]][0]++;
    for0(i, sz(s)) cnt[s[i]][1]++;
    for (int i = 0; i < 128; i++) 
        if (!(i=='C'||i=='O'||i=='W') && cnt[i][0]!=cnt[i][1]) return 0;
    return 1;
}

bool preCheck(string s) {
    for0(i, sz(s)) {
        if (s[i] == 'C') break;
        if (s[i] != goal[i]) return 0;
    }
    return 1;
}

bool sufCheck(string s) {
    int idx = (int)goal.length() - 1;
    forr0 (i, sz(s)) {
        if (s[i] == 'W') break;
        if (s[i] != goal[idx--]) return 0;
    }
    return 1;
}

bool ok(string str, int s, int t) {
    for (int i=0; (i+t-s)<=sz(goal); i++) {
        bool flag = 1;
        for0(j, t-s) if (goal[i+j]!=str[s+j]) { flag = 0; break; }
        if (flag) return 1;
    }
    return 0;
}

bool subCheck(string s) {
    int start = 0;
    for0(i, sz(s)+1) if (s[i]=='C'||s[i]=='O'||s[i]=='W'||s[i]==0) {
        if (!ok(s, start, i)) return 0;
        start=i+1;
    }
    return 1;
}

int HASH(string s) {
    int h = 0, x= 0;
    for0(i, sz(s)) {
        h = (h << 4) + s[i];
        if ((x = h&0xF0000000L) != 0) h ^= (x >> 24);
        h &= ~x;
    }
    return h;
}

bool dfs(string s, int depth) {
    if (depth == 0) return ( s == goal );
    for0(O, sz(s)) if (s[O]=='O') { // looping through all O's
        for0(C, O) if (s[C]=='C') { // looping through all C's
            for (int W=(sz(s)-1); W>O; W--) if (s[W]=='W') { // looping through all W's
                string t = decrypt(s, C, O, W);
                if (!preCheck(t)||!sufCheck(t)||!subCheck(t)) continue;
                int h = HASH(t);
                if (used.find(h) != used.end()) continue; // if same string was used before
                if (dfs(t, depth - 1)) return 1; // continue to descrypt string
                used.insert(h);
            }
        }
    }
    return 0;
}

int main() {
    setIO("cryptcow");
    string s; getline(fin, s);

    int T = (sz(s) - 47) / 3;
    if ((sz(s)-47)%3 == 0 && freCheck(s) && dfs(s, T)) fout<<1<<" "<<T<<"\n";
    else fout<<"0 0\n";
    return 0;
}