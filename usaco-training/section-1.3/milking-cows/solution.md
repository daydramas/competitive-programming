# Solution \(milk2\)

```cpp
/*
 ID: dongliu3
 TASK: milk2
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// define/structures
#define Pair pair<int, int>
// global variables
int N;
vector<Pair> I;
// functions

int main() {
    // local variables

    // fstream
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    // input
    fin >> N;
    for(int i=0; i<N; i++){
        int a,b; fin >> a >> b;
        I.push_back(Pair(a,-1));
        I.push_back(Pair(b,1));
    }
    sort(I.begin(), I.end());
    // main
    int zero = 0, one = 0, count = 0, cone = 0, czero = 0;
    for(int i=0; i<I.size(); i++) {
        cout << I[i].first<<". "<<I[i].second << endl;
        if(i) {
            if(count) {
                cone += I[i].first-I[i-1].first;
                one = max(one, cone);
                czero = 0;
            } else {
                czero += I[i].first-I[i-1].first;
                zero = max(zero, czero);
                cone = 0;
            }
        }
        count -= I[i].second;
    }
    // output
    fout << one << " " << zero << endl;
    return 0;
}
```

