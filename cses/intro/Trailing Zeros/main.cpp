#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c(int v, ll n) {
    ll pw=v, res=0;
    while(pw <= n) res += n/pw, pw*=v;
    return res;
}
int main() {
    ll n; cin >> n;
    cout << min(c(2, n), c(5, n));
}