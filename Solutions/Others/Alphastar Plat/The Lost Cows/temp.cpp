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
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

using pi = pair<int,int>;
using ppi = pair<pi,int>;
const int maxn = 205;
int n, m, s[maxn][maxn], one[maxn], w[maxn][maxn]; // s[barn][sign]
vector<ppi> v[maxn][maxn];
bool done[maxn], ndone[maxn];
queue<pi> Q;

int main() {

    cin >> n >> m;
    FOR(j,1,m) FOR(i,1,n) cin >> s[j][i];
    FOR(i,1,n) FOR(j,1,n) w[i][j]=-1;
    FOR(i,1,m) FOR(j,1,n) FOR(k,j+1,n) {
        v[s[i][j]][s[i][k]].pb({{j,k},i});
        v[s[i][k]][s[i][j]].pb({{j,k},i});
        if(s[i][j] == s[i][k] && w[j][k]==-1) {
            w[j][k]=i; Q.push({j,k}); }
    }

    while(!Q.empty()) {
        pi a=Q.front(); Q.pop();

        for(ppi c : v[a.f][a.s]) {
            if(w[c.f.f][c.f.s]==-1) {
                w[c.f.f][c.f.s]=c.s; Q.push({c.f.f,c.f.s}); } }

    }
    FOR(i,1,n) done[i]=false;
    queue<int> Q2; Q2.push(1); one[1]=1;
    while(!Q2.empty()) {
        int f=Q2.front(); Q2.pop();
        FOR(i,1,m) FOR(j,1,n) if(!one[j] && s[i][j]==f) {
            one[j]=i; Q2.push(j); }
    }
    // while(true) {
    FOR(i,1,n) done[i]=false;
    FOR(IT,1,10) {
        int F, S; F=S=-1;
        FOR(i,1,n) if(!done[i]) {
            if(F==-1) F=i;
            else if(S==-1) S=i;
        }
        if(F==-1) break;
        else if(S==-1) {
            while(F!=1) {
                cout << one[F] << endl;
                F = s[one[F]][F];
            }
            break;
        }
        if(F>S) swap(F,S);
        FOR(i,1,n) ndone[i]=true;
        int move = w[F][S];
        FOR(i,1,n) if(!done[i]) ndone[s[move][i]]=false;
        FOR(i,1,n) done[i]=ndone[i];
        cout << move << endl;
        // cout << "(" << F << ", " << S << ") = " << move << " = ";
        // FOR(i,1,n) cout << done[i];
        // cout <<"\n";
    }
}