# Calf Flac
```cpp
/*
 ID: dongliu3
 TASK: calfflac
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

int n;
string S;
vector<int> idx;
int line[20005];

int main() {
    setIO("calfflac");
    
    string t;
    while( getline(cin, t) ){
        S += t;
        line[S.length()]=1;
    }
    n = S.length();
    string N = "-";
    for0(i, n){
        char ch = S[i];
        if (ch>='a'&&ch<='z') {
            N += ch;
            N += "-";
            idx.pb(i);
        }
        if (ch>='A'&&ch<='Z') {
            N += ch-'A'+'a'; // convert from uppercase to lowercase
            N += "-";
            idx.pb(i);
        }
    }
    vector<int> dp(N.length()+1);
    for (int i = 1; i < N.length(); i++) {
        dp[i]=0;
        while (i - 1 - dp[i] >= 0 && i + 1 + dp[i] < N.length() && N[i - 1 - dp[i]] == N[i + 1 + dp[i]])
         dp[i]++;
    }
    int len = 0, index = -1;
    for (int i = 0; i < N.length(); i++) {
        if (dp[i] > len) {
            len = dp[i];
            index = i;
        }
    }
    int a = idx[(index - dp[index]) / 2];
    int b = idx[(index + dp[index]) / 2 - 1];
    cout << len << endl;
    string S2 = S.substr(a, b - a + 1);
    // int cnt=80;
    for (int i=a; i<=b; i++) {
        if (line[i]) cout <<"\n";
        cout << S[i];
    }
    cout <<"\n";
    return 0;
}

```