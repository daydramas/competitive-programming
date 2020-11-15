```cpp
/*
 ID: dongliu3
 TASK: checker
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
int cnt;
int R[30], C[30], D1[30], D2[30];
vi used;
int gd1(int row, int col) { return (row+col-1); }
int gd2(int row, int col) { return (row-col+n); }

int dfs(int row) {
    if (row==n+1) {
        if (cnt) {
            fout << used[0];
            for0(i,sz(used)) if(i) fout <<" "<<used[i];
            fout << "\n";
            cnt--;
        }  
        return 1; 
    }
    int cnt = 0;
    for1(col, n) {
        int d1=gd1(row,col), d2=gd2(row,col);
        if (R[row] || C[col] || D1[d1] || D2[d2]) {
            // cout <<"failed to place ("<<row<<", "<<col<<") | "<<R[row]<<C[col]<<D1[d1]<<D2[d2]<<"\n";
            // return 0;
            continue;
        }
        used.pb(col);
        R[row] = C[col] = D1[d1] = D2[d2] = true;
        // cout <<"placed ("<<row<<", "<<col<<").\n";
        cnt += dfs(row+1);
        used.pop_back();
        // cout <<"removed ("<<row<<", "<<col<<").\n";
        R[row] = C[col] = D1[d1] = D2[d2] = false;
    }
    return cnt;
}

int main() {
    setIO("checker");

    fin >> n; cnt = 3;
    memset(R, false, sizeof(R));
    memset(C, false, sizeof(C));
    memset(D1, false, sizeof(D1));
    memset(D2, false, sizeof(D2));
    fout << dfs(1) << "\n";
    return 0;
}

```