# Packing Rectangles
```cpp
/*
 ID: dongliu3
 TASK: packrec
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

void setIO(const string &PROB = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (PROB.length() != 0) {
        ifstream infile(PROB + ".in");
        if (infile.good()) {
            freopen((PROB + ".in").c_str(), "r", stdin);
            freopen((PROB + ".out").c_str(), "w", stdout);
        }
    }
}

/* ============================ */

ii a[5]; ii r;
int ans[105]; int ansA = int(1e9);

void update() {
	if (r.x*r.y < ansA) {
		ansA = r.x*r.y;
        // cout<<"[ANS]: " << r.x <<" " << r.y << endl;
		memset(ans, 0, sizeof(ans));
	}
	if (r.x*r.y == ansA) { 
        ans[min(r.x, r.y)] = 1;
        // if (ansA == 40) DBG2(r.x, r.y);
    }

}

void calculate() {
	r.x = 0; r.y = 0;
	for0(i, 4) {
		r.x += a[i].x;
        // cout << "a["<<i<<"].x = "<<a[i].x<<"\n";
		if (a[i].y > r.y) r.y = a[i].y;
	}
    // cout << r.x <<" " << r.y << endl;
	update();

	r.x = 0; r.y = 0;
	forc(i, 1, 3) {
		r.x += a[i].x;
		if (a[i].y > r.y) r.y = a[i].y;
	}
	if (a[0].x > r.x) r.x = a[0].x;
	r.y += a[0].y;
	update();
	
	r.x = max(a[0].x+a[1].x, a[2].x)+a[3].x;
	r.y = max(max(a[0].y, a[1].y)+a[2].y, a[3].y);
	update();

	r.x = a[0].x+max(a[1].x, a[2].x)+a[3].x;
	r.y = max(max(a[0].y, a[1].y+a[2].y), a[3].y);
	update();

	r.x = a[0].x+a[1].x;
	r.y = max(a[0].y+a[2].y, a[1].y+a[3].y);
	if (a[0].y < a[1].y) r.x = max(r.x, a[2].x+a[1].x);
	if (a[0].y+a[2].y > a[1].y) r.x = max(r.x, a[2].x+a[3].x);
	if (a[1].y < a[0].y) r.x = max(r.x, a[0].x+a[3].x);
	r.x = max(r.x, a[2].x);
	r.x = max(r.x, a[3].x);
    update();
}

void rotate(int level) {
    if (level == 4) {
        calculate();
    } else {
        rotate(level+1); swap(a[level].x, a[level].y); // flip rectangle 90 degress
		rotate(level+1); swap(a[level].x, a[level].y); // change it back
    }
}

void permute(int level) { // loop through all the possible orderings of the 4 rectangle (4!)
    if (level == 4) {
        rotate(0);
    } else {
        forc(i, level, 3) { 
			swap(a[level], a[i]); 
			permute(level+1);
			swap(a[level], a[i]);
		}        
    }
}

int main() {
    setIO("packrec");
    for0(i, 4) {
        cin >> a[i].x >> a[i].y;
        // DBG2(a[i].x, a[i].y);
    }

    permute(0);
    
    cout << ansA << endl;
    for1(i, 100) if (ans[i]) {
        cout <<i<<" "<<(ansA/i)<<endl;
    }
    return 0;
}

```