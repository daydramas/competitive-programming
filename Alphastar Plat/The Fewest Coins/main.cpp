/*
 ID: dongliu3
 TASK: fewcoins
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

/* Defines */

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) 
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define dbg(x) cout <<#x<<": "<<x<<"\n";
#define dbg2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

/* Typdefs */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define PI acos(-1.0)

/* IO */

namespace IO {
    ifstream fin;
    ofstream fout;

    /* FILE SETUP */
    void setIO(const string &PROB = "") { // Input/Output Setup
        ios::sync_with_stdio(false);
        fin.tie(nullptr);
        fin.open(PROB + ".in");
        fout.open(PROB + ".out");
    }
    void setTC(const string& PROB = "", const string& TC = "") { // Test Case Setup
        ios::sync_with_stdio(false);
        fin.tie(nullptr);
        fin.open(TC + ".in");
        fout.open(PROB + ".out");
    }

    /* INPUT */
    template<class T> void cr(T& obj) { T a; cin>>a; obj=a; }; // console read
    template<class T, class... Ts> void cr(T& t, Ts&... ts) { cr(t); cr(ts...); } // console read
    template<class T> void cra(int n, T& arr, int s1=0) { for(int i=s1; i<(n+s1); ++i) cr(arr[i]); } // console read array
    template<class T> void fr(T& obj) { T a; fin>>a; obj=a; }; // file read
    template<class T, class... Ts> void fr(T& t, Ts&... ts) { fr(t); fr(ts...); } // file read
    template<class T> void fra(int n, T& arr, int s1=0) { for(int i=s1; i<(n+s1); ++i) fr(arr[i]); } // file read array

    /* OUTPUT */ 
    template<class T> void cw(T& obj) { cout << obj; } // console write
    template<class T, class... Ts> void cw(T& t, Ts&... ts) { cw(t); cw(ts...); } // console write
    template<class... Ts> void cwl(Ts&... ts) { cw(ts...); cw("\n"); } // conosle write line
    template<class T> void fw(T& obj) { fout << obj; } // file write
    template<class T, class... Ts> void fw(T& t, Ts&... ts) { fw(t); fw(ts...); } // file write
    template<class... Ts> void fwl(Ts&... ts) { fw(ts...); fw("\n"); } // file write line
}
using namespace IO;

/* ============================ */



int main() {

    // cout <<"\n+------ Starting\n"; clock_t startT = clock(); 
    setIO("fewcoins"); // setTC("fewcoins", "XX");

    int n, t; int v[105], c[105];
    cr(n,t); cra(n,v,1); cra(n,c,1);

    int dp1[11005], dp2[11005], dpCnt[11005][105];    
    for1(i,t+1000) dp1[i]=dp2[i]=INF;
    memset(dpCnt,0,sizeof(dpCnt));

    for1(i,n) for0(j,t+1001) if((v[i]+j)<=t+1000) {
        dp1[v[i]+j] = min(dp1[v[i]+j], dp1[j]+1);
    }   

    for1(i,n) for0(j,t+1001) if((v[i]+j)<=t+1000) {
        if (dp2[j]+1 < dp2[v[i]+j] && dpCnt[j][i]+1<=c[i]) {
            for1(k,n) {dpCnt[v[i]+j][k] = dpCnt[j][k]; }
            dpCnt[v[i]+j][i]++;
            dp2[v[i]+j] = dp2[j]+1;
        }
    }   
    int ans = INF;
    for(int i=t; i<=t+1000; i++) {
        ans = min(ans, dp1[i-t]+dp2[i]); 
    }
    if (ans==INF) ans=-1;
    cwl(ans);
    // cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}
