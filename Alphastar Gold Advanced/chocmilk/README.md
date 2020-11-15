# chocmilk
```cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
// structures / defines


// global variables
int N;
int comeIn[100001], comeOut[100001], nextValue[100001];

// functions

int main() {

    cin >> N;
    for(int i=1; i<=N; i++) comeOut[i]=comeIn[i]=0;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        nextValue[a] = b;
        comeOut[a]++;
        comeIn[b]++;
    }

    int start = -1;
    for (int i=1, current=-1; i<=N; i++) {
		if (current == i)
			if (start < 0 || comeIn[i] > 1)
				start=i;

		if (comeOut[i] == 1) {
			current = max(current, nextValue[i]);
		} else break;
    }

    for (int i=start; i<=N; i=nextValue[i]) {
		cout << i << endl;
		if (comeOut[i]==0 or comeOut[i]>1) break;
    }
    return 0;
}

```