# clumsy
```cpp
/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
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

// declare any global variables
string str;
// declare any functions
void initialize(){
    cin >> str;
}
void solve(){
    int ans = 0;
    int counter = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(') counter++;
        else if (str[i] == ')'){
            counter--;
            if(counter < 0){
                ans++;
                counter += 2;
            }
        }
    }
    cout<<ans + (counter/2)<<endl;
}
void print_ans(){
    
}
int main() {
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    //close
    return 0;
}

```