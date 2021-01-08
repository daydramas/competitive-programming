#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

namespace IO {
    /* INPUT */
    char nc() { return getchar_unlocked(); }
    void rs(string& x) {
        char ch; x=""; while (isspace(ch = nc()));
        do { x += ch; } while (!isspace(ch = nc()) && ch != EOF); }
    template<class T> void ri(T &x) {
        int sgn=1; char ch; x=0;
        while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
        x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
        x *= sgn; }
    template<class T, class... Ts> void ri(T& t, Ts&... ts) {
        ri(t); ri(ts...); }
    /* OUTPUT */
    void wc(char ch) { putchar_unlocked(ch); }
    void ws(string x) { for(char ch : x) wc(ch); }
    template<class T> inline void wi(T x) {
        if(x < 0) x*=-1, wc('-');
        if(0 <= x && x <= 9) wc('0'+x);
        else wi(x/10), wc('0'+x%10); }
};
using namespace IO;

int main() {

    int n, K; ri(n,K);
    string t; int a[n]; F0R(i,n) {
        a[i]=0; rs(t); F0R(j,K) if(t[j]=='1') {
            a[i] += (1<<j); } }
    int ans = K, cur=0;
    sort(a,a+n);
    F0R(i,n) { int j=(i+1)%n; cur = 0;
        F0R(k,K) if((a[i]&(1<<k)) ^ (a[j]&(1<<k))) {
            cur++; if(cur>ans) break; }
        if(cur < ans) ans = cur; }
    if(ans!=0) F0R(i,n) FOR(j,i+1,n-1) {
        cur = 0;
        F0R(k,K) if((a[i]&(1<<k)) ^ (a[j]&(1<<k))) {
            cur++; if(cur>ans) break; }
        if(cur < ans) ans = cur;
        if(ans<=1) break;
    }
    wi(ans);

}