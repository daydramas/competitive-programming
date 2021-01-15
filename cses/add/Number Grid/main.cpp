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

ll x, y, k, ans;

ll getK(ll x) {
    R0F(i,31) {
        if(x > (1<<i)) return i;
        else if (x==(1<<i)) return i-1;
    }
    return 0;
}

int main() {
    cin >> x >> y;
    if(x<y) swap(x,y);
    if(x==1) { cout <<"0"; exit(0); }
    if(y==1) { cout <<x-1; exit(0); }
    x--,y--;
    ans=0;
    // cout <<"k="<<k<<"\n";
    while(y>1 || x>1) {
        k = getK(x+1);
        // cout << "k="<<k<<"\n";
        if(y < (1<<k)) {
            ans += (1<<k);
        } else y = y % (1<<k);
        x %= (1<<(k));
        if(x<y) swap(x,y);
    }
    // R0F(i,k+1) {
    // ROF(i,1,k) {
    //     if(y < (1<<i)) {
    //         cout <<"k="<<i<<" | y="<<y<<"\n";
    //         ans += (1<<i);
    //         // y = y % (1<<i);
    //     } else {
    //         cout <<y<<" = "<<y<<" % "<<(1<<i)<<"\n";
    //         y = y % (1<<i);
    //     }
    // }
    if(y<=1) {
        ans += (x%2)^y;
    }
    cout << ans;
}