# picture
```cpp
/*
 ID: dongliu3
 TASK: picture
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
#define DBG2(x,y) cout <<#x<<': '<<x<<' | '<<#y<<': '<<y<<endl;

#define pb push_back
#define x first
#define y second
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

struct rectangle {
    ii a, b;
};

int n;
rectangle R[5005];
int taken[5005];

bool overlap(rectangle A, rectangle B) {
	if (A.a.x > B.b.x || B.a.x > A.b.x) return false;
	if (A.a.y > B.b.y || B.a.y > A.b.y) return false;
	return true;
}
rectangle findPoints(rectangle A, rectangle B) {
	int x1,x2,x3,x4,y1,y2,y3,y4;
	x1=A.a.x; y1=A.a.y;
	x2=A.b.x; y2=A.b.y;
	x3=B.a.x; y3=B.a.y;
	x4=B.b.x; y4=B.b.y;
	int x5 = max(x1, x3);
	int y5 = max(y1, y3);
	int x6 = min(x2, x4);
	int y6 = min(y2, y4);
	rectangle ans;
	ans.a = ii(x5, y5), ans.b = ii(x6, y6);
	return ans;
}
bool inside(rectangle A, rectangle B) {
	return (A.a.x >= B.a.x && A.b.x <= B.b.x && A.a.y >= B.a.y && A.b.y <= B.b.y);
}

struct node {
    int last; rectangle r;
};

int main() {
    setIO("picture");

    ll ans=0;
    cin >> n;
    for1(i, n) {
        ii a,b; cin >> a.x >> a.y >> b.x >> b.y;
        R[i].a = a, R[i].b = b;
        ans += 2*(abs(a.x-b.x)+abs(a.y-b.y));
        taken[i] = false;
    }

    // get rid of ones that are contained inside another.
    for1(i, n) for1(j, n) if (i!=j) {
        if (!taken[i] && inside(R[i], R[j])) {
            ans -= 2*(abs(R[i].a.x-R[i].b.x)+abs(R[i].a.y-R[i].b.y));
            taken[i] = true;
            break;
        }
    }

    vi U; vector<node> N[5005];
    int conv[5005];
    for1(i, n) {
        if (!taken[i]){
            U.pb(i);
            node a; a.last = sz(U)-1; a.r = R[i];
            N[i].pb(a);
            conv[sz(U)-1] = i;
        }
    }

    // get rid of the lines that overlaps
    forc(sz, 2, n) for0(it, sz(U)) {
        int i = U[it];
        vector<node> tmp; tmp.clear();
        for0(it2, sz(N[i])) {
            int l = N[i][it2].last;
            rectangle r = N[i][it2].r;
            forc(it3, l+1, sz(U)) {
                int id = conv[it3];
                if (overlap(r, R[id])) {
                    rectangle A = findPoints(r, R[id]);
                    ans += ((sz%2)?(1):(-1))*2*(abs(A.a.x-A.b.x)+abs(A.a.y-A.b.y));
                    node a; a.last = it3; a.r = A;
                    tmp.pb(a);
                }
            }
        }
        N[i].clear();
        N[i] = tmp;
    }
    

    cout << ans << endl;
    return 0;
}

```