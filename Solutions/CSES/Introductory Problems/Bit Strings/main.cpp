#include <bits/stdc++.h>
using namespace std;
#define ll long long

int pow(int x, int n, int MOD) {
    long long y = x;
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1)
            res = res * y % MOD;
        y = y * y % MOD;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m=1e9+7; cin>>n;
    cout<<pow(2,n,m);
}