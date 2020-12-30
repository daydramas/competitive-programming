#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int maxn = 1e5+5;
int n, m, w[maxn], d[maxn];
vector<int> adj[maxn], adj2[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    fill(w+1,w+n+1,0);
    fill(d+1,d+n+1,0);
    while(m--) {
        int a, b; cin >> a >> b;
        adj2[b].pb(a); w[a]++;
    }
    queue<int> Q; vector<int> ord;
    for(int i=1; i<=n; i++) {
        if(!w[i]) Q.push(i); }
    while(Q.size()) {
        int a=Q.front(); Q.pop(); ord.pb(a);
        for(int b : adj2[a]) if(!(--w[b])) {
            Q.push(b); }
    }
    for(int a : ord) for(int b : adj2[a])
        d[b] = max(d[b], d[a]+1);
    for(int i=1; i<=n; i++) {
        if(d[i]!=0) cout <<"0\n";
        else {
            bool f=0;
            for(int j : adj[i]) if(d[j]==0) {
                cout <<"1\n"; f=1; break; }
            if(!f) cout <<"0\n";
        }
    }

}