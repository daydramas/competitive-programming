# bds
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables
int pascaln[11];
// declare any functions
int pascal2(int n, int k)
{
    int temp = 1;
    if (k>(n-k)) k = n-k;
    for (int i=0; i<k; i++) {
        temp *= (n-i);
        temp /= (i+1);
    }
    return temp;
}
void Pascal(int n) {
    for (int i=0; i<n; i++){
        pascaln[i] = pascal2(n-1, i);
    }
}



int main() {
    // declare any local variables
    int N,sum;
    
    cin >> N >> sum;
    
    // input
    int arr[N];
    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }
    
    // main
    Pascal(N);
    
    do {
        int csum = 0;
        for(int i=0; i<N; i++){
            csum += arr[i]*pascaln[i];
        }
        if(csum==sum){
            break;
        }
    } while (next_permutation(arr,arr+N) );
    // output
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

```