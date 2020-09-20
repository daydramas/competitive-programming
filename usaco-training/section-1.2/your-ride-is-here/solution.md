# Solution \(ride\)

```cpp
/*
 ID: dongliu3
 TASK: ride
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// define/structures

// global variables

// functions
int calcCode(string str) {
    int cnt = 1;
    for(int i=0; i<str.size(); i++) {
        cnt *= str[i]-'A'+1;
        cnt %= 47;
    }
    return cnt;
}
int main() {
    // local variables

    // fstream
    ifstream fin("ride.in");
    ofstream fout("ride.out");

    // input
    string a, b;
    fin >> a >> b;

    // main
    if(calcCode(a) == calcCode(b)) fout << "GO" << endl;
    else fout << "STAY" << endl;

    // output

    return 0;
}
```

