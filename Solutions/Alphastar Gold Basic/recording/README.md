# recording
```cpp
//============================================================================
// Name        : cpp_template.cpp
// Author      : Dong Liu
// Website     : dongliu.template.com
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// declare any structures
using namespace std;

vector<pair<int, int> > show;
int N;

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        show.push_back(make_pair(b,a));
    }
    sort(show.begin(), show.end());
    
    int ans = 0;
    int t1, t2;
    t1 = t2 = 0;
    for(int i = 0; i < N; ++i) {
        int start = show[i].second;
        if(start < t1) {
            continue;
        } else if(start<t2) {
            t1 = t2;
            t2 = show[i].first;
            ans++;
        } else {
            t2 = show[i].first;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

```