# The Primes
```cpp
/*
 ID: dongliu3
 TASK: prime3
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

int _[] = {-1, 10000, 1000, 100, 10, 1};
int _p[100005];
int n, m;
vi pri;

int _d(int a, int b) { return (a/(_[b]))%10; }
int _f(int a, int b, int c, int d, int e) { return (a*10000 + b*1000 + c*100 + d*10 + e); }
int sum(int a) {
    int res = 0;
    while(a) { res+=a%10; a/=10; }
    return res;
}
bool prime(int a) {
    for(int i=2; i<=(int)sqrt(a); i++) {
        if (!(a%i)) return 0;
    }
    return 1;
}
bool _c(int a) { return (a>=0 && a<=9); }
void calculatePrimes() {
    forc(i, 10000, 99999) {
        if (prime(i) && sum(i)==n) { pri.pb(i); _p[i]=1; }
    }
}

struct num {
    int a,b,c,d,e;
    num(int a, int b, int c, int d, int e) : a(a), b(b), c(c), d(d), e(e) {}
};

vector<num> ans;

bool comp(num x, num y) {
    if (x.a < y.a) return 1;
    if (x.a > y.a) return 0;
    if (x.b < y.b) return 1;
    if (x.b > y.b) return 0;
    if (x.c < y.c) return 1;
    if (x.c > y.c) return 0;
    if (x.d < y.d) return 1;
    if (x.d > y.d) return 0;
    if (x.e < y.e) return 1;
    return 0;
}

int main() {
    setIO("prime3");

    memset(_p, 0, sizeof(_p));

    fin >> n >> m;
    calculatePrimes();   

    for (int a : pri) if(_d(a,1)==m) for (int b : pri) if(_d(b,3)==_d(a,3)) {
        for (int c : pri) if(_d(c,5)==_d(b,5)&&_d(c,1)==_d(a,1)) { 
            for(int d_=1;d_<10;d_+=2)if(d_!=5){
                int d=n-(_d(c,2)+_d(a,2)+_d(b,2)+d_);
                if (!_c(d) || !_p[_f(_d(c,2),_d(a,2),d,_d(b,2),d_)]) continue;
                for(int e_=1;e_<10;e_+=2)if(e_!=5){
                    int e=n-(_d(c,4)+_d(b,4)+_d(a,4)+e_);
                    if (!_c(e) || !_p[_f(_d(c,4),_d(b,4),e,_d(a,4),e_)]) continue;
                    for(int f__=1;f__<10; f__+=2) if(f__!=5) {
                        int rf=n-(_d(a,3)+_d(c,3)+f__);
                        for0(f_,rf+1) {
                            int f=rf-f_;
                            if (!_c(f)||!_c(f_)) continue; 
                            if (!_p[_f(_d(c,3),f,_d(a,3),f_,f__)]) continue;
                            if (!_p[_f(_d(b,1),d_,f__,e_,_d(a,5))]) continue;
                            for(int g_=1;g_<10;g_+=2)if(g_!=5){
                                int g=n-(_d(a,2)+f+_d(b,4)+g_);
                                if (!_c(g) || !_p[_f(g,_d(a,2),f,_d(b,4),g_)]) continue;
                                for(int h_=1;h_<10;h_+=2)if(h_!=5){
                                    int h=n-(d+_d(a,3)+e+h_);
                                    if(!_c(h) || !_p[_f(h,d,_d(a,3),e,h_)]) continue;
                                    for(int i_=1;i_<10;i_+=2)if(i_!=5){
                                        int i=n-(_d(b,2)+f_+_d(a,4)+i_); 
                                        if(!_c(i) || !_p[_f(i,_d(b,2),f_,_d(a,4),i_)]) continue;
                                        if(!_p[_f(_d(a,1),g,h,i,_d(b,1))]) continue;
                                        if(!_p[_f(_d(b,5),g_,h_,i_,_d(a,5))]) continue;
                                        ans.pb(num(_f(_d(a,1),_d(c,2),_d(c,3),_d(c,4),_d(b,5)),
                                                   _f(g,_d(a,2),f,_d(b,4),g_),
                                                   _f(h,d,_d(a,3),e,h_),
                                                   _f(i,_d(b,2),f_,_d(a,4),i_),
                                                   _f(_d(b,1),d_,f__,e_,_d(a,5))));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    sort(all(ans), comp);
    for0(i,sz(ans)) {
        if (i) fout <<"\n\n";
        num x = ans[i];
        fout <<x.a<<"\n"<<x.b<<"\n"<<x.c<<"\n"<<x.d<<"\n"<<x.e;
    }
    if (ans.empty()) fout <<"NONE";
    fout <<"\n";
    return 0;
}
```