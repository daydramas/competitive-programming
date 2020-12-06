#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k; ri(n); ri(k);// cin >> n >> k;
    int p[k]; F0R(i,k) ri(p[i]); sort(p,p+k);
    string dp = string(n, 'L');
    F0R(j,k) dp[p[j]-1]='W';
    FOR(i,1,n) if(dp[i-1]=='L') F0R(j,k) {
        if (p[j]+i > n) break;
        dp[p[j]+i-1] = 'W';
    }
    F0R(i,n) putchar_unlocked(dp[i]);
}