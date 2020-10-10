/*
 ID: dongliu3
 TASK: latin
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

int n;
int cnt = 0;
int col[10][10], row[10][10];
int m[10], vis[10], gcnt[10], g;
const int fact[] = {0,1,2,6,24,120,720};
int find() {
    int mx = 2; memset(vis, 0, sizeof(vis));
    for1(i, n) if(!vis[i]) {
        int cnt=0, pa=i;
        do { vis[pa]=1, pa=m[pa], cnt++;  } while (!vis[pa]);
        mx = max(mx, cnt);
    }
    return mx;
}
long long dfs(int x, int y) {
    if (x==n) { gcnt[g]++; return 1; }
    long long ans = 0;
    for1(i, n) {
        if (!row[x][i] && !col[y][i]) {
            if (x==2) {
                m[y] = i;
                if (y==n) {
                    g=find();
                    if (gcnt[g] > 0) return gcnt[g];
                }
            }
            row[x][i] = 1;
            col[y][i] = 1;
            if (y < n) ans += dfs(x, y + 1);
            else ans += dfs(x + 1, 2);
            row[x][i] = 0;
            col[y][i] = 0;
        }
    }
    return ans;
}

int main() {
    // cout <<"\n+------ Starting\n"; clock_t startT = clock(); 
    setIO("latin");
    
    fin >> n;
    for1(i,n) col[i][i]=1;
    for(int i=2; i<n; i++) row[i][i]=1;
    m[1] = 2; 
    fout << dfs(2, 2) * fact[n-1] << endl;
    // cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}