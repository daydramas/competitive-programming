/*
 ID: dongliu3
 TASK: beads
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int n; string s;
int lft[MX][2], rgt[MX][2]; // r=0, b=1

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    fin >> n >> s; s=" "+s+s+" ";
    lft[0][0]=lft[0][1]=0;
    for(int i=1; i<=n+n; i++) {
        if(s[i]=='r') lft[i][0]=lft[i-1][0]+1, lft[i][1]=0;
        else if(s[i]=='b') lft[i][1]=lft[i-1][1]+1, lft[i][0]=0;
        else lft[i][0]=lft[i-1][0]+1, lft[i][1]=lft[i-1][1]+1;
    }
    rgt[n+n+1][0]=rgt[n+n+1][1]=0;
    for(int i=n+n; i>=1; i--) {
        if(s[i]=='r') rgt[i][0]=rgt[i+1][0]+1, rgt[i][1]=0;
        else if(s[i]=='b') rgt[i][1]=rgt[i+1][1]+1, rgt[i][0]=0;
        else rgt[i][0]=rgt[i+1][0]+1, rgt[i][1]=rgt[i+1][1]+1;
    }
    int cnt=0;
    for(int i=0; i<=n+n; i++)
        cnt = max(cnt, max(lft[i][0], lft[i][1])+max(rgt[i+1][0], rgt[i+1][1]));
    fout << min(cnt,n) << "\n";

}