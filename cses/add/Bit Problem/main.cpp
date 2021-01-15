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

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 2e5+5;
const int maxm = 1<<20;
int n;
int v[maxn];
int a[maxm], b[maxm];

int main() {

    cin >> n;
    F0R(i,n) {
        int x; cin >> x;
        a[x]++, b[x]++, v[i]=x;
    }
    F0R(k, 20) F0R(m, maxm)  {
        if (m & (1<<k)) a[m] += a[m ^ (1<<k)];
        else b[m] += b[m ^ (1<<k)];
    }
    F0R(i,n) cout << a[v[i]] <<" "<<b[v[i]]<<" "<<n-a[v[i] ^ (maxm - 1)]<<"\n";
}