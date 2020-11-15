# horizon
```cpp

#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iterator>
using namespace std;

struct p{
    long x,s,e,h; bool change;
    p(long x, long s, long e, long h,bool change):x(x),s(s),e(e),h(h),change(change) {}
};
struct s2b {
    bool operator() (p i,p j) {
        if(i.x!=j.x) return (i.x<j.x);
        return i.e<j.e;
    }
} s2b;

int main(){
    int N;
    vector<p> interval;
    long long ans = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        long s,e,h;
        cin >> s >> e >> h;
        interval.push_back(p(s,s,e,h,true));
        interval.push_back(p(e,s,e,h,false));
    }
    sort(interval.begin(),interval.end(),s2b);
    
    multiset<long long> multi;
    //    multi.insert(1000000010);
    //    priority_queue<long long, vector<long long>, greater<long long> > multi;
    
    for(int i=0; i<((2*N)-1); i++){
        //        cout<<i<<" location "<<interval[i].x<<" s: "<<interval[i].s<<" e: "<<interval[i].e<<" h: "<<interval[i].h<<" 1/0 "<<interval[i].change<< " ans: "<<ans<<" size: "<<multi.size()<<endl;;
        if(interval[i].change){
            multi.insert(interval[i].h);
            //            cout<<"push "<< interval[i].h <<" 1/0 "<<interval[i+1].change<<endl;
        } else if (!interval[i].change){
            multi.erase(multi.find(interval[i].h));
            //            cout<<"erase " << interval[i].h <<" 1/0 "<<interval[i+1].change<<endl;
        }
        if(multi.size()==0) continue;
        //        cout<<"check"<<endl;
        multiset<int>::reverse_iterator rit = multi.rbegin();
        
        //        cout<<"check1 "<<multi.size()<<" "<<endl;
        //        cout<<" it "<<*it<<endl;
        ans += (*rit)*(interval[i+1].x-interval[i].x);
        //        cout<<"check2"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

```