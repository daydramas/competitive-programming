# fpot
```cpp
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

struct raindrop {
  int x; int time;
  raindrop(int x, int time) : x(x), time(time) {}
};
struct s2b {
  bool operator() (raindrop i, raindrop j) { return (i.x<j.x);}
} s2b;

int N, D;
vector<raindrop> rdrop;
multiset<int> twoPoint;

long long ans = 1000000000;
int main() {

  cin >> N >> D;
  for(int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;
    rdrop.push_back(raindrop(x, y));
  }
  sort(rdrop.begin(), rdrop.end(), s2b);

  int i=0, j=0;
  twoPoint.insert(rdrop[0].time);
  while(true) {
    if(*twoPoint.rbegin()-*twoPoint.begin() >= D) {
      ans = min(ans, (long long) rdrop[j].x-rdrop[i].x);
      twoPoint.erase(twoPoint.find(rdrop[i++].time));
    } else {
      if (j==N-1) break;
      twoPoint.insert(rdrop[++j].time);
    }
  }
  if(ans != 1000000000) cout << ans << endl;
  else cout << "-1" << endl;
}

```