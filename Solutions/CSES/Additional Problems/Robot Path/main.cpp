#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using pii = pair<ll, ll>;
using piii = pair<ll, pair<ll,ll> >;

int n;
pii cur, nex;
ll dis, x, td;
char dir;
multiset<piii> H, V;
vector<pair<char,ll>>todo;
int main() {
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
    cin >> n;

    dis = 0;
    cur = {0,0};
    char last='?';
    bool flag;
    // ll minX=1e15, minY=1e15, maxX=-1e15, maxY=-1e15;
    while(n--) {
        cin >> dir >> x;
        if(todo.size() && dir==todo.back().f) todo.back().s+=x;
        else todo.pb({dir, x});
    }
    ll minX=0, minY=0, maxX=0, maxY=0;
    bool shouldigo; // this is faster than goto (i think)
    bool shouldiskip=false; char skipchar='?';
    trav(idktbh, todo) {
        dir=idktbh.f, x=idktbh.s;
        if (dir == 'U') { nex = {cur.f, cur.s+x}; }
        else if (dir == 'D') { nex = {cur.f, cur.s-x}; }
        else if (dir == 'L') { nex = {cur.f-x, cur.s}; }
        else if (dir == 'R') { nex = {cur.f+x, cur.s}; }
        flag = true; shouldigo=false;
        if(shouldiskip) {
            if(dir==skipchar) break;
            else shouldigo=1;
            shouldiskip=0;
        }
        if(nex.f < minX && cur.f==minX) {shouldigo=1;}
        else if(nex.f > maxX && cur.f==maxX) {shouldigo=1;}
        else if(nex.s < minY && cur.s==minY) {shouldigo=1;}
        else if(nex.s > maxY && cur.s==maxY) {shouldigo=1;}
        if(shouldigo) {
            // cout << dir <<endl;
            if(dir=='U' || dir=='D') {
                V.insert({cur.f, {min(cur.s,nex.s), max(cur.s,nex.s)}});
            } else {
                H.insert({cur.s, {min(cur.f,nex.f), max(cur.f,nex.f)}});
            }
            cur = nex;
            if(nex.f < minX) {shouldiskip=1; skipchar='R'; }
            else if(nex.f > maxX) {shouldiskip=1; skipchar='L'; }
            else if(nex.s < minY) {shouldiskip=1; skipchar='U'; }
            else if(nex.s > maxY) {shouldiskip=1; skipchar='D'; }
            minX = min(minX, cur.f);
            minY = min(minY, cur.s);
            maxX = max(maxX, cur.f);
            maxY = max(maxY, cur.s);
            if(!shouldiskip) skipchar='?';
            dis += x;
            continue;
        }
        if(dir=='U') {
            auto it1 = H.lower_bound({min(cur.s,nex.s), {-1e15,-1e15}});
            auto it2 = H.upper_bound({max(cur.s,nex.s), {1e15,1e15}});
            ll td=1e15;
            for(auto it=it1; it!=it2; it++) if(((*it).s.f <= cur.f) && (cur.f <= (*it).s.s))
                if(((*it).s.f!=cur.f) || ((*it).f!=cur.s)) if(((*it).s.s!=cur.f) || ((*it).f!=cur.s))
                    { td=min(td,abs(cur.s-(*it).f));/* cout << "1adding "<<abs(cur.s-(*it).f)<<"\n";*/  flag=false; break; }
            auto it3 = V.lower_bound({cur.f, {-1e15, -1e15}});
            auto it4 = V.upper_bound({cur.f, {1e15, 1e15}});
            for(auto it=it3; it!=it4; it++) {
                if((*it).f != cur.f) break;
                // cerr <<min(max(cur.s,nex.s), (*it).s.s)<<" - "<<max(min(cur.s,nex.s), (*it).s.f)<<"\n";
                if (min(max(cur.s,nex.s), (*it).s.s)-max(min(cur.s,nex.s), (*it).s.f) > 0)
                    { td=min(td,min(abs(cur.s-(*it).s.f),abs(cur.s-(*it).s.s))); flag=false; break; }
            }
            if(!flag) dis += td;
        } else if (dir=='D') {
            ll td=1e15;
            if(H.size()) {
                // cout <<"+------ Before lb: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n";
                auto it1 = H.lower_bound({min(cur.s,nex.s), {-1e15,-1e15}});
                auto it2 = H.upper_bound({max(cur.s,nex.s), {1e15,1e15}}); it2=prev(it2);
                // cout <<"+------ middle lb: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n";

                for(auto it=it2; ; it--) {
                    if((*it).f>=min(cur.s,nex.s) && (*it).f<=max(cur.s,nex.s))
                        if(((*it).s.f <= cur.f) && (cur.f <= (*it).s.s))
                            if(((*it).s.f!=cur.f) || ((*it).f!=cur.s)) if(((*it).s.s!=cur.f) || ((*it).f!=cur.s))
                                { td=min(td,abs(cur.s-(*it).f));/* cout << "1adding "<<abs(cur.s-(*it).f)<<"\n";*/  flag=false; break; }
                    if(it==it1) break;
                }
                // cout <<"+------ after lb: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
            }
            if(V.size()) {
                auto it3 = V.lower_bound({cur.f, {-1e15, -1e15}});
                auto it4 = V.upper_bound({cur.f, {1e15, 1e15}}); it4=prev(it4);
                if(it3!=V.end()) for(auto it=it4; ; it--) {
                    if((*it).f != cur.f) break;
                    // cerr <<min(max(cur.s,nex.s), (*it).s.s)<<" - "<<max(min(cur.s,nex.s), (*it).s.f)<<"\n";
                    if (min(max(cur.s,nex.s), (*it).s.s)-max(min(cur.s,nex.s), (*it).s.f) > 0)
                        { td=min(td,min(abs(cur.s-(*it).s.f),abs(cur.s-(*it).s.s))); flag=false; break; }
                    if(it==it3) break;
                }
            }
            if(!flag) dis += td;
        } else if (dir=='R') {
            auto it1 = V.lower_bound({min(cur.f,nex.f), {-1e15,-1e15}});
            auto it2 = V.upper_bound({max(cur.f,nex.f), {1e15,1e15}});
            // if(it2 != V.end() && (min(cur.f,nex.f) <= (*it2).f && (*it2).f <= max(cur.f,nex.f))) it2=next(it2);
            td=1e15;
            for(auto it=it1; it!=it2; it++) if(((*it).s.f <= cur.s) && (cur.s <= (*it).s.s))
                if((cur.s!=(*it).s.f) || ((*it).f!=cur.f)) if((cur.s!=(*it).s.s) || ((*it).f!=cur.f))
                    { td=min(td,abs(cur.f-(*it).f));/* cout << "2adding "<<cur.f<<"-"<<(*it).f<<"\n"; */flag=false; break; }
            auto it3 = H.lower_bound({cur.s, {-1e15, -1e15}});
            auto it4 = H.upper_bound({cur.s, {1e15, 1e15}});
            for(auto it=it3; it!=it4; it++) {
                if((*it).f != cur.s) break;
                if (min(max(cur.f,nex.f), (*it).s.s)-max(min(cur.f,nex.f), (*it).s.f) > 0)
                    { td=min(td,min(abs(cur.f-(*it).s.f),abs(cur.f-(*it).s.s))); flag=false; break; }
            }
            if(!flag) dis+=td;
            // H.insert({cur.s, {min(cur.f,nex.f), max(cur.f,nex.f)}});
        } else if (dir=='L') {
            td=1e15;
            if(V.size()) {
                auto it1 = V.lower_bound({min(cur.f,nex.f), {-1e15,-1e15}});
                auto it2 = V.upper_bound({max(cur.f,nex.f), {1e15,1e15}});  it2=prev(it2);
                // if(it2 != V.end() && (min(cur.f,nex.f) <= (*it2).f && (*it2).f <= max(cur.f,nex.f))) it2=next(it2);

                for(auto it=it2; ; it--) {
                    if((*it).f >= min(cur.f,nex.f) && (*it).f <= max(cur.f,nex.f))
                        if(((*it).s.f <= cur.s) && (cur.s <= (*it).s.s))
                            if((cur.s!=(*it).s.f) || ((*it).f!=cur.f)) if((cur.s!=(*it).s.s) || ((*it).f!=cur.f))
                                { td=min(td,abs(cur.f-(*it).f));/* cout << "2adding "<<cur.f<<"-"<<(*it).f<<"\n"; */flag=false; break; }
                    if(it==it1) break;
                }
            }
            if(H.size()) {
                auto it3 = H.lower_bound({cur.s, {-1e15, -1e15}});
                auto it4 = H.upper_bound({cur.s, {1e15, 1e15}}); it4=prev(it4);

                if(it3!=H.end()) for(auto it=it4; ; it--) {
                    if((*it).f != cur.s) break;
                    if (min(max(cur.f,nex.f), (*it).s.s)-max(min(cur.f,nex.f), (*it).s.f) > 0)
                        { td=min(td,min(abs(cur.f-(*it).s.f),abs(cur.f-(*it).s.s))); flag=false; break; }
                    if(it==it3) break;
                }
            }
            if(!flag) dis+=td;
        }
        if(!flag) break;
        if(dir=='U' || dir=='D') {
            V.insert({cur.f, {min(cur.s,nex.s), max(cur.s,nex.s)}});
        } else {
            H.insert({cur.s, {min(cur.f,nex.f), max(cur.f,nex.f)}});
        }
        cur = nex;
        minX = min(minX, cur.f);
        minY = min(minY, cur.s);
        maxX = max(maxX, cur.f);
        maxY = max(maxY, cur.s);
        dis += x;

    }
    // cerr <<"FINAL dist = "<<dis<<endl;
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
    cout <<dis << endl;
}