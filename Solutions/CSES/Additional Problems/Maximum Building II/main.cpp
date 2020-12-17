#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 105;

int n, m;
char g[maxn][maxn]; // grid
int nr[maxn][maxn]; // next right
int nd[maxn][maxn]; // next down

int main() {

    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,n) cin >> g[i][j];

    FOR(i,1,n) {
        int NR=m+1;
        ROF(j,1,m) {
            if(g[i][j]=='*') NR=j;
            nr[i][j]=NR;
        }
    }
    FOR(j,1,n) {
        int ND=n+1;
        ROF(i,1,n) {
            if(g[i][j]=='*') ND=i;
            nd[i][j]=ND;
        }
    }

}