#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;
using Matrix = v<vl>;
#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1000000000000000007;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

template<class T> struct Mat {
    T** d;
    int a, b;

    Mat() { a = b = 0; }
    Mat(int _a, int _b) : a(_a), b(_b) {
        d = new T*[a];
        F0R(i,a) {
            d[i] = new T[b];
            F0R(j,b) {
                d[i][j] = INF;
            }
        }
    }
    Mat (const vector<vector<T>>& v) : Mat(sz(v),sz(v[0])) {
        F0R(i,a) F0R(j,b) d[i][j] = v[i][j];
    }

    operator vector<vector<T>> () {
        auto ret = vector<vector<T>>(a,vector<T>(b));
        F0R(i,a) F0R(j,b) ret[i][j] = d[i][j];
        return ret;
    }
    friend void pr(const Mat& m) {
        Mat M(m); pr(vector<vector<T>>(M));
    }

    Mat operator+(const Mat& m) {
        assert(a == m.a && b == m.b);
        Mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = d[i][j]+m.d[i][j];
        return r;
    }
    Mat operator-(const Mat& m) {
        assert(a == m.a && b == m.b);
        Mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = d[i][j]-m.d[i][j];
        return r;
    }
    Mat operator*(const Mat& m) {
        assert(b == m.a);
        Mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) ckmin(r.d[i][k],d[i][j]+m.d[j][k]);
        return r;
    }

    Mat& operator+=(const Mat& m) { return *this = (*this)+m; }
    Mat& operator-=(const Mat& m) { return *this = (*this)-m; }
    Mat& operator*=(const Mat& m) { return *this = (*this)*m; }

    friend Mat exp(Mat m, ll p) {
        Mat r(m.a,m.a); assert(m.a == m.b);
        F0R(i,m.a) r.d[i][i] = 0;
        for (; p; p /= 2, m *= m) if (p&1) r *= m;
        return r;
    }
};

Mat<ll> M;

int main() {
    setIO("");

    int n, m, k; cin >> n >> m >> k;
    M = Mat<ll>(n,n);
    F0R(i,m) {
        ll a,b,c; cin >> a >> b >> c; a--,b--;
        ckmin(M.d[a][b], c);
    }
    M=exp(M, k);
    // cout << M.d[0][n-1] <<" ";
    if (M.d[0][n-1] == INF) M.d[0][n-1] = -1;
    cout << M.d[0][n-1];


}