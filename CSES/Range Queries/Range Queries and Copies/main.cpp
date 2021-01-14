#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

struct node {
    ll val;
    node* left, *right;
    node() {}
    node(node* l, node* r, int v)
    {
        left = l;
        right = r;
        val = v;
    }
};

int arr[MX];
node* version[MX];

void build(node* n,int low,int high) {
    if (low==high) {
        n->val = arr[low];
        return;
    }
    int mid = (low+high) / 2;
    n->left = new node(NULL, NULL, 0);
    n->right = new node(NULL, NULL, 0);
    build(n->left, low, mid);
    build(n->right, mid+1, high);
    n->val = n->left->val + n->right->val;
}

node *update(node *t, int l, int r, int i, ll x) {
    node *t_ = new node(NULL, NULL, 0);

    if (r == l) t_->val = x;
    else {
        int m = (l + r) / 2;

        if (i <= m) {
            t_->left = update(t->left, l, m, i, x);
            t_->right = t->right;
        } else {
            t_->left = t->left;
            t_->right = update(t->right, m+1, r, i, x);
        }
        t_->val = t_->left->val + t_->right->val;
    }
    return t_;
}
ll query(node* n, int low, int high, int l, int r) {
    if (l > high or r < low or low > high)
       return 0;
    if (l <= low and high <= r)
       return n->val;
    int mid = (low+high) / 2;
    ll p1 = query(n->left,low,mid,l,r);
    ll p2 = query(n->right,mid+1,high,l,r);
    return p1+p2;
}

int main() {
    setIO("");

    int n, q; cin >> n >> q;
    FOR(i,1,n) cin >> arr[i];

    node* root = new node(NULL, NULL, 0);
    build(root, 1, n);
    version[1] = root; int versionc=1;

    F0R(i,q) {
        int t; cin >> t;
        if (t==1) {
            int k, a, x; cin >> k >> a >> x;
            version[k] = update(version[k], 1, n, a, x);
        } else if (t==2) {
            int k, a, b; cin >> k >> a >> b;
            cout << query(version[k], 1, n, a, b) <<"\n";
        } else if (t==3) {
            int k; cin >> k;
            version[++versionc] = version[k];
        }
    }

}