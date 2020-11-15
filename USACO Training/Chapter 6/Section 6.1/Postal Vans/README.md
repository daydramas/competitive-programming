```cpp
/*
 ID: dongliu3
 TASK: vans
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

const int MX = 600;

struct bignum {
    vi v;
    bignum(vector<int> v) : v(v) {}
    bignum(int x) {
        v.resize(MX, 0);
        for (int i=0; i<MX && x!=0; i++) {
            v[i] = x % 10;
            x /= 10;
        }
    }
    bignum operator+(const bignum &x) {
        vi out(MX, 0);
        int carry = 0;
        for0(i, MX) {
            out[i] = v[i] + x.v[i] + carry;
            carry = out[i] / 10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    bignum operator-(const bignum &x) {
        vi out = v;
        for0(i, MX) {
            if (out[i] < x.v[i]) {
                out[i + 1]--;
                out[i] += 10;
            }
            out[i] -= x.v[i];
        }
        return bignum(out);
    }
    bignum operator*(const int x) {
        vi out = v;
        int carry = 0;
        for0(i, MX) {
            out[i] = out[i]*x + carry;
            carry = out[i]/10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    void print() {
        int in = MX-1;
        while (in > 0 && v[in] == 0) in--;
        while (in >= 0) cout << v[in--];
        cout <<"\n";
    }
};

int n;
vector<bignum> a(1005, 0), b(1005, 0);

int main() {
    setIO("vans");
    
    cin >> n;
    a[1] = bignum(2); a[2] = bignum(2); a[3] = bignum(8); 
    b[2] = bignum(2); b[3] = bignum(4);
    forc(i, 4, n) {
        b[i] = a[i-1] + b[i-1];
        a[i] = b[i-1]*2 + a[i-1] + a[i-2] - a[i-3];
    }
    b[n].print();
    return 0;
}

```