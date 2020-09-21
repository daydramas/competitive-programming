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
#define DBG(x) cout << #x << ": " << x << endl;
#define DBG2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x)(x).begin(), (x).end()
#define rall(x)(x).rbegin, (x).rend()

/* Typdefs */

typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef long long ll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef double ld;

/* IO */

ifstream fin;
ofstream fout;

void setIO(const string & PROB = "") {
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

int n, m, b[55], r[1030], sm[1030];

bool dfs(int cb, int cr) {
    if (cr <= 0) return true;

    int s = 0; for1(i, n) if (b[i]>=r[1]) s+=b[i];
	if(s<sm[cr]) return false;
    int strt=1; if (cr<m && r[cr]==r[cr+1]) strt=cb;

    forc(i, strt, n) if (b[i]==r[cr]) {
		b[i] = 0;
		bool t = dfs(1, cr - 1);
		b[i] = r[cr];
		return t;
	}
    forc(i, strt, n) if (b[i]>=r[cr]) {
		b[i] -= r[cr];
		bool t = dfs(i, cr - 1);
		b[i] += r[cr];
		if (t) return true;
	}
    return false;
}

int main() {
    setIO("fence8");

	int smb = 0;
    fin >> n; for1(i, n) { fin >> b[i]; smb += b[i]; }
	fin >> m; for1(i, m) { fin >> r[i]; }

    sort(b+1, b+n+1); sort(r+1, r+m+1);
	for1(i, m) if((sm[i]=sm[i-1]+r[i]) > smb) {
		m=i-1; break;
	}
    int l = 0, r = m, mid;
    while (l < r) {
        mid = ((l + r) / 2) + 1;
		cout << l <<" "<<r<<" m: "<<mid<<endl;
        if (dfs(1, mid)) { l = mid; }
		else { r = mid - 1; }
    }
    fout << l << endl;

    return 0;
}