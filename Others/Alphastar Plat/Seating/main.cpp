#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = 5e5;
using T = int; T ans=0;
T lft[(maxn+5)*4], rgt[(maxn+5)*4], mx[(maxn+5)*4], sz[(maxn+5)*4], lz[(maxn+5)*4];
T ID=0;
void build(int i=1, int l=1, int r=n) {
    lft[i]=rgt[i]=mx[i]=sz[i]=(r-l+1);lz[i]=0; int m=(l+r)/2;
    if(l!=r) build(i*2,l,m), build(i*2+1,m+1,r);
}
void pull(int i) {
    lft[i]=lft[i*2]+(lft[i*2]==sz[i*2]?lft[i*2+1]:0);
    rgt[i]=rgt[i*2+1]+(rgt[i*2+1]==sz[i*2+1]?rgt[i*2]:0);
    mx[i]=max(max(mx[i*2],mx[i*2+1]), rgt[i*2]+lft[i*2+1]);
}
void push(int i, int l, int r) {
    if(!lz[i]) return;
    if(lz[i]==1) lft[i]=rgt[i]=mx[i]=0; // to be filled
    else lft[i]=rgt[i]=mx[i]=sz[i]; // to be emptied
	if(l!=r) lz[i*2]=lz[i*2+1]=lz[i];
	lz[i]=0;
}
void upd(int L, int R, T v, int i=1, int l=1, int r=n) {
	push(i,l,r); if(R<l || L>r) return;
	if(L<=l && R>=r) { lz[i]=v; push(i,l,r); return; }
	int m=(l+r)/2; upd(L,R,v,i*2,l,m);
	upd(L,R,v,i*2+1,m+1,r); pull(i);
}
int qry(int s, int i=1, int l=1, int r=n) {
    push(i,l,r); int m=(l+r)/2;
    if(l==r) return l;
    if(mx[i*2] >= s) return qry(s, i*2, l, m);
    else if(rgt[i*2]+lft[i*2+1] >= s) return m-rgt[i*2]+1;
    return qry(s, i*2+1, m+1, r);
}
void seat(int s) {
    push(1,1,n); if(mx[1] < s) { ++ans; return; }
    int p=qry(s); upd(p, p+s-1, 1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    build();
    // while(m--) {
    for(int i=0; i<m; i++) {
        char t; cin >> t;
        if(t=='A') {
            int a; cin >> a; seat(a);
        } else {
            int a, b; cin >> a >> b;
            upd(a, b, 2);
        }
    }
    cout << ans << '\n';
}