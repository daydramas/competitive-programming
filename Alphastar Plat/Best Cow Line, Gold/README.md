# Best Cow Line, Gold
```cpp
/*
 ID: dongliu3
 TASK: bclgold
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

int n; char a[30005];

bool c(int s, int e) {
    while(s<=e) {
        if (a[s]<a[e]) return 1;
        else if (a[s]>a[e]) return 0;
        s++; e--;
    }
    return s;
}
int main() {
    setIO("bclgold");
    
    cin >> n;
    for0(i,n) cin >> a[i];
    
    string ans = "";
    int s=0, e=n-1;
    while(s<=e) {
        if (s==e) ans+=a[s++]; 
        else if (a[s]<a[e]) ans+=a[s++];
        else if (a[s]>a[e]) ans+=a[e--];
        else {
            if (c(s,e)) ans+=a[s++];
            else ans+=a[e--];
        }
    }
    for0(i, n) {
        if (i && i%80==0) cout <<"\n";
        cout <<ans[i];
    }
    cout <<"\n";
    return 0;
}

```