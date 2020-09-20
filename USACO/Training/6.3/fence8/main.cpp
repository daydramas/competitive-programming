/*
 ID: dongliu3
 TASK: fence8
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
#define DBG(x) cout <<#x<<": "<<x<<endl;
#define DBG2(x,y) cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;

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

/* IO */

ifstream fin;
ofstream fout;

void setIO(const string &PROB = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (PROB.length() != 0) {
        ifstream infile(PROB + ".in");
        if (infile.good()) {
            fin.open(PROB + ".in");
            fout.open(PROB + ".out");
        }
    }
}

/* ============================ */

const int maxn = 52;
const int maxm = 1024;
int n,m,b[maxn],r[maxm];
int sum_b,sum[maxm];

int main() {
    setIO("fence8");
    
    fin>>n; sum_b=0;
    for1(i, n) { fin>>b[i]; sum_b+=b[i]; }
	fin>>m; for1(i, m) fin>>r[i];

    sort(b+1, b+n+1);
	int idx=1;
	for1(i, m) if(r[i]<=b[n]) {
        r[idx]=r[i];
        idx++;
	}
	m=idx-1;
	sort(r+1,r+m+1);
	for(int i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+r[i];
		if(sum[i]>sum_b)
		{
			m=i-1;
			break;
		}
	}
	int l=0,r=m,mid;
	while(l<r) {
		mid=((l+r)>>1)+1;
		if(dfs(1,mid))
			l=mid;
		else
			r=mid-1;
	}
	fout<<l<<endl;
	fin.close();
	fout.close();
	return 0;

    return 0;
}
