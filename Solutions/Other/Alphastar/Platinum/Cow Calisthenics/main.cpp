#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
int n, k, ans;
vector<int> g[maxn];

int dfs(int a, int c, int d) {
    vector<int> v = {0};
    for(int b : g[a]) if(b!=c)
        v.push_back(dfs(b,a,d)+1);
    sort(v.rbegin(), v.rend());
    while(v.size()>1 && v.back()+v[v.size()-2] <= d) v.pop_back();
    ans += v.size()-1;
    return v.back();
}

int main() {

    cin >> n >> k;
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int l=0, r=n;
    while(l<r) {
        int m=(l+r)/2;
        ans=0; dfs(1,1,m);
        if(ans <= k) r=m;
        else l=m+1;
    }
    cout << l << '\n';
}