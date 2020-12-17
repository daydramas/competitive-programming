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

const int maxn = 1005;
const int mod = 1e9+7;

using T = ll;

int n;
T BC[maxn][maxn]; // binomial
T F[maxn]; // factorial
T ans, tmp;

int main() {

    cin >> n;
    F0R(i,n+1) {
        BC[i][0]=1;
        FOR(j,1,i) BC[i][j] = (0LL+BC[i-1][j]+BC[i-1][j-1]) % mod;
    }
    F[0]=1; FOR(i,1,n) F[i]=(1LL*F[i-1]*i) % mod;
    ans=0; F0R(i,n) { tmp=0;
        F0R(j,i+1) tmp = (0LL+tmp+BC[n-i][j]*BC[n-j-1][i-j]) % mod;
        tmp = (1LL*tmp*F[n-i]) % mod;
        // cout << tmp <<"\n";
        if(i&1) ans = (ans-tmp+mod) % mod;
        else ans = (ans+tmp) % mod;
    }
    cout << ans;

}