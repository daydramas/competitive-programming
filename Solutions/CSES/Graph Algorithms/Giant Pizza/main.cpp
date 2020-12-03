/* LOL I didn't use SCC */
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

int n, m;
vi w1,w2,d,r;

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}


int main() {

    // cin >> n >> m;
    ri(n); ri(m);
    w1.resize(n+1), w2.resize(n+1);
    d.resize(m+1); r.resize(m+1);
    FOR(i,1,n) {
        char s1, s2;
        s1=getchar_unlocked(); getchar_unlocked(); ri(w1[i]);
        s2=getchar_unlocked(); getchar_unlocked(); ri(w2[i]);
        if (s1=='-') d[w1[i]]--, w1[i] *= -1;
        else d[w1[i]]++;

        if (s2=='-') d[w2[i]]--, w2[i] *= -1;
        else d[w2[i]]++;
    }
    FOR(i,1,n) {
        int v1=abs(w1[i]), v2=abs(w2[i]);
        if (r[v1]!=0 && r[v1]==(w1[i]/v1)) { continue; }
        if (r[v2]!=0 && r[v2]==(w2[i]/v2)) { continue; }
        if (r[v1]!=0 && r[v2]==0) { r[v2]=(w2[i]/v2); continue; }
        if (r[v1]==0 && r[v2]!=0) { r[v1]=(w1[i]/v1); continue; }
        if (r[v1]==0 && r[v2]==0) {
            int m1=d[v1]/(w1[i]/v1);
            int m2=d[v2]/(w2[i]/v2);
            if (m1>m2) { r[v1]=(w1[i]/v1); }
            else { r[v2]=(w2[i]/v2); }
            continue;
        }
        cout <<"IMPOSSIBLE"; goto end;
    }
    FOR(i,1,m) cout << (r[i]==-1?"-":"+") <<" ";
    end: return 0;
}