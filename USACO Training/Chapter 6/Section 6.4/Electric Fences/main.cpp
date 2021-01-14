/*
 ID: dongliu3
 TASK: fence3
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

#define INF 2147483647
#define EPS 1e-8

struct point {
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    point operator-(const point &a) {
        return point(x - a.x, y - a.y);
    }
    bool operator==(const point &a) {
        return x == a.x && y == a.y;
    }
};

struct line {
    double x1, y1, x2, y2;
    line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    point end0() {return point(x1, y1);}
    point end1() {return point(x2, y2);}
};

double direc[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

double cross(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double dot(point a, point b, point c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

double length(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(point p, line l) {
    if (l.end0() == l.end1()) return length(p, l.end0());
    if (dot(l.end0(), l.end1(), p) < 0) return length(l.end0(), p);
    else if (dot(l.end1(), l.end0(), p) < 0) return length(l.end1(), p);
    else return fabs(cross(l.end0(), l.end1(), p)) / length(l.end0(), l.end1());
}

int F;
vector<line> fence;

int main() {
    setIO("fence3");
    
    fin >> F;
    int x1, y1, x2, y2;
    for0(i, F) {
        fin >> x1 >> y1 >> x2 >> y2;
        fence.push_back(line(x1, y1, x2, y2));
    }
    point p = fence[0].end0();
    double T = 100, ans = INF, delta = 0.98;
    int i;
    while (T > (double)(1e-08)) {
        bool ok = 1;
        while (ok) for(i=0, ok=0; i<4; i++){
            point tmp(p.x + direc[i][0] * T, p.y + direc[i][1] * T);
            double tans = 0;
            for0(j, F) tans += dist(tmp, fence[j]);
            if (tans < ans) { ans = tans, p = tmp, ok = 1; }
        }
        T *= delta;
    }
    fout.setf(ios::fixed);
    fout << setprecision(1) << (double)p.x << " " << (double)p.y << " " << ans << endl;
    
    return 0;
}
