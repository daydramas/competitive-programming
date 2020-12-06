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

#define double long double
using grid = vector<vector<double>>;
grid g; grid a;

int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

bool v(int i, int j) { return i>=0 && i<8 && j>=0 && j<8; }
void advance() {
    grid G(8, vector<double>(8, 0.0));
    F0R(i,8) F0R(j,8) {
        int n=0;
        F0R(k,4) if(v(i+X[k], j+Y[k])) n++;
        F0R(k,4) if (v(i+X[k], j+Y[k])) G[i+X[k]][j+Y[k]] += (g[i][j]/n);
    }
    swap(G, g);
}
int main() {
    a.assign(8, vector<double>(8, 1.0));
    int k; cin >> k;

    F0R(_,8) F0R(__,8) {
        g.assign(8, vector<double>(8, 0.0)); g[_][__]=1;
        F0R(x,k) advance();
        F0R(i,8) F0R(j,8) a[i][j] *= 1-g[i][j];
    }
    double ans = 0;
    F0R(i,8) F0R(j,8) ans += a[i][j];
    cout << fixed << setprecision(6) << ans <<"\n";
}