/*
 ID: dongliu3
 TASK: clocks
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

struct state {
    int hsh; int mv; vi mva;
    state(int hsh, int mv, vi mva) : hsh(hsh), mv(mv), mva(mva) {}
};

vi o;
bool vis[300000];
queue<state> q;
vi pow4;
int ch[10][10] = {{4,0,1,3,4}, {3,0,1,2}, {4,1,2,4,5}, {3,0,3,6}, {5,1,3,4,5,7}, {3,2,5,8}, {4,3,4,6,7}, {3,6,7,8}, {4,4,5,7,8}};
string toString(int hsh) {
    string s="";
    for0(i,9) { 
        // cout <<(hsh%pow4[i+1])/pow4[i]<<endl;
        s += to_string( (hsh%pow4[i+1])/pow4[i] );
    }
    return s;
}
int hsh(vi& v) {
    int m=1, r=0;
    for0(i,9) { r+=m*(v[i]%4), m*=4; }
    return r;
}
int useMove(int hsh, int mv) {
    for1(i, ch[mv][0]) {
        int in = ch[mv][i];
        int d = (hsh%pow4[in+1])/pow4[in];
        hsh -= pow4[in]*d;
        d = (d+1)%4;
        hsh += pow4[in]*d;
    }
    return hsh;
}

int main() {
    cout <<"\n+------ Starting\n"; clock_t startT = clock();
    setIO("clocks");
    
    for0(i,9) { int x; fin>>x; o.pb(x/3); }
    pow4.pb(1);
    for0(i,9) pow4.pb(pow4[i]*4);

    vi t;
    memset(vis, false, sizeof(vis));
    q.push(state(hsh(o), 0, t));
    vis[hsh(o)] = true;
    while(!q.empty()) {
        state f = q.front(); q.pop();
        
        // cout << toString(f.hsh) <<" | "<< ( f.mva.size()?f.mva.back():0 ) <<"\n";
        if (!f.hsh) { 
            fout << f.mva[0]+1;
            for0(i,sz(f.mva)) if (i)fout <<" "<<f.mva[i]+1;
            fout <<"\n"; 
            break;
        }
        for0(i,9) {
            int nhsh = useMove(f.hsh, i);
            if (!vis[nhsh]) {
                vis[nhsh]=true;

                f.mva.pb(i);
                q.push(state(nhsh, f.mv+1, f.mva));
                f.mva.pop_back();
            }
        }
    }

    cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}
