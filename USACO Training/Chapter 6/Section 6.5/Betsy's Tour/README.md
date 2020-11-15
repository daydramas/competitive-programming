```cpp
/*
 ID: dongliu3
 TASK: betsy
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
bool v[10][10];

int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

bool vl(int x, int y) { return ( x>=1 && x<=n && y>=1 && y<=n ); }
bool vl2(int x, int y) { return !vl(x,y)||v[x][y]; }

// bool de(int x, int y) {
//     if (vl2(x+1,y) && vl2(x-1,y) && vl2(x,y+1) && vl2(x,y-1)) return false;
//     // if (vl2(x+1,y+1) && vl2(x+1,y-1) && vl2(x+2,y)) { return false; }
//     // if (vl2(x-1,y-1) && vl2(x-1,y+1) && vl2(x-2,y)) { return false; }
//     // if (vl2(x-1,y+1) && vl2(x+1,y+1) && vl2(x,y+2)) { return false; }
//     // if (vl2(x-1,y-1) && vl2(x+1,y-1) && vl2(x,y-2)) { return false; }
//     return true;
// }
bool de(int x, int y) {
    if ((!vl(x + 1, y) || v[x + 1][y]) && (!vl(x - 1, y) || v[x - 1][y])) {
        if (vl(x, y - 1) && !v[x][y - 1] && vl(x, y + 1) && !v[x][y + 1])
            return true;
    }
    if ((!vl(x, y - 1) || v[x][y - 1]) && (!vl(x, y + 1) || v[x][y + 1])) {
        if (vl(x - 1, y) && !v[x - 1][y] && vl(x + 1, y) && !v[x + 1][y])
            return true;
    }
    return false;
}

void pv() {
    for1(i,n) {
        for1(j,n) cout << v[i][j]<<" ";
        cout <<"\n";
    }
    cout <<"\n";
}

int ccnt(int i, int j) {
    int cnt=0;
    for0(k, 4) {
        cnt += (vl(i+X[k],j+Y[k]) && !v[i+X[k]][j+Y[k]]);
    }
    return cnt;
}

int dfs(int i, int j, int vis) {
    if (i==n && j==1) return (vis==n*n);
    if (vis==n*n) return 0;
    if (de(i, j)) return 0;

    int ans = 0;
    int cnt=0, _i=-1;
    for0(k, 4) {
        int x1 = i+X[k], y1 = j+Y[k];
        if (vl(x1, y1) && !v[x1][y1] && ccnt(x1, y1) == 1) {
            if (x1 == n && y1 == 1) continue;
            cnt++, _i = k;
        }
    }
    if (cnt == 1) {
        int x=(i+X[_i]), y=(j+Y[_i]);
        v[x][y]=true;
        ans += dfs(i+X[_i], j+Y[_i], vis+1);
        v[x][y]=false;
    } else {
        for0(k, 4) {
            int x=(i+X[k]), y=(j+Y[k]);
            if (vl(x, y) && !v[x][y]) {
                v[x][y]=true;
                ans += dfs(x, y, vis+1);
                v[x][y]=false;
            }
        }
    }
    return ans;
    // for0(k, 4) {
    //     int x=i+X[k], y=j+Y[k];
    //     if (vl(x, y) && !v[x][y]) {
            
    //         v[x][y] = true;
    //         cnt += dfs(x, y, vis+1);
    //         v[x][y] = false;
    //     }
    // }
    return cnt;
}

int main() {
    cout <<"\n+------ Starting\n"; clock_t startT = clock();
    setIO("betsy");

    fin >> n;
    memset(v, false, sizeof(v));
    v[1][1]=true;
    fout << dfs(1, 1, 1) << "\n";
    cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}

```