#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n, d[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; fill(d+1,d+n+1,0);
    for(int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        d[a]++, d[b]++;
    }
    int c=n-1; d[1]++;
    for(int i=1; i<=n; i++) c += ceil(log2(d[i]));
    cout << c << "\n";
}