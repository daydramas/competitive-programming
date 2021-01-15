#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    int n; ll k, s=0;
    cin >> n >> k;
    vector<ll> a(n+n), b(n+n);
    vi c(n+n);
    F0R(i,n) {
        int x; cin >> x;
        a[i]=a[i+n]=x;
        s+=x;
    }
    b[0]=a[0];
    FOR(i,1,n+n-1) b[i]=a[i]+b[i-1];
    if(s <= k) {
        cout <<"1";
        return 0;
    }

    int ans=1e9;
    // int lb = upper_bound(all(b), b[0]+(k-a[0]))-b.begin();
    // cerr <<"lb="<<lb<<endl;
    int lb = (4e7)/n;
    vi tbd;
    vi tolook; F0R(i,n) tolook.pb(i);
    // cerr << "lb = "<<lb<<"\n";
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(all(tolook),default_random_engine(seed));
    F0R(I,n) {
        int i = tolook[I];
        // cout <<"looking "<<i<<"\n";
        if(!lb) break; lb--;
        if(c[i]) { tbd.pb(i); continue; }
        int cur=i,cnt=0;
        while(cur<n+i) {
            c[cur]=1;
            auto it=upper_bound(all(b), b[cur]+(k-a[cur]));
            int dist = it-b.begin();
            cur = dist; cnt++;
            // if(cnt>ans) break;
        }// cout <<"\n";
        ans=min(ans,cnt);
    }

    shuffle(all(tbd),default_random_engine(seed));
    // cerr <<lb <<" - "<<sz(tbd)<<"\n";
    F0R(j,min(lb,sz(tbd))) {
        int i=tbd[j];
        int cur=i,cnt=0;
        while(cur<n+i) {
            // if(cur+1<(n+n) && a[cur]+a[cur+1] > k) {
            //     cur++, cnt++; continue;
            // }
            int dist = upper_bound(all(b), b[cur]+(k-a[cur]))-b.begin();
            cur = dist; cnt++;
            if(cnt>ans) break;
        }
        ans=min(ans,cnt);
    }
    int lst=0; FOR(i,1,n-1) if(a[i]>a[lst]) lst=i;
    int i=lst; int cur=i,cnt=0;
    while(cur<n+i) {
        // if(cur+1<(n+n) && a[cur]+a[cur+1] > k) {
        //     cur++, cnt++; continue;
        // }
        int dist = upper_bound(all(b), b[cur]+(k-a[cur]))-b.begin();
        cur = dist; cnt++;
        if(cnt>ans) break;
    }
    ans=min(ans,cnt);
    cout << ans;
    // cerr << ans;
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}