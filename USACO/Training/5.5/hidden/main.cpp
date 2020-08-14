/*
 ID: dongliu3
 TASK: hidden
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
#define DBG(x) cout <<#x<<': '<<x<<endl;
#define DBG2(x,y) cout <<#x<<': '<<x<<' | '<<#y<<': '<<y<<endl;

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

int n;
string s;

int main() {
    setIO("hidden");

    cin >> n;
    string tmp; s="";
    while(cin >> tmp) s += tmp;
    s += s;

    int i=0,j=1,k;
    while(i<n&&j<n) {
        k=0; while(k<n && s[i+k]==s[j+k]) k++;
        if (i==0 && k==n) break;
        if (s[i+k]<s[j+k]) j+=k+1;
        else i+=k+1;
        if (i==j) j++;
    }
    // cout << i <<" " << j << endl;
    cout << min(i,j) << endl;
    return 0;
}
