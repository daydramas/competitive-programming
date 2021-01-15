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

const int k = 31;
const int maxn = 2e5+5;
int n, a[maxn];
int mmb=-1;
vi b[k][2];

int maxBit(int x) {
    R0F(i,k) if (x & (1<<i)) return i;
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    map<int,bool> M;
    // freopen("input.in", "r", stdin);
    // freopen("output.in", "w", stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    a[0]=0; FOR(i,1,n) a[i] ^= a[i-1], mmb=max(mmb, maxBit(a[i]));
    int ans=-1;
    vi todo;
    FOR(i,1,n) {
        int x=a[i];
        if (M[x]) continue;
        M[x]=1;
        if (maxBit(x) == mmb) {
            ans = max(ans, x);
            todo.pb(x);
        } else {
            R0F(j,k) if (x & (1<<j))
                b[j][(bool)(x & (1<<(j-1)))].pb(x);
        }
    }
    // cerr <<"todo sz: "<<todo.size() <<"\n";
    // int iterations=0;
    // cerr <<"+------ bk1 | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    trav(x, todo) {
        int lf=-1;
        R0F(j,mmb) if (!(x & (1<<j)) && (b[j][0].size() || b[j][1].size())) { lf=j; break; }
        // if (ans & (1<<(mmb-1)) && lf < (mmb-1) && (!(x & (1<<(mmb-1))))) continue;
        if(lf!=-1) {
            if (x & (1<<(lf-1))) {
                if (b[lf][0].size()) trav(t, b[lf][0]) ans = max(ans, x ^ t);
                else trav(t, b[lf][1]) ans = max(ans, x ^ t);
            } else {
                if (b[lf][1].size()) trav(t, b[lf][1]) ans = max(ans, x ^ t);
                else trav(t, b[lf][0]) ans = max(ans, x ^ t);
            }
        }
    }
    cout << ans;
    // cerr <<"iterations: "<<iterations<<" | average: "<<(double)iterations/todo.size()<<"\n";
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}