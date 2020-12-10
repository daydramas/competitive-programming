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

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}
#define pc putchar_unlocked
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

const int maxn = 1e5+5;

int n; vi adj[maxn], leaf;

void dfs(int root, int par=-1) {
    if (adj[root].size() == 1) leaf.pb(root);
    trav(child, adj[root]) {
        if (par != child) dfs(child, root);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;//ri(a); ri(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    int k=(leaf.size()+1)/2, j=k-1; cout<<k<<"\n";//wi(k); pc('\n');
    F0R(i,k-1) cout <<leaf[i]<<" "<<leaf[j*2-i]<<"\n";
    //wi(leaf[i]), pc(' '), wi(leaf[j*2-i]), pc('\n');
    cout<<leaf[j]<<" "<<leaf[leaf.size()-1]<<"\n";
    // wi(leaf[j]), pc(' '), wi(leaf[leaf.size()-1]);
}