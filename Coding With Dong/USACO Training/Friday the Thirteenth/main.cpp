#include <bits/stdc++.h>
using namespace std;

int n, cnt[7], cur;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // add 1 to feb if leap year

bool leapYear(int y) { // y = year
    if(y % 100 == 0) {
        return (y % 400 == 0);
    } else {
        return (y % 4 == 0);
    }
}

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    fin >> n;
    fill(cnt,cnt+7,0);
    cur=0; // monday
    for(int y=1900; y<=(1900+n-1); y++) { // year
        for(int m=0; m<12; m++) { // month
            cnt[(cur+12) % 7]++;
            if(m==1) { // feb
                if(leapYear(y)) {
                    cur = (cur+month[m]+1) % 7;
                } else cur = (cur+month[m]) % 7;
            } else cur = (cur+month[m]) % 7;
        }
    }
    for(int i=5; i<7; i++) fout << cnt[i]<<" "; // sat-sun
    for(int i=0; i<5; i++) fout << cnt[i]<<" "; // mon-fri
    fout <<"\n";
}