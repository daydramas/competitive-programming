#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5+5;
using ll = long long;
using pi = pair<int, ll>;
int n, ans[maxn]; ll l;
vector<pi> adj[maxn];

struct Node {
    using T = pair<ll, int>;
    Tree<T> s; int ans;
    void add(T x) {
        s.insert(x);
    }
    void merge(Node* x) {
        for(auto y : x->s) add(y);
        x->s.clear();
    }
    Node* join(Node* x) {
        if(s.size() > x->s.size()) {
            merge(x); return this;
        } else {
            x->merge(this); return x;
        }
    }
    int calc_ans(ll d) {
        return s.order_of_key({d+l, maxn});
    }
};
Node* m[maxn];

void dfs(int a, int c, ll d) {
    m[a] = new Node();
    m[a]->add({d, a});
    for(pi e : adj[a]) {
        if(e.first == c) continue;
        dfs(e.first, a, d+e.second);
        m[a] = m[a]->join(m[e.first]);
    }
    ans[a] = m[a]->calc_ans(d);
}

int main() {

    cin >> n >> l;
    for(int b=2; b<=n; b++) {
        int a; ll c;
        cin >> a >> c;
        adj[a].push_back({b, c});
    }
    dfs(1,1,0);
    for(int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
}
