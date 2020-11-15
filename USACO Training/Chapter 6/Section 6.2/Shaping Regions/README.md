```cpp
/*
 ID: dongliu3
 TASK: rect1
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
#define x first
#define y second
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
            fin.open(PROB+".in");
            fout.open(PROB+".out");
        }
    }
}


/* ============================ */

struct rect {
    int x1, y1, x2, y2, c;
    rect(int x1, int y1, int x2, int y2, int c) : x1(x1), y1(y1), x2(x2), y2(y2), c(c) {}
};

int A, B, N;
vector<rect> R;
int cnt[2505];

void newRect(int x1, int y1, int x2, int y2, int c, int idx) {
    
    while (idx <= N && (x1 >= R[idx].x2 || x2 <= R[idx].x1 || y1 >= R[idx].y2 || y2 <= R[idx].y1)) idx++;
    
    // not intersecting with rectangles painted later than idx
    if (idx == N + 1) { cnt[c] += (x2 - x1) * (y2 - y1); return; }
    
    if (x1 < R[idx].x1) { newRect(x1, y1, R[idx].x1, y2, c, idx + 1); x1 = R[idx].x1; }
    if (x2 > R[idx].x2) { newRect(R[idx].x2, y1, x2, y2, c, idx + 1); x2 = R[idx].x2; }
    if (y1 < R[idx].y1) { newRect(x1, y1, x2, R[idx].y1, c, idx + 1); y1 = R[idx].y1; }
    if (y2 > R[idx].y2) { newRect(x1, R[idx].y2, x2, y2, c, idx + 1); y2 = R[idx].y2; }
}

int main() {
    cout <<"\n+------ Starting\n"; clock_t startT = clock();

    setIO("rect1");
    fin >> A >> B >> N;
    R.push_back(rect(0, 0, A, B, 1)); 


    for0(i, N) {
        int x1, y1, x2, y2, c;
        fin >> x1 >> y1 >> x2 >> y2 >> c;
        R.push_back(rect(x1, y1, x2, y2, c));
    }
    forr0(i, N+1) {
        newRect(R[i].x1, R[i].y1, R[i].x2, R[i].y2, R[i].c, i + 1);
    }
    for1(i, 2500) if (cnt[i]) fout << i <<" " <<cnt[i]<<"\n";


    cout <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    return 0;
}


```