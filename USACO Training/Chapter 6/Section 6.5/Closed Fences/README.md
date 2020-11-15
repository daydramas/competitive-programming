```cpp
/*
 ID: dongliu3
 TASK: fence4
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
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

/* Typdefs */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double, double> ii;
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

struct line {
    ii p1, p2;
    line(ii p1, ii p2) : p1(p1), p2(p2) {}
};

int n;
ii fj;
ii pnt[205];
bool ok[205];
vi ans; 

int ccw(ii p0, ii p1, ii p2) {
	double dx1, dx2, dy1, dy2;
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	if (dx1 * dy2 > dy1 * dx2) return +1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
	if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return +1;
	return 0;
}
int intersect(struct line l1, struct line l2) {
	return ((ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2)) <= 0)
			&& ((ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2)) <= 0);
}
int intersect_(struct line l1, struct line l2) {
	return ((ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2)) < 0)
			&& ((ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2)) < 0);
}

bool valid() {
    for0(i, n) for0(j, n) if (j!=i && (i+1)%n!=j && (j+1)%n!=i){
        if (intersect(line(pnt[i], pnt[(i+1)%n]), line(pnt[j], pnt[(j+1)%n]))) {
            return false;
        }
    }
    return true;
}
bool comp(int i, int j) {
    ii a = {i, (i+1)%n};
    ii b = {j, (j+1)%n};
    if (a.y==0) swap(a.x, a.y);
    if (b.y==0) swap(b.x, b.y);
    if (a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
int main() {
    setIO("fence4");
    
    fin >> n;
    fin >> fj.x >> fj.y;
    for0(i, n) fin >> pnt[i].x >> pnt[i].y;

    if (!valid()) { cout << "NOFENCE\n"; return 0; }

    memset(ok, true, sizeof(ok));
    for0(i, n) {
        ii t = { pnt[i].x, pnt[i].y };
        ii d = { (pnt[(i+1)%n].x-pnt[i].x)/1000,
                 (pnt[(i+1)%n].y-pnt[i].y)/1000 };
        for0(it,999) {
            t = { t.x+d.x, t.y+d.y };
            bool ok = true;
            for0(j, n) if(j!=i) {
                if (intersect(line(fj, t), line(pnt[j], pnt[(j+1)%n]))) {
                    // if (i==0) cout<<pnt[j].x<<" "<<pnt[j].y<<" | "<<pnt[(j+1)%n].x<<" "<<pnt[(j+1)%n].y<<"\n";
                    ok = false;
                    break;
                }
            }
            if (ok) { ans.pb(i); break; }
        }
    }
    fout <<ans.size()<<"\n";
    sort(all(ans), comp);
    for0(j, sz(ans)) {
        int i=ans[j];
        if (i==n-1) {
            fout <<pnt[0].x<<" "<<pnt[0].y<<" "<<pnt[n-1].x<<" "<<pnt[n-1].y<<"\n";
        } else fout <<pnt[i].x<<" "<<pnt[i].y<<" "<<pnt[(i+1)%n].x<<" "<<pnt[(i+1)%n].y<<"\n";
    }
    return 0;
}
```