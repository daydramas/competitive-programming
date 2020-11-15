# contact
```cpp
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

// declare any functions

int main() {
    // declare any local variables
    int A, B, N;
    map<long long, long> count;
    string full_view = "";
    
    // input
    cin >> A >> B >> N;
    string temp;
    getline(cin, temp);
    getline(cin, temp);
    while(true){
        full_view = full_view + temp;
        getline(cin, temp);
        if(temp=="") break;
    }
    // main
    for(int i=A; i<=B; i++){
        if(full_view.size()<i) break;
        string substring = full_view.substr(0,i);
        count[stol("1"+substring)]++;
        for(int j=i; j<full_view.size(); j++){
            substring.erase(substring.begin());
            substring = substring + full_view[j];
            count[stol("1"+substring)]++;
        }
    }
    
    map<long long, vector<long> > counted;
    for(map<long, long >::reverse_iterator rit=count.rbegin(); rit!=count.rend(); ++rit){
        counted[rit->second].push_back(rit->first);
    }
    // output
    int counter0 = 0;
    for(map<int, vector<long> >::reverse_iterator rit=counted.rbegin(); rit!=counted.rend(); ++rit){
        sort(counted[rit->first].begin(), counted[rit->first].end());
    }
    for(map<int, vector<long> >::reverse_iterator rit=counted.rbegin(); rit!=counted.rend(); ++rit){
        counter0++;
        cout<<rit->first<<endl;
        int counter=0;
        for(int i=0; i<rit->second.size();i++){
            string new_string = to_string(rit->second[i]);
            cout<<new_string.substr(1,new_string.size()-1)<<" ";
            counter++;
            if(counter==6){
                counter=0;
                cout<<endl;
            }
        }
        if(counter!=0) cout<<endl;
        if(counter0==N) break;
    }
    return 0;
}

```