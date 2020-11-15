```cpp
/*
 ID: dongliu3
 TASK: cowxor
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

int n, a[100005];
int nxt[750005][2], pos[750005];

int main(){
    setIO("cowxor");
    cin >> n;


    int j, k, ans, anss, anse, tot;
    ans = 0; anss = anse = tot = 1;
	for1(i, n) {
		cin >> a[i]; a[i] ^= a[i-1];
		for(k = 1, j = 20; j >= 0; j--){
			if(!nxt[k][(a[i - 1] >> j) & 1]) 
				nxt[k][(a[i - 1] >> j) & 1] = ++tot; 
			k = nxt[k][(a[i - 1] >> j) & 1];
		}
		pos[k] = i - 1;
		for(k = 1, j = 20; j >= 0; j--)
                        k = (nxt[k][!( (a[i]>>j)&1 )]) ? (nxt[k][!( (a[i]>>j)&1 )]) : (nxt[k][(a[i]>>j)&1]);
		if((a[i] ^ a[pos[k]]) > ans)
                        ans = a[i] ^ a[pos[k]], anss = pos[k] + 1, anse = i;
	}
	cout << ans << " " << anss << " " << anse << endl;
	return 0;
}
```