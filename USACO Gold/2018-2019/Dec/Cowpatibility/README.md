```cpp
/*
 ID: dongliu3
 TASK: cowpatibility
 LANG: C++
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>
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
// #define sz(a) int((a).size())
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

struct node {
    int sz; int arr[5];
    // node(int sz, int arr[]) : sz(sz), arr(arr) {}
};
bool operator<(const node& l, const node& r) {
    for0(i,5) {
        if (l.arr[i]<r.arr[i]) return true;
        if (l.arr[i]>r.arr[i]) return false;
    }
    return false;
}
const int maxn = 50005;
ll n; node a[50005];
map<node, ll> M;
// void dfs(int i) {
//     if (i==5) {
//         if (!u[0] && !u[1] && !u[2] && !u[3] && !u[4]) return;
//         vi t; for0(i,5) if(u[i]) { t.pb(a[i]);  }
//         M[t]++;
//         return;
//     }
//     u[i]=0; dfs(i+1);
//     u[i]=1; dfs(i+1);
//     u[i]=0;
// }
int main() {
    cout <<"\n+------ Starting\n"; clock_t startT = clock(); 
    setIO("cowpatibility");
    fin >> n;
    for0(i, n) {
        for0(j,5) fin >> a[i].arr[j];
        sort(a[i].arr, a[i].arr+5); // dfs(0);
        for(int j=1; j<=31; j++) {
            node t = {0, {0, 0, 0, 0, 0} };
            for0(k, 5) {
                if ((1<<k)&j) {
                    t.arr[t.sz++]=a[i].arr[k];
                }
            }
            M[t]++;
        }
    }
    ll cnt = n * (n-1) / 2;
    int mul[] = {0, -1, 1, -1, 1, -1};
    for(auto& t : M) {
        cnt += (ll)mul[t.first.sz] * (ll)t.second*((ll)t.second-1)/2;
    }
    fout << cnt <<"\n";
    cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}

```