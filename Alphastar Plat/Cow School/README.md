# Cow School
```cpp
/*
 ID: dongliu3
 TASK: schul
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
ii t[50005];
ii tch[50005];

bool comp (ii a, ii b) {
    return a.F*b.S <= b.F*a.S;
}
int main() {

    // setIO("schul");

    // cin >> n;
    // ii ttl = {0, 0};
    // for1(i,n) { cin >> t[i].F >> t[i].S; ttl.F+=t[i].F, ttl.S+=t[i].S; }
    // sort(t+1, t+n+1, comp);
    
    // tch[0]={0,0};
    // for1(i,n) tch[i]={tch[i-1].F+t[i].F, tch[i-1].S+t[i].S};

    // vi ans;
    // for1(i,n-1) {
    //     double teacher = (double)(ttl.F-tch[i].F)/(double)(ttl.S-tch[i].S);
    //     for1(k, 50) {
    //         if (i+k > n) break;
    //         ii b = tch[i]; b.F+=t[i+k].F, b.S+=t[i+k].S;
    //         bool flag = false;
    //         for1(j,i) {
    //             b.F -= t[j].F, b.S -= t[j].S;
    //             double bessie = (double)(ttl.F-b.F)/(double)(ttl.S-b.S);
    //             b.F += t[j].F, b.S += t[j].S;
    //             if (bessie > teacher) { flag=true; break; }
    //         }
    //         if (flag) { ans.pb(i); break; }
    //     }
    // }
    // cout << ans.size() <<"\n";
    // for(int a : ans) cout << a <<"\n";

    return 0;
}

```