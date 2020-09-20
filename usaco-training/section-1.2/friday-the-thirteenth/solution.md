# Solution \(friday\)

```cpp
/*
 ID: dongliu3
 TASK: friday
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// define/structures

// global variables
int N, ans[7];
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// functions
bool leapYear(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    } else {
        return year % 4 == 0;
    }
}
int main() {
    // local variables

    // fstream
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    // input
    fin >> N;
    // main
    int day = 0;
    for(int i=1900; i<1900+N; i++) {
        for(int j=0; j<12; j++) {
            ans[(day + 12) % 7]++;
            if(j==1) {
                if(leapYear(i)) day += month[j]+1;
                else day += month[j];
            } else day += month[j];
        }
    }
    // output
    for(int i=5; i<7; i++) fout << ans[i] <<" ";
    for(int i=0; i<4; i++) fout << ans[i] <<" ";
    fout << ans[4] << endl;
    return 0;
}
```

