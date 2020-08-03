/*
 ID: dongliu3
 TASK: window
 LANG: C++
 */

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

// structures/defines
struct Window {
    int x1, y1, x2, y2, layer;
    bool alive;
    void init(int x1_, int y1_, int x2_, int y2_, int layer_, bool alive_) {
    	x1=x1_,y1=y1_,x2=x2_,y2=y2_,layer=layer_,alive=alive_;
    }
} windows[128];
// global variables
int topLayer = 1;
int bottomLayer = 0;

// functions

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
int area(int x1, int y1, int x2, int y2) {
    return (y1-y2)*(x2 - x1);
}

int calcArea(int x1, int y1, int x2, int y2, int layer) {
    if (x2 <= x1 || y2 <= y1) return 0;

    for (int i = 0; i < 128; i++) {
        if (!windows[i].alive || windows[i].layer <= layer) continue;
        if (y2 <= windows[i].y1 || windows[i].y2 <= y1 || x2 <= windows[i].x1 || windows[i].x2 <= x1) continue;
        return calcArea(x1, y1, max(windows[i].x1, x1), y2, layer)
               + calcArea(max(windows[i].x1, x1), min(windows[i].y2, y2), min(windows[i].x2, x2), y2, layer)
               + calcArea(min(windows[i].x2, x2), y1, x2, y2, layer)
               + calcArea(max(windows[i].x1, x1), y1, min(windows[i].x2, x2), max(windows[i].y1, y1), layer);
    }

    return area(x1, y1, x2, y2);
}
int main() {
	// local variables

	// fstream
	setIO("window");

	// input
	char ty;
	while (cin >> ty) {
		char id, junk;
		if (ty=='w') {
			int x1, y1, x2, y2;
			cin >> junk >> id >> junk >> x1 >> junk >> y1 >> junk >> x2 >> junk >> y2 >> junk;
			windows[id].init(min(x1,x2), min(y1,y2), max(x1,x2), max(y1,y2), topLayer++, true);
		} else if (ty=='t') {
			 cin >> junk >> id >> junk;
			 windows[id].layer = topLayer++;
		} else if (ty=='b') {
			cin >> junk >> id >> junk;
			windows[id].layer = bottomLayer--;
		} else if (ty=='d') {
			cin >> junk >> id >> junk;
			windows[id].alive = false;
		} else if (ty=='s') {
			cin >> junk >> id >> junk;
			cout << fixed << setprecision(3) << abs(100.0*double(calcArea(windows[id].x1, windows[id].y1, windows[id].x2, windows[id].y2, windows[id].layer))/double(area(windows[id].x1, windows[id].y1, windows[id].x2, windows[id].y2)))<<endl;
		}
	}
	// output

	return 0;
}
