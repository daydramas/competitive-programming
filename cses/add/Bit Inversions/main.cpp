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

const int maxn=2e5+5;
const int mx=524288;
int v[maxn];

#define rsz resize


string s;
int l[mx],r[mx],a[mx];

int left(int i) { return i*2; }
int right(int i) { return i*2+1; }

void upd(int id, int L, int R, int P) {
    if (P > R || P < L) return;
    if (L == R) {
        l[id]=r[id]=a[id]=1;
        return;
    }
    int M = (R+L)/2;
    upd(left(id), L, M, P);
    upd(right(id), M+1, R, P);
    l[id]=l[left(id)]; r[id]=r[right(id)];
    if (l[left(id)] == M-L+1 && v[L]==v[M+1]) l[id]+=l[right(id)];
    if (r[right(id)] == R-M && v[R]==v[M]) r[id]+=r[left(id)];
    a[id] = max(a[left(id)], a[right(id)]);
    if (v[M] == v[M+1]) a[id] = max(a[id], r[left(id)]+l[right(id)]);
}

void upd(int P) {
    upd(1, 1, s.length(), P);
}

int main() {

    cin >> s;
    int t=0; trav(c, s) v[++t]=(c=='0'?0:1);
    FOR(i,1,s.length()) upd(i);
    int n; cin >> n;

    while(n--) {
        int x; cin >> x;
        v[x] = 1-v[x];
        upd(x);
        cout << a[1] <<" ";
    }

}