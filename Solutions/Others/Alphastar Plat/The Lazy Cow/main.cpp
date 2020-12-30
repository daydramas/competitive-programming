#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n; ll k;
struct G { int g; ll x,y; };
vector<G> p;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int g; ll x,y; cin >> g >> x >> y;
        p.pb({g,x-y,x+y});
    }
}
