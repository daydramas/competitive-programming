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
static int X[8] = {1,1,2,2,-1,-1,-2,-2};
static int Y[8] = {2,-2,1,-1,2,-2,1,-1};
int V[8][8];

bool vl(int i, int j) { // valid
    return (i>=0 && i<8 && j>=0 && j<8 && V[i][j]==0);
}
int gc(int i, int j) { // get count
    int res=0;
    F0R(k,8) res += vl(i+X[k], j+Y[k]);
    return res;
}
bool check(int ox, int oy) {
    F0R(i,8) F0R(j,8) V[i][j]=0;
    int x=ox, y=oy;
    int v=1; V[x][y]=1;
    while(v<64) {
        int nc=-1, nx=-1, ny=-1;
        int rn=rand()%8;
        F0R(it,8) {
            int k=(it+rn) % 8;
            if (!vl(x+X[k], y+Y[k])) continue;
            int c=gc(x+X[k], y+Y[k]);
            if (nc==-1 || (nc > c)) nc=c, nx=x+X[k], ny=y+Y[k];
        }
        if (nc==-1) break;
        V[nx][ny]=V[x][y]+1, v++;
        x=nx, y=ny;
    }
    return (v==64);
}
int main() {

    int x,y;
    cin >> y >> x;
    --x,--y;
    while(!check(x,y));
    F0R(i,8) {
        F0R(j,8)cout << V[i][j]<<" ";
        cout <<"\n";
    }

}