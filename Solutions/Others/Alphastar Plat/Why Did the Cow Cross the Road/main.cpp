#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n, a[maxn], b[maxn], c[maxn], d[maxn], ans[maxn];

using T = long long; T B[maxn];
void init() { for(int i=0; i<maxn; i++) B[i]=0; }
void upd(int i) { for(; i<maxn; i+=i&(-i)) B[i]++; }
T qry(int i) { T R=0; for(; i; i-=i&(-i)) R+=B[i];
	return R; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; d[a[i]]=i; }
    for(int j=1; j<=n; j++) { cin >> b[j]; c[b[j]]=j; }
    T r, s=0; init();
    for(int i=1; i<=n; i++) {
        upd(c[a[i]]);
        s+=ans[i]=c[a[i]]-qry(c[a[i]]);
    }
    // cout <<"s="<<s<<"\n";
    r=s; for(int i=1; i<=n; i++) {
        s += n-2*(c[a[i]]-1)-1;
        // cout <<"a="<<a[i]<<" | ans["<<i<<"]="<<ans[i]<<" | s="<<s<<"\n";
        r = min(r, s);
    }
    s=0; init();
    for(int i=1; i<=n; i++) {
        upd(d[b[i]]);
        s+=ans[i]=d[b[i]]-qry(d[b[i]]);
    }
    // cout <<"s="<<s<<"\n";
    for(int i=1; i<=n; i++) {
        s += n-2*(d[b[i]]-1)-1;
        r = min(r, s);
    }
    cout << r << '\n';

}