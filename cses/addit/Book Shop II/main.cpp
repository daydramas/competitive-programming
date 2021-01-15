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
#define rsz resize

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 100;
const int maxx = 1e5+5;
int n, x;
int h[maxn], s[maxn], k[maxn], dp[maxx];
// vi h,s,k,dp;

int main() {
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("a.in","r", stdin);
    // freopen("a.out","w", stdout);
    cin >> n >> x;
    // h.rsz(n); s.rsz(n); k.rsz(n);
    // dp = vi(x+1);
    // trav(y, h) cin >> y;
    // trav(y, s) cin >> y;
    // trav(y, k) cin >> y;
    F0R(i,n) cin >> h[i];
    F0R(i,n) cin >> s[i];
    F0R(i,n) cin >> k[i];
    F0R(i,x+1) dp[i]=0;
    for(int i=0; i<n; i++) {
        F0R(j,20) if(k[i] >= (1<<j)) {
            int l=(1<<j), a=h[i]*l, b=l*s[i];
            R0F(y,x-a+1) dp[y+a] = max(dp[y+a], dp[y]+b);
            k[i] -= l;
        }
        if(k[i]) {
            int l=k[i], a=h[i]*l, b=l*s[i];
            R0F(y,x-a+1) dp[y+a] = max(dp[y+a], dp[y]+b);
            k[i] -= l;
        }
    }
    // for(int i=0; i<n; i++) {
    //     int l=1;
    //     while(k[i] >= l)
    // }
    // for(int j=h[i], l=1; l<=k[i]; j+=h[i], k[i]-=l, l*=2)
    // for(int y=x; y>=j; y--) {
    //     // cout <<"dp["<<y<<"] = max("<<dp[y]<<", "<<dp[y-j]<<"+"<<l<<"*"<<s[i]<<") | y-j="<<y-j<<"\n";
    //     dp[y] = max(dp[y], dp[y-j]+l*s[i]);
    //     cout <<"dp["<<y<<"]="<<dp[y]<<"\n";
    // }
    int ans=0;
    F0R(i,x+1) ans=max(ans,dp[i]);
    cout << ans;
    // cerr << ans <<" <- "<<endl;
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}