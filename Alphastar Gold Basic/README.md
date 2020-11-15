<div align="center"> <a href="#0">agrinet.cpp</a> | <a href="#1">auto.cpp</a> | <a href="#2">bds.cpp</a> | <a href="#3">bullcow.cpp</a> | <a href="#4">buyhay.cpp</a> | <a href="#5">cardgame.cpp</a> | <a href="#6">catchcow.cpp</a> | <a href="#7">cgiving.cpp</a> | <a href="#8">cgiving2.cpp</a> | <a href="#9">change.cpp</a> | <a href="#10">charm.cpp</a> | <a href="#11">checklist.cpp</a> | <a href="#12">clumsy.cpp</a> | <a href="#13">coaster.cpp</a> | <a href="#14">comehome.cpp</a> | <a href="#15">contact.cpp</a> | <a href="#16">contest.cpp</a> | <a href="#17">cowdance.cpp</a> | <a href="#18">cowids.cpp</a> | <a href="#19">cowjog.cpp</a> | <a href="#20">cowlineup.cpp</a> | <a href="#21">cowrun.cpp</a> | <a href="#22">cpp_template.cpp</a> | <a href="#23">daisy.cpp</a> | <a href="#24">danger.cpp</a> | <a href="#25">delivery.cpp</a> | <a href="#26">diet.cpp</a> | <a href="#27">dijkstra.cpp</a> | <a href="#28">dijkstra2.cpp</a> | <a href="#29">egroup.cpp</a> | <a href="#30">fliptile.cpp</a> | <a href="#31">flow.cpp</a> | <a href="#32">gravity.cpp</a> | <a href="#33">hay4sale.cpp</a> | <a href="#34">heatwv.cpp</a> | <a href="#35">hideseek.cpp</a> | <a href="#36">hopscotch.cpp</a> | <a href="#37">horizon.cpp</a> | <a href="#38">hps.cpp</a> | <a href="#39">hurdles.cpp</a> | <a href="#40">invite.cpp</a> | <a href="#41">irrigation.cpp</a> | <a href="#42">jump.cpp</a> | <a href="#43">knapsack.cpp</a> | <a href="#44">landscape.cpp</a> | <a href="#45">lcs.cpp</a> | <a href="#46">lcstring.cpp</a> | <a href="#47">lis.cpp</a> | <a href="#48">marathon.cpp</a> | <a href="#49">maze1.cpp</a> | <a href="#50">meteor.cpp</a> | <a href="#51">milkprod.cpp</a> | <a href="#52">money.cpp</a> | <a href="#53">moo.cpp</a> | <a href="#54">mst2.cpp</a> | <a href="#55">nocross.cpp</a> | <a href="#56">pachinko2.cpp</a> | <a href="#57">packdel.cpp</a> | <a href="#58">picnic.cpp</a> | <a href="#59">pie1.cpp</a> | <a href="#60">pogocow.cpp</a> | <a href="#61">privc.cpp</a> | <a href="#62">pwalk.cpp</a> | <a href="#63">recording.cpp</a> | <a href="#64">roadblock.cpp</a> | <a href="#65">roads.cpp</a> | <a href="#66">sandcas.cpp</a> | <a href="#67">scales.cpp</a> | <a href="#68">sed.cpp</a> | <a href="#69">sgraze.cpp</a> | <a href="#70">silvlilly.cpp</a> | <a href="#71">snail.cpp</a> | <a href="#72">soda.cpp</a> | <a href="#73">stamps.cpp</a> | <a href="#74">subset.cpp</a> | <a href="#75">tallest.cpp</a> | <a href="#76">tractor.cpp</a> | <a href="#77">waterslides.cpp</a> </div>

# [agrinet.cpp](#0)
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

// declare any functions

int main()
{
    int N;
    int dist[101];
    int path[101][101];
    
    cin >> N;
    for (int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int temp_d;
            cin >> temp_d;
            path[i][j]=temp_d;
        }
    }
    
    int k=1;
    int ans=0;
    
    fill(dist, dist+N+1, 1000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        dist[k]=-1;
        
        for (int j=1; j<=N; j++) {
            if (path[k][j]<dist[j]){
                dist[j]=path[k][j];
            }
        }
        k=-1;
        for (int j=1; j<=N; j++){
            if (dist[j]!=-1 && dist[j]!=1000000000){
                if (k==-1 || dist[j]<dist[k]){
                    k=j;
                }
            }
        }
        ans+=dist[k];
    }
    cout << ans << endl;
}

```

# [auto.cpp](#1)
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

// declare any functions

int main() {
    // declare any local variables
    int N,W;
    vector<pair<string,int> > dic;
    
    // input
    cin >> W >> N;
    string read;
    for(int i=1; i<=W; i++){
        cin >> read;
        dic.push_back(make_pair(read,i));
    }
    sort(dic.begin(),dic.end());
    // main
    int K;
    int times;
    string word;
    for(int i=1; i<=N; i++){
        cin >> K >> word;
        times=0;
        times=lower_bound(dic.begin(),dic.end(),make_pair(word,0))-dic.begin();
        
        times+=K-1;
        
        if(times<W) {
            if(dic[times].first.substr(0,word.length())==word){
                cout<<dic[times].second<<endl;
            } else{
                cout<<"-1"<<endl;
            }
        } else cout<<"-1"<<endl;
    }
    
    // output
    
    return 0;
}

```

# [bds.cpp](#2)
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

# [bullcow.cpp](#3)
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

// declare any functions

int main() {
    // declare any local variables
    int N, K;
    long DP[100001];
    // input
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        DP[i]=0;
    }
    // main
    //    DP[1]=2;
    for(int i=1; i<=N; i++){
        if(i-1 >= 1){
            DP[i] += DP[i-1];
        } else {
            DP[i] += 1;
        }
        if(i-K-1 >= 1){
            DP[i] += DP[i-K-1];
        } else {
            DP[i] += 1;
        }
        DP[i] %= 5000011;
    }
    // output
    cout << DP[N]<<endl;
    return 0;
}

```

# [buyhay.cpp](#4)
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
#define MAXN_N 101

// declare any global variables
int N, H;
int P[MAXN_N], C[MAXN_N];
int DP[60001];
int maxn = 0;
int max_p = 0;
// declare any functions
void initialize(){
    cin >> N >> H;
    for(int i=1; i<=N; i++){
        cin >> P[i] >> C[i];
        max_p = max(max_p, P[i]);
    }
    for(int i=1; i<=H+max_p; i++) DP[i] = 500001;
}
void solve_DP(){
    DP[0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            //            if(j+P[i] <= H){
            DP[j+P[i]] = min(DP[j+P[i]], DP[j]+C[i]);
            //            }
        }
    }
}
int main() {
    
    //code here
    initialize();
    solve_DP();
    // output
    int ans = 500001;
    for(int i=H; i<=H+max_p; i++){
        ans = min(ans, DP[i]);
    }
    cout<<ans<<endl;
    return 0;
}

```

# [cardgame.cpp](#5)
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
#define MAXN 50001
// declare any global variables
int N;
//int Elsie[MAXN];
vector<int> Elsie1, Elsie2, Bessie;
bool deck[(2*MAXN)-1];

struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

// declare any functions
void initialize(){
    cin >> N;
    memset(deck, false, sizeof(deck));
    for(int i=1; i<=N; i++){
        int card; cin >> card;
        if(i<=(N/2)) Elsie1.push_back(card);
        else Elsie2.push_back(card);
        deck[card] = true;
        //        cout<<"deck["<<Elsie[i]<<"] = true"<<endl;
    }
    for(int i=1; i<=2*N; i++){
        if(!deck[i]){
            Bessie.push_back(i);
        }
    }
    sort(Elsie1.begin(), Elsie1.end(), myobject);
    sort(Elsie2.begin(), Elsie2.end(), myobject);
    sort(Bessie.begin(), Bessie.end(), myobject);
}
void solve(){
    int ans = 0;
    for(int i=0; i<Elsie1.size(); i++){
        for(int j=(N/2); j<=(N-1); j++){
            if(Bessie[j]>Elsie1[i] && !deck[Bessie[j]]){
                ans++;
                //                cout<<"used "<<Bessie[j]<<" to defeat "<<Elsie[i]<<endl;
                deck[Bessie[j]] = true;
                break;
            }
        }
    }
    for(int i=0; i<Elsie2.size(); i++){
        for(int j=0; j<N/2; j++){
            if(!deck[Bessie[j]] && Bessie[j]<Elsie2[i]){
                ans++;
                //                cout<<"used "<<Bessie[j]<<" to defeat "<<Elsie[i]<<endl;
                deck[Bessie[j]] = true;
                break;
            }
        }
    }
    cout<<ans<<endl;
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

# [catchcow.cpp](#6)
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

struct p{
    int x, t;
    p(int x, int t) : x(x), t(t) {}
};

int main() {
    
    int N, K;
    cin >> N >> K;
    
    queue<p> qu;
    qu.push(p(N,0));
    map<int, int> visited;
    
    int far_right = 2*K;
    
    while(!qu.empty()){
        
        int i = qu.front().x;
        int t = qu.front().t;
        visited[i] = 1;
        
        //        cout<<i<<" time "<<t<<endl;
        if(i==K){
            cout<<t<<endl;
            break;
        }
        
        far_right = max(far_right, i);
        
        if(i-1>=0 && visited[i-1]==0) qu.push(p(i-1,t+1));
        if(i+1<=100000 and (i+1)<(far_right) && visited[i+1]==0) qu.push(p(i+1,t+1));
        if(i*2<=100000 and (i*2)<(far_right) && visited[i*2]==0) qu.push(p(i*2,t+1));
        qu.pop();
    }
    return 0;
}

```

# [cgiving.cpp](#7)
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
int V, E, S;
vector<Pair> path[50010];
int dist[50010];
bool visited[50010];
// declare any functions
void initialize(){
    cin >> V >> E >> S;
    for(int i=1; i<=E; i++){
        int a,b,d; cin >> a >> b >> d;
        path[a].push_back(Pair(b,d));
        path[b].push_back(Pair(a,d));
    }
}
void spath(int start){
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    
    memset(visited, false, sizeof(bool)*(V+1));
    memset(dist, 0, sizeof(int)*(V+1));
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        
        if(visited[i]) continue;
        visited[i] = true;
        
        for(int x=0; x<path[i].size(); x++){
            int go = path[i][x].neighbor;
            int ndist = dist[i] + path[i][x].weight;
            if((go!=S and dist[go]==0) || ndist < dist[go]){
                dist[go] = ndist;
                pq.push(make_pair(ndist, go));
            }
        }
        
    }
    for(int i=1; i<=V; i++){
        if(i==S) cout<<"0"<<endl;
        else if (!visited[i]) cout<<"-1"<<endl;
        else cout<<dist[i]<<endl;
    }
}

void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    spath(S);
    // output
    print_ans();
    
    //close
    return 0;
}

```

# [cgiving2.cpp](#8)
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
struct p{
    int b,d;
    p(int b, int d) :b(b),d(d) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N, start, E;
    map<int, vector<p> > edge;
    // fstream
    
    // input
    cin >> N >> E >> start;
    for(int i=1; i<=E; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a].push_back(p(b,d));
        edge[b].push_back(p(a,d));
    }
    
    // main
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[start] = 0;
    while(true){
        int in = -1;
        for(int i=1; i<=N; i++){
            if(dist[i] != -1){
                if(!visited[i]&&(in == -1 or dist[i]<dist[in])){
                    in=i;
                }
            }
        }
        if(in==-1) break;
        visited[in] = true;
        for(int i=0; i<edge[in].size(); i++){
            int go = edge[in][i].b;
            int ndist = dist[in]+edge[in][i].d;
            if(dist[go]==-1 || ndist<dist[go]){
                dist[go]=ndist;
            }
        }
    }
    // output
    for(int i=1; i<=N; i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}

```

# [change.cpp](#9)
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
long long V, N, currency[11];
long long dp[1001];
// declare any functions
void initialize(){
    cin >> N >> V;
    for(int i=1; i<=V; i++){
        cin >> currency[i];
    }
    for(int i=1; i<=N; i++) dp[i]=100000000;
}
void solve_dp(){
    dp[0] = 0;
    for(int i=1; i<=V; i++){
        for(int j=0; j<=N; j++){
            if(j+currency[i] <= N) dp[j+currency[i]] = min(dp[j+currency[i]], dp[j]+1);
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    cout<<dp[N]<<endl;
    return 0;
}

```

# [charm.cpp](#10)
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
struct point{
    int t, p;
    point(int t, int p) : t(t),p(p) {}
};

// declare any global variables
long t[3403],p[3403];
long dp[2][12881];
long max0(long a, long b){
    if(a>b) return a;
    return b;
}
int main() {
    // declare any local variables
    int N,C;
    
    // input
    cin >> N >> C;
    for(int i=1; i<=N; i++){
        cin >> t[i] >> p[i];
    }
    // main
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=C; j++){
            if(j-t[i] < 0) dp[1][j] = dp[0][j];
            else dp[1][j] = max0(dp[0][j-t[i]]+p[i],dp[0][j]);
        }
        swap(dp[1],dp[0]);
    }
    // output
    cout<<dp[0][C];
    return 0;
}

```

# [checklist.cpp](#11)
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

// declare any global variables
int H, G, hx[1001], hy[1001], gx[1001], gy[1001];
long long dp[1001][1001][2];
// declare any functions
void initialize(){
    cin >> H >> G;
    for(int i=0; i<H; i++) cin >> hx[i] >> hy[i];
    for(int i=0; i<G; i++) cin >> gx[i] >> gy[i];
    for(int i=0; i<=H; i++){
        for(int j=0; j<=G; j++){
            for(int k=0; k<=1; k++){
                dp[i][j][k] = 100000000000;
            }
        }
    }
}
int square (int x){
    return (x*x);
}
int dist(int x1, int y1, int x2, int y2){
    return square(abs(x2-x1))+square(abs(y2-y1));
}
void solve(){
    
    dp[1][0][0]=0;
    for(int i=0; i<=H; i++){
        for(int j=0; j<=G; j++){
            for(int k=0; k<=1; k++){
                if(k == 0 && i == 0) continue;
                if(k == 1 && j == 0) continue;
                
                int fx, fy;
                if(k==0){
                    fx=hx[i-1]; fy=hy[i-1];
                } else if (k==1){
                    fx=gx[j-1]; fy=gy[j-1];
                }
                if(i<H){
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + dist(hx[i],hy[i],fx,fy));
                }
                if(j<G){
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + dist(gx[j],gy[j],fx,fy));
                }
            }
        }
    }
    
}
void print_ans(){
    cout<<dp[H][G][0]<<endl;
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    return 0;
}

```

# [clumsy.cpp](#12)
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

# [coaster.cpp](#13)
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
struct piece{
    int x, w, f, c;
    piece(int x, int w, int f, int c) : x(x), w(w), f(f), c(c) {}
};
struct waytosort {
    bool operator() (piece i, piece j) {
        if(i.x!=j.x)return (i.x<j.x);
        return i.w < j.w;
    }
} waytosort;

// declare any global variables
int L, N, B;
vector<piece> component;
int dp[1001][1001];
// declare any functions
void initialize(){
    cin >> L >> N >> B;
    for(int i=0; i<N; i++){
        int x, w, f, c; cin >> x >> w >> f >> c;
        component.push_back(piece(x,w,f,c));
    }
    sort(component.begin(), component.end(), waytosort);
    for(int i=0; i<=L; i++){
        for(int j=0; j<=B; j++){
            dp[i][j]=-100000000;
        }
    }
}
void solve(){
    dp[0][0]=0;
    for(int i=0; i<N; i++){
        int start = component[i].x;
        int width = component[i].w;
        int fun = component[i].f;
        int cost = component[i].c;
        //        cout<<start<<" "<<width<<" "<<fun<<" "<<cost<<endl;
        for(int x=0; x<=B; x++){
            if(cost > x) continue;
            //            cout<<"dp["<<start+width<<"]["<<x<<"] = max("<<dp[start+width][x]<<", "<<dp[start][x-cost]+fun<<") = "<< max(dp[start+width][x], dp[start][x-cost]+fun)<<endl;
            dp[start+width][x] = max(dp[start+width][x], dp[start][x-cost]+fun);
        }
    }
}
void print_ans(){
    int ans = 0;
    for(int j=0; j<=B; j++){
        ans = max(ans, dp[L][j]);
    }
    if(ans==0) cout<<"-1";
    else cout<<ans<<endl;
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    return 0;
}

```

# [comehome.cpp](#14)
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
struct p{
    char b;
    int d;
    p(char b, int d) : b(b),d(d) {}
};
// declare any global variables
//vector <p> path[10001];
//map<char, vector<p> > path;
//map<char, map<char, int> > path;
map<char,int> dist;
//int dist[60];
map<char,int> visited;
//bool visited[60];
// declare any functions
int ansd=1000000000; char ansc;
//void spath(){
//    priority_queue<pair<int, char>,vector<pair<int, char> >, greater<pair<int, char> > > pq;
//
////    memset(dist,1000000000,sizeof(int)*(60));
////    memset(visited,false,sizeof(bool)*(60));
//    visited['Z'] = true;
//    pq.push(make_pair(0,'Z'));
//    dist['Z']=0;
//    while(!pq.empty()){
//        char a = pq.top().second;
////        int d = pq.top().first;
//        pq.pop();
//
//        if(isupper(a) && a!='Z'){
//            ansd = dist[a];
//            ansc = a;
//            return;
//        }
//
//        for(map<char,int>::iterator it=path[a].begin(); it!=path[a].end(); ++it){
//            if(it->second==1000000000) continue;
//            char go = it->first;
//            int ndist = dist[a] + it->second;
//            if((dist[go]==0) || ndist < dist[go]){
//                dist[go] = ndist;
////                if(!visited[go]){
////                    cout<<a<<" -> "<<go<<" "<<dist[go]<<" "<<ndist<<endl;
//                    pq.push(make_pair(dist[go], go));
//                    visited[go]=true;
////                }
//            }
//        }
//    }
//}
int change2int(char c){
    if(islower(c)){
        return (c-'a'+1);
    }
    return (c-'A'+27);
}
char change2char(int a){
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return abc[a-27];
}
int min0(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
int main() {
    // declare any local variables
    int P;
    
    // input
    //    int path[60][60];
    map<int, map<int, int> > path;
    cin >> P;
    for(int i=1; i<=52; i++){
        for(int j=1; j<=52; j++){
            path[i][j]=1000000000;
        }
    }
    for(int i=1; i<=P; i++){
        char a,b;
        int d;
        //        int a,b,d;
        cin >> a >> b >> d;
        int ai = change2int(a);
        int bi = change2int(b);
        //        path[a].push_back(p(b,d));
        path[ai][bi]=min0(path[ai][bi],d);
        //        path[a].push_back(p(b,d));
        //        path[b].push_back(p(a,d));
        path[bi][ai]=min0(path[bi][ai],d);
        //        path[b][path[b].size()+1]=p(a,d);
    }
    
    // main
    for(int k=1; k<=52; k++){
        for(int i=1; i<=52; i++){
            for(int j=1; j<=52; j++){
                path[i][j]=min0(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    
    for (int k=27; k<=51; k++){
        if(path[52][k]<ansd){
            ansd=path[52][k];
            ansc=change2char(k);
        }
    }
    //    spath();
    // output
    //    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    //    for(int i=0; i<25; i++){
    ////        cout<<alpha[i]<<" d: "<<dist[alpha[i]]<<endl;
    //        if(dist[alpha[i]]!=0 and (dist[alpha[i]]<ansd || (dist[alpha[i]]==ansd and alpha[i]<ansc))){
    //            ansd=dist[alpha[i]];
    //            ansc=alpha[i];
    //        }
    //    }
    cout<<ansc<<" "<<ansd<<endl;
    return 0;
}

```

# [contact.cpp](#15)
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

# [contest.cpp](#16)
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
struct p{
    int b; bool better;
    p(int b, bool better):b(b),better(better) {}
};
// declare any functions

int main() {
    // declare any local variables
    int N,M;
    map<int, int> times;
    //    int X[4501],Y[4501];
    vector<p> result[101];
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int x,y;
        cin >> x >> y;
        result[x].push_back(p(y,true));
        result[y].push_back(p(x,false));
    }
    
    // input
    int ans=0;
    bool visited[N+1];
    for(int i=1; i<=N; i++){
        
        queue<int> above;
        memset(visited, false,sizeof(bool)*(N+1));
        int mysmallcounter = -2;
        above.push(i);
        while(!above.empty()){
            int j=above.front();
            above.pop();
            visited[j]=true;
            mysmallcounter++;
            
            for(int k=0; k<result[j].size(); k++){
                if(!result[j][k].better && !visited[result[j][k].b]){
                    visited[result[j][k].b] = true;
                    above.push(result[j][k].b);
                }
            }
        }
        
        queue<int> below;
        memset(visited, false,sizeof(bool)*(N+1));
        below.push(i);
        while(!below.empty()){
            int j=below.front();
            below.pop();
            visited[j]=true;
            mysmallcounter++;
            
            for(int k=0; k<result[j].size(); k++){
                if(result[j][k].better && !visited[result[j][k].b]){
                    visited[result[j][k].b] = true;
                    below.push(result[j][k].b);
                }
            }
        }
        if(mysmallcounter==(N-1)){
            ans++;
        }
    }
    // main
    cout<<ans<<endl;
    // output
    
    return 0;
}


```

# [cowdance.cpp](#17)
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
struct p{
    int t,i;
    p(int t, int i) : t(t),i(i) {}
};
// declare any global variables
struct b2s {
    bool operator() (int i,int j) { return (i>j);}
} b2s;

// declare any functions

int main() {
    // declare any local variables
    int N,T_max;
    vector<int> time;
    
    // input
    cin >> N >> T_max;
    for(int i=0; i<N; i++){
        int read;
        cin >> read;
        time.push_back(read);
    }
    
    int min = 0, max=N;
    while(min<max){
        int K = (min+max)/2;
        priority_queue<int, vector<int>, greater<int> > qu;
        int in = -1;
        for(int i=0; i<K; i++){
            in++;
            qu.push(time[in]);
        }
        bool work = false;
        while(!qu.empty()){
            int i=qu.top();
            qu.pop();
            
            if(in==N){
                work=true;
                break;
            }
            in++;
            if(i+time[in]>T_max){
                work=false;
                break;
            }
            qu.push(i+time[in]);
            
        }
        if(work){
            max=K;
        } else{
            min=K+1;
        }
    }
    // main
    cout<<min<<endl;
    // output
    
    return 0;
}

```

# [cowids.cpp](#18)
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
#include <math.h>
using namespace std;

// declare any structures

// declare any global variables
struct point{
    int zero, r;
    point (int zero, int r) : zero(zero), r(r) {}
};
// declare any functions
point intlog(int K, int N) {
    int timestimes = 0;
    int times = 1;
    while(true){
        if(N<=times){
            return point(timestimes, times-N+1);
            break;
        }
        times *= K;
        timestimes++;
    }
}
int main() {
    // declare any local variables
    int N, K;
    
    // input
    cin >> N >> K;
    // main
    if(K==1){
        cout<<"1";
        for(int i=2; i<=N; i++){
            cout<<"0";
        }
        cout<<endl;
        return 0;
    }
    point temp = intlog(K,N);
    
    int num_of_0 = temp.zero;
    //    cout<<num_of_0<<" "<<remainder<<" ";
    
    int sizeofans = num_of_0+K;
    int DP[5010][K+10];
    for(int i=0; i<=sizeofans+5; i++){
        for(int j=0; j<=K; j++){
            DP[i][j] = 0;
        }
    }
    DP[0][0] = 1;
    for(int i=1; i<=5000; i++){
        for(int j=0; j<=K; j++){
            if(j-1 < 0) DP[i][j] = DP[i-1][j];
            else DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
        }
    }
    int current_K = K;
    int current_N = N;
    int N_i = 6000;
    int printed = 0;
    vector<char> ans;
    while(true){
        for(int i=1; i<=5000; i++){
            
            if(DP[i][current_K]>=current_N){
                if(N_i==6000){
                    sizeofans = i;
                } else {
                    for(int j=i+1; j<N_i; j++){
                        cout<<"0";
                        printed++;
                    }
                }
                N_i = i;
                cout<<"1";
                printed++;
                current_N -= DP[i-1][current_K];
                break;
            }
        }
        current_K--;
        if(current_K==0){
            for(int i=printed+1; i<=sizeofans; i++){
                cout<<"0";
            }
            break;
        }
    }
    // output
    return 0;
}


```

# [cowjog.cpp](#19)
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
#define ll long long
struct node{
    ll start, speed, end_position;
    node(ll start, ll speed, ll end_position) : start(start), speed(speed), end_position(end_position) {}
};

// declare any global variables
ll N, T;
vector <node> cow;
int position[100001];
// declare any functions
void initialize(){
    cin >> N >> T;
    ll start, speed, end_position;
    for(int i=0; i<N; i++){
        cin >> start >> speed;
        end_position = start + (speed*T);
        cow.push_back(node(start, speed, end_position));
    }
    for(int i=0; i<N; i++){
        //        cout<<cow[i].start<<" "<<cow[i].speed<<" "<<cow[i].end_position<<endl;
    }
}
void solve(){
    //    position[1] = cow[0].end_position;
    //    cout<<"solving ... "<<endl;
    long long groups = N;
    for(long long i=N-1; i>0; i--){
        //        cout<<cow[i].end_position<<" "<<cow[i-1].end_position<<" "<<groups<<endl;
        if(cow[i].end_position <= cow[i-1].end_position){
            //            cout<<"cow["<<i-1<<"].end_position = "<<"cow["<<i<<"].end_position"<<endl;
            //            cout<<cow[i-1].end_position<<" = "<<cow[i].end_position<<endl;
            cow[i-1].end_position = cow[i].end_position;
            //            groups--;
        }
        //        cout<<"groups: "<<groups<<endl;;
    }
    for(int i=1; i<N; i++){
        if(cow[i].end_position == cow[i-1].end_position) groups--;
    }
    cout<<groups<<endl;
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

# [cowlineup.cpp](#20)
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
struct p{
    int t,i;
    p(int t, int i) : t(t),i(i) {}
};
// declare any global variables
struct b2s {
    bool operator() (int i,int j) { return (i>j);}
} b2s;

// declare any functions

int main() {
    // declare any local variables
    int N,T_max;
    vector<int> time;
    
    // input
    cin >> N >> T_max;
    for(int i=0; i<N; i++){
        int read;
        cin >> read;
        time.push_back(read);
    }
    
    int min = 0, max=N;
    while(min<max){
        int K = (min+max)/2;
        priority_queue<int, vector<int>, greater<int> > qu;
        int in = -1;
        for(int i=0; i<K; i++){
            in++;
            qu.push(time[in]);
        }
        bool work = false;
        while(!qu.empty()){
            int i=qu.top();
            qu.pop();
            
            if(in==N){
                work=true;
                break;
            }
            in++;
            if(i+time[in]>T_max){
                work=false;
                break;
            }
            qu.push(i+time[in]);
            
        }
        if(work){
            max=K;
        } else{
            min=K+1;
        }
    }
    // main
    cout<<min<<endl;
    // output
    
    return 0;
}

```

# [cowrun.cpp](#21)
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

// declare any global variables
int N, M;
int dist[10001];
int dp[2][501][2];
//map<int, map<int, map<int, int> > > dp;
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> dist[i];
}
void solve(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            for(int k=0; k<2; k++){
                if(k==0){
                    if(i-1 >= 1 and j+1 <= M){
                        dp[1][j][0] = max(dp[0][j+1][0], dp[0][j+1][1]);
                    }
                    if(j==0){
                        dp[1][j][0] = max(dp[1][j][0],dp[0][j][0]);
                    }
                } else if (k==1){
                    if(i-1 >=1 and j-1 >= 0){
                        dp[1][j][1] = dp[0][j-1][1]+dist[i];
                    }
                    if(j==1){
                        dp[1][j][1] = max(dp[1][j][1], dp[0][j-1][0]+dist[i]);
                    }
                }
            }
        }
        //        swap(dp[1],dp[0]);
        for(int j=0; j<=M; j++){
            for(int k=0; k<2; k++){
                dp[0][j][k]=dp[1][j][k];
                dp[1][j][k]=0;
            }
        }
    }
}
void print_ans(){
    cout<< dp[0][0][0];
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

# [cpp_template.cpp](#22)
```cpp
//the following library inclusions are from C++ bits/stdc++.h
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

//declare defines, structures

//declare global variables (global variables use up less space than local variables)

//declare functions
void initialize(){
    
}
void solve(){
    
}
void print_ans(){
    
}
int main(/* no variables here, it's main */) {
//  declare local variables
    
//  fstream (remember to change file name)
    std::ifstream fin ("CHANGE.in");
    std::ofstream fout ("CHANGE.out");
    
//  input
    initialize();
//  fin.close();
        
//  main
    solve();
    
//  output
    print_ans();
//  fout.close();
    
//  close main
    return 0;
}

```

# [daisy.cpp](#23)
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

// declare any functions

int main() {
    // declare any local variables
    int N, M;
    vector <int> path[251];
    bool visited[251];
    
    // input
    cin >> N >> M;
    memset(visited, false, sizeof(bool)*(N+1));
    for(int i=1; i<=M; i++){
        int a,b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    // main
    queue<int> bfs;
    bfs.push(1);
    visited[1] = true;
    
    while(!bfs.empty()){
        int i=bfs.front();
        bfs.pop();
        
        for(int j=0; j<path[i].size(); j++){
            if(!visited[path[i][j]]){
                bfs.push(path[i][j]);
                //                cout<<i<<" -> "<<path[i][j]<<endl;
                visited[path[i][j]]=true;
            }
        }
    }
    // output
    bool zero = true;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            zero = false;
            cout<<i<<endl;
        }
    }
    if(zero) cout<<"0"<<endl;
    return 0;
}

```

# [danger.cpp](#24)
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

// declare any functions

int main() {
    // declare any local variables
    int N,M;
    int fm[101][101];
    vector<int> path;
    // fstream
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            fm[i][j]=1000000000;
        }
    }
    for(int i=1; i<=M; i++){
        int a;
        cin >> a;
        path.push_back(a);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int d;
            cin >> d;
            fm[i][j]=d;
        }
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                fm[i][j]=min(fm[i][j],fm[i][k]+fm[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<(M-1); i++){
        ans += fm[path[i]][path[i+1]];
    }
    // main
    cout<<ans<<endl;
    // output
    
    return 0;
}

```

# [delivery.cpp](#25)
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
#include <vector>
#include <set>

using namespace std;

//declare any structures
#define MAXN 1000001
#define Pair pair<int, int>
struct node {
    int x, y;
    node(int x, int y) : x(x), y(y) {}
} ;

//declare any global variables
int N;
int x[100], y[100];
int converter[100];
set<pair<int, int> > points;
vector<node> nodes;
vector<int> directPath[500];

//declare any functions
int distance(int a, int b) { return abs(nodes[a].x-nodes[b].x)+abs(nodes[a].y-nodes[b].y); }
bool isNotBlockedByFarm(int i, int j){ for(int k=0; k<N; k++){ if(x[k]==i and y[k]==j){ return false; } } return true; }
bool blocked_by_node(int x1, int y1, int x2, int y2, int x3, int y3){ return (x2==x3 && (x1 == x2 && y1 > min(y2, y3) && y1 < max(y2, y3))) || (y1==y2&&(y1 == y2 && x1 > min(x2, x3) && x1 < max(x2, x3))); }
bool isValid(int i, int j) { return (i >= 1 and i <= MAXN-1 and j >= 1 and j <= MAXN-1); }
bool isDestination(int i, int j, Pair dest){ return (i==dest.first && j==dest.second); }

bool route_possible(int a, int b){
    bool return1, return2;
    if(nodes[a].x == nodes[b].x or nodes[a].y == nodes[b].y or isNotBlockedByFarm(nodes[a].x, nodes[b].y)) return1 = true;
    else return1 = false;
    for(int i = 0; i < N; i++){
        if(blocked_by_node(x[i], y[i], nodes[a].x, nodes[a].y, nodes[a].x, nodes[b].y) || blocked_by_node(x[i], y[i], nodes[a].x, nodes[b].y, nodes[b].x, nodes[b].y)){
            return1 = false;
            break;
        }
    }
    if(nodes[a].x == nodes[b].x or nodes[a].y == nodes[b].y or isNotBlockedByFarm(nodes[b].x, nodes[a].y)){
        return2 = true;
    } else return2 = false;
    
    for(int i = 0; i < N; i++){
        if(blocked_by_node(x[i], y[i], nodes[a].x, nodes[a].y, nodes[b].x, nodes[a].y) || blocked_by_node(x[i], y[i], nodes[b].x, nodes[a].y, nodes[b].x, nodes[b].y)){
            return2 = false;
            break;
        }
    }
    
    return (return1 || return2);
}

bool visited[500];
int dist[500];
int solve(int a, int b) {
    fill(dist, dist+nodes.size(), 1000000000);
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < N; i++) if(converter[i] != a && converter[i] != b) visited[converter[i]] = true;
    
    dist[a] = 0;
    for(int i = 0; i < nodes.size(); i++){
        int next = 0;
        for(int j = 0; j < nodes.size(); j++){
            if(!visited[j] && (dist[j] < dist[next] || visited[next])) next = j;
        }
        if(visited[next] || dist[next] == 1000000000) return -1;
        
        if(next == b) return dist[b];
        
        visited[next] = true;
        for(int j = 0; j < directPath[next].size(); j++){
            if(!visited[directPath[next][j]]) dist[directPath[next][j]] = min(dist[directPath[next][j]], dist[next] + distance(next, directPath[next][j]));
        }
    }
    return -1;
}
void initialize(){
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        points.insert(make_pair(x[i], y[i]));
    }
    int X[] = {0,1,0,-1,0};
    int Y[] = {0,0,1,0,-1};
    
    for(int i = 0; i < N; i++){
        for(int j=0; j<=4; j++){
            if(X[j] == 0 && Y[j] == 0) {
                nodes.push_back(node(x[i], y[i]));
                converter[i] = nodes.size()-1;
            }
            else if((X[j]==0 or Y[j]==0) && isNotBlockedByFarm(x[i]+X[j],y[i]+Y[j])) nodes.push_back(node(x[i]+X[j],y[i]+Y[j]));
        }
    }
}
void solve(){
    for(int i = 0; i < nodes.size(); i++){
        for(int j = i+1; j<nodes.size(); j++){
            if(route_possible(i, j)){
                directPath[i].push_back(j);
                directPath[j].push_back(i);
            }
        }
    }
}
int solve4ans(int i){
    if(i==N-1) return 0;
    else return i+1;
}
int print_ans(){
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int current_minutes = solve(converter[i], converter[solve4ans(i)]);
        //        cout<<i<<" m: "<<current_minutes<<endl;
        if(current_minutes == -1) {
            return -1;
            break;
        } else ans += current_minutes;
    }
    return ans;
}
int main(){
    //input
    initialize();
    //main
    solve();
    //fout
    cout<< print_ans() <<endl;
    
    //close
    return 0;
}

```

# [diet.cpp](#26)
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables
int N, H, W[501];
bool DP[501][45001];
// declare any functions
int main() {
    // declare any local variables
    
    // fstream
    
    // input
    cin >> H >> N;
    for(int i=1; i<=N; i++) cin >> W[i];
    
    
    // main
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            DP[i][j]=false;
        }
    }
    DP[0][0]=true;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            if(j-W[i]<0) DP[i][j] = (DP[i][j] || DP[i-1][j]);
            else DP[i][j] = (DP[i-1][j-W[i]] || DP[i][j] || DP[i-1][j]);
        }
    }
    // output
    //    cout<<DP[N][H];
    for(int i=H; i>=0; i--){
        if(DP[N][i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

```

# [dijkstra.cpp](#27)
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
struct p{
    int b,d;
    p(int b, int d) :b(b),d(d) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N, start, E;
    map<int, vector<p> > edge;
    // fstream
    
    // input
    cin >> N >> E >> start;
    for(int i=1; i<=E; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a].push_back(p(b,d));
        edge[b].push_back(p(a,d));
    }
    
    // main
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[start] = 0;
    while(true){
        int in = -1;
        for(int i=1; i<=N; i++){
            if(dist[i] != -1){
                if(!visited[i]&&(in == -1 or dist[i]<dist[in])){
                    in=i;
                }
            }
        }
        if(in==-1) break;
        visited[in] = true;
        for(int i=0; i<edge[in].size(); i++){
            int go = edge[in][i].b;
            int ndist = dist[in]+edge[in][i].d;
            if(dist[go]==-1 || ndist<dist[go]){
                dist[go]=ndist;
            }
        }
    }
    // output
    for(int i=1; i<=N; i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}

```

# [dijkstra2.cpp](#28)
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
int V, E, S;
vector<Pair> path[50010];
int dist[50010];
bool visited[50010];
// declare any functions
void initialize(){
    cin >> V >> E >> S;
    for(int i=1; i<=E; i++){
        int a,b,d; cin >> a >> b >> d;
        path[a].push_back(Pair(b,d));
        path[b].push_back(Pair(a,d));
    }
}
void spath(int start){
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    
    memset(visited, false, sizeof(bool)*(V+1));
    memset(dist, 0, sizeof(int)*(V+1));
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int i = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(visited[i]) continue;
        visited[i] = true;
        
        for(int x=0; x<path[i].size(); x++){
            int go = path[i][x].neighbor;
            int ndist = dist[i] + path[i][x].weight;
            if((go!=S and dist[go]==0) || ndist < dist[go]){
                dist[go] = ndist;
                pq.push(make_pair(ndist, go));
            }
        }
        
    }
    for(int i=1; i<=V; i++){
        if(i==S) cout<<"0"<<endl;
        else if (!visited[i]) cout<<"-1"<<endl;
        else cout<<dist[i]<<endl;
    }
}

void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    spath(S);
    // output
    print_ans();
    
    //close
    return 0;
}

```

# [egroup.cpp](#29)
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

// declare any global variables
int N;
int cards[30001], ncards[30001];
int dp[30001][4], dp1[30001][4];
// declare any functions
void initialize(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> cards[i];
    }
    
}
void solve(){
    for(int j=1; j<=3; j++){
        for(int i=1; i<=N; i++){
            if(j==1) dp[i][1] = dp[i-1][1] + (cards[i]!=1);
            else if (j==2) dp[i][2]=min(dp[i-1][1], dp[i-1][2])+(cards[i]!=2);
            else if (j==3) dp[i][3]=min(dp[i-1][3], min(dp[i-1][1], dp[i-1][2]))+(cards[i]!=3);
            //            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
    
    for(int j=3; j>=1; j--){
        for(int i=1; i<=N; i++){
            if(j==1) dp1[i][1] = min(dp1[i-1][3], min(dp1[i-1][1], dp1[i-1][2])) + (cards[i]!=1);
            else if (j==2) dp1[i][2]=min(dp1[i-1][3], dp1[i-1][2])+(cards[i]!=2);
            else if (j==3) dp1[i][3]=dp1[i-1][3]+(cards[i]!=3);
            //            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp1[i][j]<<endl;
        }
    }
}
void print_ans(){
    cout<<min(min(dp[N][1], min(dp[N][3], dp[N][2])),min(dp1[N][1], min(dp1[N][3], dp1[N][2])));
}
int main() {
    
    // fstream
    
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

# [fliptile.cpp](#30)
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
int N, M;
int grid[16][16];
bool flipped[16][16];
int X[] = {0,1,0,-1,0};
int Y[] = {0,0,1,0,-1};

// declare any functions

//void non_recurse(int i){
//
//
//}
int least_flip = 300;
bool flipped_ans[16][16];
bool compair(bool a[16][16],bool b[16][16]){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!b[i][j] && a[i][j]){
                return false;
            }
            if(!a[i][j] && b[i][j]){
                return true;
            }
        }
    }
    return false;
}
void flip(int i, int j){
    flipped[i][j]=true;
    for(int k=0; k<5; k++){
        int x = i+X[k];
        int y = j+Y[k];
        if(x>=1 && x<=N && y>=1 && y<=M){
            grid[x][y]=1-grid[x][y];
        }
    }
}
void dfs(int z){
    //    cout<<"j: "<<z<<" grid: "<<grid[1][1]<<" "<<grid[1][2]<<" "<<grid[1][3]<<" "<<grid[1][4]<<" "<<grid[1][5]<<endl;
    //    cout<<endl;
    if(z>M){
        int oldgrid[16][16];
        bool oldflip[16][16];
        //        for(int i=1; i<=N; i++) {
        //            for(int j=1; j<=M; j++) {
        //                cout<<grid[i][j]<<" ";
        //            }
        //            cout<<endl;
        //        }
        //        cout<<"causing"<<endl;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                oldgrid[i][j]=grid[i][j];
                oldflip[i][j]=flipped[i][j];
            }
        }
        for(int i=2; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(grid[i-1][j]==1){
                    flip(i,j);
                }
            }
        }
        bool impossible1 = false;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(grid[i][j]==1){
                    impossible1=true;
                    //                    cout<<"failed on "<<i<<" "<<j<<endl;
                    //                    break;
                }
            }
            //            if(impossible1) break;
        }
        if(!impossible1){
            int k=0;
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    //                    cout<<flipped[i][j]<<" ";
                    if(flipped[i][j]) k++;
                }
                //                cout<<endl;
            }
            //            cout<<endl;
            if(k<least_flip || (k==least_flip && compair(flipped,flipped_ans))){
                least_flip=k;
                for(int i=1; i<=N; i++) {
                    for(int j=1; j<=M; j++) {
                        flipped_ans[i][j]=flipped[i][j];
                    }
                }
            }
        }
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                grid[i][j]=oldgrid[i][j];
                flipped[i][j]=oldflip[i][j];
            }
        }
        return;
    }
    // w/out flip
    dfs(z+1);
    flip(1,z);
    // w/ flip
    dfs(z+1);
    flipped[1][z] = false;
    for(int k=0; k<5; k++){
        int x = 1+X[k];
        int y = z+Y[k];
        if(x>=1 && x<=N && y>=1 && y<=M){
            grid[x][y]=1-grid[x][y];
        }
    }
}
int main() {
    // declare any local variables
    // fstream
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            int tile_color;
            cin >> tile_color;
            
            grid[i][j]=tile_color;
            flipped[i][j]=false;
            flipped_ans[i][j]=false;
        }
    }
    // input
    dfs(1);
    
    // main
    if(least_flip==300) cout<<"IMPOSSIBLE"<<endl;
    else {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                cout<<flipped_ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // output
    
    return 0;
}

```

# [flow.cpp](#31)
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

// declare any functions
int convert_to_int(char ch){
    if(islower(ch)) return (ch-'a'+1);
    else return (ch-'A'+27);
}
int main() {
    // declare any local variables
    int N;
    int edge[60][60];
    //    int path[60];
    vector<int> path[60];
    // initialize
    for(int i=1; i<=52; i++){
        for(int j=1; j<=52; j++) edge[i][j] = 0;
    }
    cin >> N;
    for(int i=1; i<=N; i++){
        char read_a,read_b; int read_cap;
        cin >> read_a >> read_b >> read_cap;
        int int_a = convert_to_int(read_a);
        int int_b = convert_to_int(read_b);
        edge[int_a][int_b] += read_cap;
        path[int_b].push_back(int_a);
    }
    //  main
    //    deletion:
    for(int k=1; k<=51; k++){
        for(int i=1; i<=51; i++){
            int counter = 0;
            for(int j=1; j<=52; j++){
                if(edge[i][j]!=0) counter++;
            }
            if(counter==0 && path[i].size()>=0){
                for(int x=0; x<path[i].size(); x++){
                    edge[path[i][x]][i]=0;
                }
            }
        }
    }
    //  merge
    for(int x=1; x<=52; x++){
        for(int i=1; i<=52; i++){
            int back_counter = 0;
            int p = 0;
            for(int j=1; j<=52; j++){
                if(edge[i][j]!=0){
                    p = j;
                    back_counter++;
                }
            }
            if(back_counter == 1){
                int front_counter = 0;
                int c = 0;
                for(int j=1; j<=52; j++){
                    if(edge[j][i]!=0){
                        c = j;
                        front_counter++;
                    }
                }
                if (front_counter == 1){
                    edge[c][p] += min(edge[c][i],edge[i][p]);
                    edge[c][i]=edge[i][p]=0;
                }
            }
        }
    }
    // output
    cout<<edge[27][52]<<endl;
    return 0;
}

```

# [gravity.cpp](#32)
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
struct p{
    int x,y,flips,d;
    p(int x, int y, int flips, int d) : x(x), y(y), flips(flips),d(d) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N, M;
    int matrix[501][501];
    int visited[501][501],visited1[501][501];


    // input
    int cx=0,cy=0,dx=0,dy=0;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string read;
        cin >> read;
        for(int j=1; j<=M; j++){
            visited[i][j] = visited1[i][j] = 0;
            if(read[j-1]=='#') matrix[i][j] = 1;
            else if (read[j-1]=='.') matrix[i][j] = 0;
            else if (read[j-1]=='D'){
                dx = i; dy = j;
                matrix[i][j] = 0;
            } else if (read[j-1]=='C'){
                cx = i; cy = j;
                matrix[i][j] = 0;
            }

        }
    }


    // bfs
    deque <p> myde;
    int ans = -1;
    myde.push_front(p(cx,cy,0,0));

    while(!myde.empty())
    {
        int i=myde.front().x;
        int j=myde.front().y;
        int f=myde.front().flips;
        int d=myde.front().d;
        myde.pop_front();
        //        cout<<i<<" "<<j<<" "<<f<<" "<<d<<endl;

        //        visited[i][j]=1;
        if(i==dx and j==dy){
            ans = f;
            break;
        }

        if(d==1){
            visited1[i][j]=1;
            if(i-1 < 1) continue;
            else if(i-1 >= 1 and matrix[i-1][j]==0 and visited1[i-1][j]==0){
                myde.push_front(p(i-1,j,f,d));
            } else if (true){
                if ((i-1)>=1){
                    if(((j+1)<=M and matrix[i-1][j]==1 and matrix[i][j+1]==0 and visited1[i][j+1]==0)){
                        //                    if(((j+1)<=M and matrix[i][j+1]==0 and visited1[i][j+1]==0)){
                        myde.push_front(p(i,j+1,f,d));
                    }
                    if((j-1)>=1 and matrix[i-1][j]==1 and matrix[i][j-1]==0 and visited1[i][j-1]==0){
                        //                    if((j-1)>=1 and matrix[i][j-1]==0 and visited1[i][j-1]==0){
                        myde.push_front(p(i,j-1,f,d));
                    }
                }
                if((i+1)<=N and matrix[i+1][j]==0 and visited[i+1][j]==0){
                    myde.push_back(p(i+1,j,f+1,0));
                }
            }
        } else if (d==0){
            visited[i][j]=1;
            if(i+1 > N) continue;
            else if(i+1 <= N and matrix[i+1][j]==0 and visited[i+1][j]==0){
                myde.push_front(p(i+1,j,f,d));
            } else if (true){
                if ((i+1)<=N){
                    if(((j+1)<=M and matrix[i+1][j]==1 and matrix[i][j+1]==0 and visited[i][j+1]==0)){
                        //                    if(((j+1)<=M and matrix[i][j+1]==0 and visited[i][j+1]==0)){
                        myde.push_front(p(i,j+1,f,d));
                    }
                    if((j-1)>=1 and matrix[i+1][j]==1 and matrix[i][j-1]==0 and visited[i][j-1]==0){
                        //                    if((j-1)>=1 and matrix[i][j-1]==0 and visited[i][j-1]==0){
                        myde.push_front(p(i,j-1,f,d));
                    }
                }
                if((i-1)>=1 and matrix[i-1][j]==0 and visited1[i-1][j]==0){
                    myde.push_back(p(i-1,j,f+1,1));
                }

            }
        }
    }
    cout<<ans<<endl;
    // output
    return 0;
}

```

# [hay4sale.cpp](#33)
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
int C, H;
int V[5001]; bool DP[2][50001];
// declare any functions
void initialize(){
    cin >> C >> H;
    for(int i=1; i<=H; i++) cin >> V[i];
    for(int i=0; i<=C; i++) DP[0][i] = DP[1][i] = false;
}
void solve_DP(){
    DP[0][0] = true;
    for(int i=1; i<=H; i++){
        for(int j=0; j<=C; j++){
            if(j-V[i]<0) DP[1][j] = (DP[1][j] || DP[0][j]);
            else DP[1][j] = (DP[0][j-V[i]] || DP[1][j] || DP[0][j]);
        }
        for(int j=0; j<=C; j++){
            DP[0][j] = DP[1][j];
            DP[1][j] = false;
        }
    }
}
void cout_ans(){
    for(int i=C; i>=0; i--){
        if(DP[0][i]){
            cout<<i<<endl;
            break;
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_DP();
    cout_ans();
    
    return 0;
}

```

# [heatwv.cpp](#34)
```cpp

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures
typedef pair<int, int> pi;
// declare any global variables
map<int, map<int, int> > edge;
//int edge[2501][2501];
//vector<int> path[2500];
map<int, vector<int> >path;
int N, C; int startt, endt;

// declare any functions

int spath(){
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    bool visited[N+1];
    memset(visited, false, sizeof(bool)*(N+1));
    int dist[N+1];
    memset(dist, -1, sizeof(int)*(N+1));
    
    pq.push(make_pair(0,startt));
    dist[startt]=0;
    while(!pq.empty()){
        int i = pq.top().second;
        //        cout<<"popping "<<i<<endl;
        pq.pop();
        //        int i = -1;
        //        for(int j=1; j<=N; j++){
        //            if(dist[j] != -1 && !visited[j]){
        //                if((i == -1 or dist[j]<dist[i])){
        //                    i=j;
        //                }
        //            }
        //            cout<<"dist["<<j<<"] = "<<dist[j]<<endl;
        //        }
        //        cout<<endl;
        //        if(i==-1) break;
        visited[i] = true;
        
        //        if(dist[endt]!=0 and dist[i] > dist[endt]){
        //            pq.pop();
        //            continue;
        //        }
        for(int x=0; x<path[i].size(); x++){
            int go = path[i][x];
            int ndist = dist[i] + edge[i][go];
            //            cout<<ndist<<" = "<<dist[i]<<" + "<<edge[i][go]<<endl;
            if(dist[go]==-1 || ndist < dist[go]){
                dist[go] = ndist;
                //                cout<<"dist["<<go<<"] = "<<dist[go]<<endl;
                if(!visited[go])pq.push(make_pair(dist[go],go));
            }
        }
    }
    return dist[endt];
}
int main() {
    ifstream fin ("read.in");
    // declare any local variables
    
    // fstream
    cin >> N >> C >> startt >> endt;
    for(int i=1; i<=C; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    // input
    
    // main
    
    // output
    cout<<spath()<<endl;
    return 0;
}

```

# [hideseek.cpp](#35)
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

// declare any global variables
int N; int M;
vector<int> path[20001]; int read_f, read_g;
bool visited[20001];
int dist[20001];
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> read_f >> read_g;
        path[read_f].push_back(read_g);
        path[read_g].push_back(read_f);
    }
    for(int i=1; i<=N; i++){
        visited[i] = false;
        dist[i] = N+1;
    }
}
void solve(){
    queue<int> barn; barn.push(1);
    dist[1] = 0; visited[1] = true;
    
    while(!barn.empty()){
        int i = barn.front();
        barn.pop();
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j]; int ndist = dist[i]+1;
            if(ndist < dist[x]){
                dist[x] = ndist;
                if(!visited[x]){
                    visited[x] = true;
                    barn.push(x);
                }
            }
        }
    }
}
void print_ans(){
    int max_path = 0; int min_barn; int max_barns;
    max_barns = -1; min_barn = -1;
    for(int i=1; i<=N; i++){
        if(dist[i] != (N+1)){
            if(dist[i] > max_path){
                max_path = dist[i];
                min_barn = i;
                max_barns = 1;
            } else if (dist[i] == max_path){
                max_barns++;
            }
        }
    }
    cout<<min_barn<<" "<<max_path<<" "<<max_barns<<endl;
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

# [hopscotch.cpp](#36)
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

// declare any functions

int main() {
    // declare any local variables
    int N, M, K;
    int matrix[101][101];
    int DP[101][101];
    
    // input
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> matrix[i][j];
            DP[i][j] = 0;
        }
    }
    // main
    DP[1][1] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int x=i+1; x<=N; x++){
                for(int y=j+1; y<=M; y++){
                    if(matrix[i][j]!=matrix[x][y]){
                        DP[x][y] += DP[i][j];
                        DP[x][y] %= 1000000007;
                    }
                }
            }
        }
    }
    // output
    cout<<DP[N][M];
    
    return 0;
}

```

# [horizon.cpp](#37)
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

# [hps.cpp](#38)
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

// declare any global variables
int N, K;
int move1[100001];
int dp[100001][21][4];
// declare any functions
bool win(int a, int b){
    if(a==2 and b==1) return true;
    if(a==3 and b==2) return true;
    if(a==1 and b==3) return true;
    return false;
}
void initialize(){
    cin >> N >> K;
    char read_move;
    for(int i=1; i<=N; i++){
        cin >> read_move;
        if(read_move=='H') move1[i] = 3;
        else if (read_move=='S') move1[i] = 2;
        else if (read_move=='P') move1[i] = 1;
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=K; j++){
            for(int k=1; k<=3; k++){
                dp[i][j][k] = -1*(N+1);
            }
        }
    }
}
void solve(){
    dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=K; j++){
            for(int m=1; m<=3; m++){
                if(win(m, move1[i+1])){
                    if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]+1);
                } else {
                    if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]);
                }
                for(int n=1; n<=3; n++){
                    if(n==m) continue;
                    if(win(n, move1[i+1])){
                        if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]+1);
                    } else {
                        if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]);
                    }
                }
            }
        }
    }
}
void print_ans(){
    cout<<max(dp[N][0][3],max(dp[N][0][1],dp[N][0][2]));
}
int main() {
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    return 0;
}

```

# [hurdles.cpp](#39)
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
struct p{
    int b,d;
    p(int b, int d) : b(b),d(d) {}
};
// declare any global variables

// declare any functions


int main() {
    // declare any local variables
    int N,M,T;
    int path[301][301];
    // input
    
    cin >> N >> M >> T;
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            path[k][i]=1000000001;
        }
    }
    for(int i=1; i<=M; i++){
        int a,b,d;
        cin >> a >> b >> d;
        path[a][b]=d;
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                path[i][j]=min(path[i][j],max(path[i][k],path[k][j]));
            }
        }
    }
    for(int i=1; i<=T; i++){
        int f,g;
        cin >> f >> g;
        if(path[f][g]==1000000001){
            cout<<"-1"<<endl;
        }
        else cout<<path[f][g]<<endl;
    }
    // main
    
    // output
    
    return 0;
}

```

# [invite.cpp](#40)
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
#include <set>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N,G;
    map<int, vector<int> > group;
    map<int, set<int> >party;
    //    vector<int> group[600],party[600];
    //    int group[310][310],party[310][310];
    bool visited[1000001];
    
    // input
    cin >> N >> G;
    
    for(int i=1; i<=G; i++){
        int size1;
        cin >> size1;
        for(int j=1; j<=size1; j++){
            int id;
            cin >> id;
            group[id].push_back(i);
            //            group[id][count]=i;
            party[i].insert(id);
            //            party[i][count]=id;
            visited[j] = false;
            
        }
    }
    // main
    queue <int> qu;
    int counter=0;
    visited[1]=true;
    qu.push(1);
    while(!qu.empty()){
        int i=qu.front();
        qu.pop();
        
        counter++;
        for(int j=0; j<group[i].size(); j++){
            int g=group[i][j];
            
            
            party[g].erase(i);
            
            if(party[g].size()==1){
                set<int>::iterator it=party[g].begin();
                int in=*it;
                if(!visited[in]){
                    visited[in]=true;
                    qu.push(in);
                }
            }
        }
    }
    
    // output
    cout<<counter<<endl;
    return 0;
}

```

# [irrigation.cpp](#41)
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
struct p{
    int x, y;
};
// declare any functions
int square(int x){
    return x*x;
}
int main()
{
    int N; int least_C;
    p field[2001];
    int dist[2001];
    
    cin >> N >> least_C;
    for (int i=1; i<=N; i++){
        cin >> field[i].x >> field[i].y;
    }
    
    int k=1;
    int ans=0;
    
    fill(dist, dist+N+1, 1000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        dist[k]=-1;
        
        for (int j=1; j<=N; j++) {
            int current_dist = square(field[k].x-field[j].x)+square(field[k].y-field[j].y);
            if (current_dist >= least_C && current_dist<dist[j]){
                dist[j]=current_dist;
            }
        }
        k=-1;
        for (int j=1; j<=N; j++){
            if (dist[j]!=-1 && dist[j]!=1000000000){
                if (k==-1 || dist[j]<dist[k]){
                    k=j;
                }
            }
        }
        if(k==-1){
            ans=-1;
            break;
        }
        ans+=dist[k];
    }
    cout << ans << endl;
}

```

# [jump.cpp](#42)
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
struct myclass {
    bool operator() (int i, int j) { return (i<j);}
} waytosort;

// declare any global variables
int L, N, M;
vector<int> rocks;
bool mark[50001];
// declare any functions
void initialize(){
    cin >> L >> N >> M;
    memset(mark, false, sizeof(mark));
    for(int i=0; i<N; i++){
        int read_dist;
        cin >> read_dist;
        rocks.push_back(read_dist);
    }
    rocks.push_back(L);
    sort(rocks.begin(), rocks.end(), waytosort);
}
void solve(){
    int min = 0;
    int max = 1000000000;
    while(min<max && min!=max){
        int mid = (min+max)/2;
        int safe = 0;
        int left = M;
        int work = true;
        for(int i=0; i<=N; i++){
            if(rocks[i]-safe >= mid){
                safe = rocks[i];
            } else {
                left--;
                if(left < 0){
                    work = false;
                    break;
                }
            }
        }
        if(work){
            if(min+1 == max){
                min = mid;
                break;
            }
            min = mid;
            //            cout<<mid<<" worked "<<min<<" "<<max<<endl;
        } else {
            max = mid;
            //            cout<<mid<<" no worked "<<min<<" "<<max<<endl;
        }
    }
    cout<<min<<endl;
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

# [knapsack.cpp](#43)
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
struct point{
    int t, p;
    point(int t, int p) : t(t),p(p) {}
};

// declare any global variables
long t[1001],p[1001];
long dp[1001][5001];
// declare any functions
long max0(long a, long b){
    if(a>b) return a;
    return b;
}
int main() {
    // declare any local variables
    int N,C;
    
    // input
    cin >> N >> C;
    for(int i=1; i<=N; i++){
        cin >> t[i] >> p[i];
    }
    // main
    
    //    map<long, map<long, long> > dp;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=C; j++){
            dp[i][j]=0;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=C; j++){
            if(j-t[i] < 0) dp[i][j] = max0(dp[i][j],dp[i-1][j]);
            else dp[i][j] = max0(dp[i-1][j-t[i]]+p[i],max0(dp[i][j],dp[i-1][j]));
        }
    }
    // output
    cout<<dp[N][C];
    return 0;
}

```

# [landscape.cpp](#44)
```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


//structures

//global variables
int N; int X, Y, Z;
int totalstart, totalend;
int A[1001], B[1001];
int DP[1001][1001];

int min0(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a<b) return a;
    return b;
}
//declare functions
void initialize(){
    cin >> N >> X >> Y >> Z;
    for (int i=1; i<=N; i++) {
        int b, a;
        cin >> a >> b;
        for(int j=a; j>=0; j--){
            totalstart++;
            A[totalstart] = i;
        }
        for(int j=b; j>=0; j--){
            totalend++;
            B[totalend] = i;
        }
    }
    
    //      for (int i=1; i<=totalstart; i++){
    //         for (int j=1; j<=totalend; j++) {
    //            DP[i][j]=1000000000;
    //         }
    //      }
    for (int j=1; j<=totalstart; j++) DP[0][j] = j*X;
    for (int i=1; i<=totalend; i++) DP[i][0] = i*Y;
}
void solve_dp(){
    for (int i=1; i<=totalstart; i++){
        for (int j=1; j<=totalend; j++) {
            DP[i][j] = min0(DP[i][j], min((DP[i-1][j-1])+(Z*abs(A[i]-B[j])),min(DP[i][j-1] + X, DP[i-1][j] + Y)));
            //            cout<<"DP["<<i<<"]["<<j<<"] = "<<DP[i][j]<<endl;
        }
    }
}
int main() {
    initialize();
    solve_dp();
    cout<<DP[totalstart][totalend];
    return 0;
}

```

# [lcs.cpp](#45)
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
string str1, str2;
int dp[2][10001];
// declare any functions
void initialize(){
    cin >> str1 >> str2;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]) dp[1][j] = dp[0][j-1]+1;
            else dp[1][j]= max(dp[0][j],dp[1][j-1]);
        }
        swap(dp[0],dp[1]);
    }
}
int main() {
    // declare any local variables
    initialize();
    solve_dp();
    cout<<dp[0][str2.size()];
    // output
    
    return 0;
}

```

# [lcstring.cpp](#46)
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
string str1, str2;
int dp[1001][1001];
// declare any functions
void initialize(){
    cin >> str1 >> str2;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
        }
    }
}
void cout_ans(){
    int maxn = 0;
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            maxn = max(maxn, dp[i][j]);
        }
    }
    cout<<maxn<<endl;
}
int main() {
    
    initialize();
    solve_dp();
    cout_ans();
    return 0;
}

```

# [lis.cpp](#47)
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

// declare any functions
int max0(int a, int b){
    if(a>b) return a;
    return b;
}
int main() {
    // declare any local variables
    int N;
    int num[20001];
    int DP[20001];
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    
    // main
    //    vector < vector<int> > LIS;
    int maxn = 0;
    for(int i=1; i<=N; i++){
        DP[i] = 1;
        for(int j=1; j<=i-1; j++){
            if(num[j]<num[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        maxn = max(maxn, DP[i]);
    }
    //    vector<int> sub;
    //    LIS.push_back(sub);
    //    for(int i=1; i<=N; i++){
    //
    ////        if(LIS.size()==0){
    //////            LIS.push_back(push_back(num[i]));
    ////            vector<int> sub; sub.push_back(num[i]);
    ////            LIS.push_back(sub);
    ////        }
    ////        else {
    ////        cout<<i<<" s: "<<LIS.size()<<endl;
    //        for(int j=0; j<LIS.size(); j++){
    //            if(LIS[j].size()==0 || num[i] > LIS[j][LIS[j].size()-1]){
    //                vector<int> sub1=LIS[j];
    //                sub1.push_back(num[i]);
    //                LIS.push_back(sub1);
    //            } else {
    //                LIS.erase(LIS.begin()+j);
    //            }
    //        }
    ////        }
    ////        maxn = max0(maxn, LIS.size());
    //        for(int j=0; j<LIS.size(); j++){
    //            maxn = max0(maxn, LIS[j].size());
    //            for(int k=0; k< LIS[j].size(); k++){
    ////                cout<<LIS[j][k]<<" ";
    //            }
    ////            cout<<endl;
    ////            cout<<LIS[j].size()<<" ";
    //        }
    ////        cout<<endl;
    //    }
    // output
    cout<<maxn<<endl;
    return 0;
}

```

# [marathon.cpp](#48)
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
int N, K;
int x[501], y[501];
// declare any functions


int dist_between (int i, int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main() {
    // declare any local variables
    
    // input
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> x[i] >> y[i];
    
    // main
    int DP[501][501];
    for(int i=0; i<=K; i++){
        for(int j=1; j<=N; j++){
            DP[i][j] = 1000000000;
        }
    }
    
    DP[0][1] = 0;
    for(int i=0; i<=K; i++){
        for(int j=1; j<=N; j++){
            for(int l=j+1; l<=N && (i-j+l-1)<=K; l++){
                int X = i-j+l-1;
                int Y = l;
                DP[X][Y] = min(DP[X][Y], DP[i][j]+dist_between(j, l));
                //                cout<<"DP["<<X<<"]["<<Y<<"] = "<<DP[X][Y]<<endl;
            }
        }
    }
    // output
    cout<<DP[K][N];
    return 0;
}

```

# [maze1.cpp](#49)
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
#include <string>
using namespace std;

// declare any structures

// declare any global variables
struct p{
    int x,y,d,t;
    p(int x, int y, int d,int t) : x(x),y(y),d(d),t(t) {}
};
// declare any functions

int main() {
    // declare any local variables
    int N, M;
    cin >> M >> N;
    string temp;
    getline(cin, temp);
    
    int maze[N*2+1][M*2+1];
    bool visited1[N*2+1][M*2+1];
    
    int ex1,ey1; int ex2,ey2;
    ex1=ey1=ex2=ey2=-1;
    
    for(int i=0; i<((N*2)+1); i++){
        string read;
        getline(cin,read);
        for(int j=0; j<((M*2)+1); j++){
            visited1[i][j]=false;
            if(read[j]=='+' or read[j]=='-' or read[j]=='|') maze[i][j]=1;
            else maze[i][j]=0;
            
            if(maze[i][j]==0){
                if(i==0){
                    if(ex1==-1){
                        ex1=1; ey1=j;
                    } else{
                        ex2=1; ey2=j;
                    }
                } else if(i==2*N){
                    if(ex1==-1){
                        ex1=(2*N)-1; ey1=j;
                    } else{
                        ex2=(2*N)-1; ey2=j;
                    }
                } else if(j==0){
                    if(ex1==-1){
                        ex1=i; ey1=1;
                    } else{
                        ex2=i; ey2=1;
                    }
                } else if(j==2*M){
                    if(ex1==-1){
                        ex1=i; ey1=(2*M)-1;
                    } else{
                        ex2=i; ey2=(2*M)-1;
                    }
                }
            }
        }
    }
    // main
    //    cout<<ex1<<" "<<ey1<<" "<<ex2<<" "<<ey2<<endl;
    queue<p> qu;
    
    qu.push(p(ex1,ey1,1,0));
    qu.push(p(ex2,ey2,1,1));
    
    
    int X[] = {1,0,-1,0};
    int Y[] = {0,1,0,-1};
    int ans = 0;
    
    visited1[ex1][ey1]=visited1[ex2][ey2]=true;
    while(!qu.empty()){
        int i=qu.front().x;
        int j=qu.front().y;
        int d=qu.front().d;
        int t=qu.front().t;
        //        int t=qu.front().t;
        qu.pop();
        
        ans = max(ans,d);
        
        //        if(t==1){
        for(int k=0; k<4; k++){
            int x=i+X[k];
            int y=j+Y[k];
            if(x>=0 && x<=(N*2)+1 && y>=0 && y<=M*2+1){
                //                    cout<<"pass ";
                if(maze[x][y]==0){
                    //                        cout<<"pass :";
                    x += X[k]; y += Y[k];
                    //                        cout<<x<<"/ "<<y<<" ";
                    if(x>=0 && x<=N*2 && y>=0 && y<=M*2 && !visited1[x][y] && maze[x][y]==0){
                        //                            cout<<"pass ";
                        qu.push(p(x,y,d+1,t));
                        visited1[x][y]=true;
                    }
                }
            }
        }
    }
    // output
    cout<<ans<<endl;
    return 0;
}

```

# [meteor.cpp](#50)
```cpp

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct p1{
    int x, y, t;
    p1(int x, int y, int t) : x(x), y(y), t(t) {}
};

int main() {
    
    //initialize
    int M;
    int matrix[310][310];
    bool visited[310][310];
    int maxn = 1001;
    
    for(int i=0; i<=301; i++){
        for(int j=0; j<=301; j++){
            matrix[i][j] = maxn;
            visited[i][j] = false;
        }
    }
    
    //input
    cin >> M;
    for(int i=1; i<=M; i++){
        int x, y, t;
        cin >> x >> y >> t;
        
        if (x > 300 || y>300 ) continue;
        matrix[x][y] = min(t, matrix[x][y]);
        if(x > 0) matrix[x-1][y] = min(t, matrix[x-1][y]);
        if(y > 0) matrix[x][y-1] = min(t, matrix[x][y-1]);
        if(x < 301) matrix[x+1][y] = min(t, matrix[x+1][y]);
        if(y < 301) matrix[x][y+1] = min(t, matrix[x][y+1]);
        
    }
    
    // bfs
    queue<p1> qu;
    
    qu.push(p1(0,0,0));
    
    int X[] = {1, 0, -1, 0};
    int Y[] = {0, 1, 0, -1};
    
    int ans = -1;
    visited[0][0] = true;
    
    while(!qu.empty()){
        int i = qu.front().x;
        int j = qu.front().y;
        int t = qu.front().t;
        qu.pop();
        
        
        if(t >= matrix[i][j]) continue;
        else if(matrix[i][j]==maxn){
            ans = t;
            break;
        }
        
        for(int k=0; k<4; k++){
            int x = i+X[k];
            int y = j+Y[k];
            
            if(x<0 || x>301 || y<0 || y>301) continue;
            if(!visited[x][y]){
                visited[x][y]=true;
                qu.push(p1(x,y,t+1));
            }
        }
    }
    
    // output
    cout<<ans<<endl;
    return 0;
}

```

# [milkprod.cpp](#51)
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
struct point {
    int start, end, efficiency;
    point(int start, int end, int efficiency) : start(start), end(end), efficiency(efficiency) {}
};
struct s2b {
    bool operator() (point i, point j) { return (i.start<j.start);}
} s2b;

// declare any global variables
int N, M, R;
vector<point> interval;
int dp[1000001];
// declare any functions
void initialize(){
    cin >> N >> M >> R;
    
    int a, b, e;
    for(int i=1; i<=M; i++){
        cin >> a >> b >> e;
        interval.push_back(point(a,b,e));
    }
    sort(interval.begin(), interval.end(), s2b);
    //    for(int i=0; i<M; i++){
    //        cout<<interval[i].start<<" "<<interval[i].end<<" "<<interval[i].efficiency<<endl;
    //    }
}
void solve_dp(){
    for(int i=1; i<=M; i++){
        for(int j=0; j<=N; j++){
            if(j>interval[i-1].start) break;
            if((dp[j]==0 and j<=interval[i-1].start)||(j+R <= interval[i-1].start )){
                //                cout<<"dp["<<interval[i-1].end<<"] = max("<<dp[interval[i-1].end]<<", "<<dp[j]<<"+"<<interval[i-1].efficiency<<") = "<<max(dp[interval[i-1].end], dp[j]+interval[i-1].efficiency)<<endl;
                dp[interval[i-1].end] = max(dp[interval[i-1].end], dp[j]+interval[i-1].efficiency);
            }
        }
    }
}
void print_ans(){
    
    int ans = 0;
    for(int j=0; j<=N; j++){
        ans = max(ans, dp[j]);
    }
    cout<<ans<<endl;
}
int main() {
    
    // input
    initialize();
    // main
    solve_dp();
    // output
    print_ans();
    
    //close
    return 0;
}

```

# [money.cpp](#52)
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
long long V, N, currency[26];
long long dp[10001];
// declare any functions
void initialize(){
    cin >> V >> N;
    for(int i=1; i<=V; i++){
        cin >> currency[i];
    }
}
void solve_dp(){
    dp[0] = 1;
    for(int i=0; i<=V; i++){
        for(int j=0; j<=N; j++){
            if(i+1 <= V) if (j+currency[i+1] <= N) dp[j+currency[i+1]] += dp[j];
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    cout<<dp[N]<<endl;
    return 0;
}

```

# [moo.cpp](#53)
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
struct p{
    int h,s;
    p(int h, int s) : h(h),s(s) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int n;
    vector<p> heights;
    
    // main
    cin >> n;
    int sound[50010];
    for(int i=0; i<n; i++){
        int h,s;
        sound[i]=0;
        cin >> h >> s;
        heights.push_back(p(h,s));
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=(i+1); j<n; j++){
            if(heights[j].h > heights[i].h){
                sound[j]+=heights[i].s;
                break;
            }
        }
        for(int j=(i-1); j>=0; j--){
            if(heights[j].h > heights[i].h){
                sound[j]+=heights[i].s;
                break;
            }
        }
    }
    
    // output
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,sound[i]);
    }
    cout<<ans<<endl;
    return 0;
}

```

# [mst2.cpp](#54)
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
int V, E;
vector<Pair> path[50001]; int read_e, read_s, read_w;
bool visited[50001];
// declare any functions
void initialize(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        cin >> read_s >> read_e >> read_w;
        path[read_s].push_back(Pair(read_e, read_w));
        path[read_e].push_back(Pair(read_s, read_w));
    }
    for(int i=1; i<=V; i++) visited[i] = false;
}
void solve(){
    int ans = 0;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int i = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(visited[i]) continue;
        visited[i] = true;
        ans += d;
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j].neighbor;
            int ndist = path[i][j].weight;
            pq.push(make_pair(ndist, x));
        }
    }
    cout<<ans<<endl;
}
void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    
    //close
    return 0;
}

```

# [nocross.cpp](#55)
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
int N;
int left1[1001],right1[1001];
int DP[1001][1001];
int ans = 0;
// declare any functions
int connected(int l, int r){
    if(abs(left1[l]-right1[r]) <= 4) return 1;
    return 0;
}
int main() {
    // declare any local variables
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> left1[i];
    }
    for(int j=1; j<=N; j++){
        cin >> right1[j];
    }
    // main
    for(int i=1; i<=N; i++){
        DP[i][1] = connected(i,1);
    }
    for(int i=1; i<=N; i++){
        DP[1][i] = connected(1,i);
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1 or j==1) continue;
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            DP[i][j] = max(DP[i][j], DP[i-1][j-1]+connected(i,j));
        }
    }
    // output
    cout<<DP[N][N]<<endl;
    return 0;
}

```

# [pachinko2.cpp](#56)
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
int N;
int points[101][101];
int DP[101][101];
// declare any functions
void solve(int i, int j){
    //    cout<<"DP["<<i<<"]["<<j<<"] = "<<DP[i][j]<<endl;
    if(i==N) return;
    DP[i+1][j] = max(DP[i+1][j],DP[i][j]+points[i+1][j]);
    solve(i+1, j);
    DP[i+1][j+1] = max(DP[i+1][j+1],DP[i][j]+points[i+1][j+1]);
    solve(i+1, j+1);
}
int main() {
    // declare any local variables
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i][j]=0;
            int read_points;
            cin >> read_points;
            points[i][j] = read_points;
        }
    }
    // main
    DP[1][1] = points[1][1];
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                DP[i][j] = DP[i-1][j]+points[i][j];
            } else DP[i][j] = max(DP[i-1][j]+points[i][j],DP[i-1][j-1]+points[i][j]);
        }
    }
    //    solve(1,1);
    // output
    int maxn = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            maxn = max(maxn, DP[i][j]);
        }
    }
    cout<<maxn<<endl;
    return 0;
}

```

# [packdel.cpp](#57)
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
int N, M;
vector<Pair> path[50001];
int dist[50001]; bool visited[50001];
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int a, b, d; cin >> a >> b >> d;
        path[a].push_back(Pair(b,d));
        path[b].push_back(Pair(a,d));
    }
}
void spath (int from){
    
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, from));
    dist[from] = 0;
    while(!pq.empty()){
        int in = pq.top().second;
        pq.pop();
        
        if(visited[in]) continue;
        visited[in] = true;
        for(int i=0; i<path[in].size(); i++){
            int go = path[in][i].neighbor;
            int ndist = dist[in]+path[in][i].weight;
            if(dist[go]==-1 || ndist<dist[go]){
                dist[go]=ndist;
                pq.push(make_pair(ndist, go));
            }
        }
    }
}
void print_ans(){
    cout<<dist[N]<<endl;
}
int main() {
    
    // input
    initialize();
    // main
    spath(1);
    // output
    print_ans();
    
    //close
    return 0;
}

```

# [picnic.cpp](#58)
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
//int V, E;
int K, N, M;
vector<int> path[50001]; int read_e, read_s, read_w;
bool visited[50001];
vector<int> loc;
// declare any functions
void initialize(){
    cin >> K >> N >> M;
    for(int i=1; i<=K; i++){
        int r; cin >> r;
        loc.push_back(r);
    }
    for(int i=1; i<=M; i++){
        cin >> read_s >> read_e;
        path[read_e].push_back(read_s);
    }
}
bool solve(int start){
    //    priority_queue<int, vector<int>, greater<int> > pq;
    queue<int> qu;
    qu.push(start);
    memset(visited, false, sizeof(bool)*(N+1));
    visited[start] = true;
    while(!qu.empty()){
        int i = qu.front();
        qu.pop();
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j];
            if(!visited[x]){
                qu.push(x);
                visited[x] = true;
            }
        }
    }
    
    bool returnb = true;
    for(int i=0; i<K; i++){
        if(!visited[loc[i]]){
            returnb = false;
            break;
        }
    }
    return returnb;
}
void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    int ans = 0;
    for(int i=1; i<=N; i++){
        
        if(solve(i)){
            //            cout<<i<<endl;
            ans++;
        }
    }
    // output
    cout<<ans<<endl;
    //close
    return 0;
}

```

# [pie1.cpp](#59)
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

// declare any functions

int main() {
    // declare any local variables
    int N, K;
    long DP[100001];
    // input
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        DP[i]=0;
    }
    // main
    //    DP[1]=2;
    for(int i=1; i<=N; i++){
        if(i-1 >= 1){
            DP[i] += DP[i-1];
        } else {
            DP[i] += 1;
        }
        if(i-K-1 >= 1){
            DP[i] += DP[i-K-1];
        } else {
            DP[i] += 1;
        }
        DP[i] %= 5000011;
    }
    // output
    cout << DP[N]<<endl;
    return 0;
}

```

# [pogocow.cpp](#60)
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

using namespace std;

//structures
struct point{
    int x, p;
    point(int x, int p):x(x),p(p) {}
};
struct myclass {
    bool operator() (point i,point j) { return (i.x<j.x);}
} waytosort;

//global variables

// functions

int main() {
    
    // local variables
    int N;
    int DP[1010][1010];
    vector<point> target;
    
    // input
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int x,p;
        cin >> x >> p;
        target.push_back(point(x,p));
    }
    sort(target.begin(), target.end(), waytosort);
    
    //main
    int maxn = 0;
    for(int temp = 0; temp < 2; temp++) {
        for(int i = N-1; i >= 0; i--) {
            int k = N;
            int val = 0;
            for(int j=0; j<=i; j++) {
                while(k - 1 > i && target[k - 1].x - target[i].x >= target[i].x - target[j].x) {
                    k--;
                    val = max(val, target[k].p + DP[k][i]);
                }
                DP[i][j] = val;
            }
            maxn = max(maxn, target[i].p + val);
        }
        for(int i = 0; i < N; i++) {
            target[i].x = -1*target[i].x;
        }
        reverse(target.begin(), target.end());
    }
    
    //output
    cout << maxn << endl;
    return 0;
}

```

# [privc.cpp](#61)
```cpp
/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
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

// declare any structures
struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

// declare any global variables
int N;
vector<int> order, sorted;
int cow[4][4];
// declare any functions
void initialize(){
    cin >> N;
    int read;
    for(int i=1; i<=N; i++){
        cin >> read;
        order.push_back(read);
        sorted.push_back(read);
    }
    cow[1][1]=cow[1][2]=cow[1][3]=0;
    cow[2][1]=cow[2][2]=cow[2][3]=0;
    cow[3][1]=cow[3][2]=cow[3][3]=0;
    
    sort(sorted.begin(), sorted.end(), myobject);
}
void solve(){
    for(int i=0; i<N; i++){
        if(order[i] != sorted[i]){
            cow[order[i]][sorted[i]]++;
        }
    }
    int ans = 0;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            //            if(i==j) continue;
            int minn = min(cow[i][j], cow[j][i]);
            ans += minn;
            cow[i][j] -= minn;
            cow[j][i] -= minn;
        }
    }
    ans += (cow[1][2]+cow[1][3])*2;
    cout<<ans<<endl;
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

# [pwalk.cpp](#62)
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
struct p{
    long long b,d;
    p(int b, long long d) :b(b),d(d) {}
};
// declare any global variables
int N,Q;
//int edge[1001][1001];
vector<p> edge[1001];

// declare any functions
long long spath(int s,int e){
    long long dist[1001];
    bool visited[1001];
    memset(dist,0,sizeof(long long)*(N+1));
    memset(visited,false,sizeof(bool)*(N+1));
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0,s));
    dist[s] = 0;
    
    while(!pq.empty()){
//        int d=pq.top().first;
        int i=pq.top().second;
        pq.pop();
        for(int j=0; j<edge[i].size(); j++){
            long long go = edge[i][j].b;
            long long ndist = dist[i] + edge[i][j].d;
            if(dist[go]==0 || ndist < dist[go]){
                dist[go] = ndist;
                if(!visited[go]) pq.push(make_pair(dist[go], go));
            }
        }
    }
    return dist[e];
}
int main() {
    // declare any local variables
    
    // input
    cin >> N >> Q;
    for(int i=1; i<N; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a].push_back(p(b,d));
        edge[b].push_back(p(a,d));
    }
    int s[Q+1],e[Q+1];
    for(int i=1; i<=Q; i++){
        cin >> s[i] >> e[i];
        cout<<spath(s[i],e[i])<<endl;
    }
    // main
    // output
    
    return 0;
}

```

# [recording.cpp](#63)
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

# [roadblock.cpp](#64)
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
int N,M;
//vector<p> edge[10000];
//map<int, map<int, int> > edge;
int edge[101][101];
map<int, int> pre;
int spath_before(){
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[1] = 0;
    while(true){
        int in = -1;
        for(int i=1; i<=N; i++){
            if(dist[i] != -1){
                if(!visited[i]&&(in == -1 or dist[i]<dist[in])){
                    in=i;
                }
            }
        }
        if(in==-1) break;
        visited[in] = true;
        for(int i=1; i<=N; i++){
            if(edge[in][i]==0) continue;
            int go = i;
            int ndist = dist[in]+edge[in][i];
            if(dist[go]==-1 || ndist<dist[go]){
                pre[go] = in;
                dist[go]=ndist;
            }
        }
    }
    return dist[N];
}
int spath_after(){
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[1] = 0;
    while(true){
        int in = -1;
        for(int i=1; i<=N; i++){
            if(dist[i] != -1){
                if(!visited[i]&&(in == -1 or dist[i]<dist[in])){
                    in=i;
                }
            }
        }
        if(in==-1) break;
        visited[in] = true;
        for(int i=1; i<=N; i++){
            if(edge[in][i]==0) continue;
            int go = i;
            int ndist = dist[in]+edge[in][i];
            if(dist[go]==-1 || ndist<dist[go]){
                pre[go] = in;
                dist[go]=ndist;
            }
        }
    }
    return dist[N];
}
// declare any functions

int main() {
    // declare any local variables
    
    
    // input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            edge[i][j]=0;
        }
    }
    for(int i=1; i<=M; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a][b]=d;
        edge[b][a]=d;
    }
    // main
    int ori_dist = spath_before();
    int before = N;
    int current;
    int ans = 0;
    while(true){
        current = pre[before];
        if(current==0) break;
        
        edge[before][current] *=2;
        edge[current][before] *=2;
        ans = max(ans,spath_after()-ori_dist);
        edge[before][current] /=2;
        edge[current][before] /=2;
        
        before = current;
        
    }
    // output
    cout<<ans<<endl;
    return 0;
}

```

# [roads.cpp](#65)
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
#include <math.h>
#include <iomanip>
using namespace std;

// declare any structures

// declare any global variables
struct p{
    long long x, y;
};
// declare any functions
long long square(long x){
    return x*x;
}
int main()
{
    int N; int M;
    p field[1001];
    long double dist[1001];
    cin >> N >> M;
    bool connected[N+1][N+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            connected[i][j] = false;
        }
    }
    for(int i=1; i<=N; i++){
        cin >> field[i].x >> field[i].y;
    }
    for (int i=1; i<=M; i++){
        long long x,y;
        cin >> x >> y;
        connected[x][y]=true;
        connected[y][x]=true;
    }
    int k=1;
    long double ans=0;
    bool visited[N+1];
    memset(visited,false,sizeof(bool)*(N+1));
    fill(dist, dist+N+1, 100000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        //        cout<<"k: "<<k<<endl;
        //        dist[k]=-1;
        visited[k]=true;
        for (int j=1; j<=N; j++) {
            if(connected[k][j]){
                dist[j]=0;
            }
            long double current_dist = sqrt(square(field[k].x-field[j].x)+square(field[k].y-field[j].y));
            if (current_dist<dist[j]){
                dist[j]=current_dist;
            }
            //            cout<<"dist["<<j<<"] = "<<dist[j]<<endl;
        }
        k=-1;
        for (int j=1; j<=N; j++){
            if (!visited[j] && dist[j]!=100000000000){
                if (k==-1 || dist[j]<dist[k]){
                    k=j;
                }
            }
        }
        ans += dist[k];
        //        cout << ans << endl;
        
    }
    
    cout << fixed << setprecision(2) << ans << endl;
}

```

# [sandcas.cpp](#66)
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
struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} waytosort;
// declare any global variables
int N, X, Y;
vector<int> M, B;
// declare any functions
void initialize(){
    cin >> N >> X >> Y;
    for(int i=0; i<N; i++){
        int m, b; cin >> m >> b;
        M.push_back(m);
        B.push_back(b);
    }
    sort(M.begin(), M.end(), waytosort);
    sort(B.begin(), B.end(), waytosort);
}
void solve(){
    int ans = 0;
    for(int i=0; i<N; i++){
        if(M[i] > B[i]){
            ans += abs(M[i] - B[i])*Y;
        } else{
            ans += abs(M[i] - B[i])*X;
        }
    }
    cout<<ans<<endl;
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

# [scales.cpp](#67)
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


struct myclass {
    bool operator() (int i,int j) { return (i>j);}
} myobject;


vector<int> weight;
int N; int max1;
int ans = 0;
void recurse (int i, int C){
    
    if(C < 0) return;
    ans = max(ans, max1-C);
    
    
    if(C == 0) return;
    if(i >= N) return;
    
    if(i+1<N and weight[i]+weight[i+1]<=C){
        recurse(i+1, C-weight[i]);
    }
    else if(weight[i] > C){
        recurse(i+1, C);
    }
    else {
        recurse(i+1, C-weight[i]);
        recurse(i+1, C);
    }
    
}

int main() {
    
    cin >> N >> max1;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        weight.push_back(a);
    }
    
    sort(weight.begin(), weight.end(), myobject);
    recurse(0,max1);
    
    cout<<ans<<endl;
    return 0;
}

```

# [sed.cpp](#68)
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
string str1, str2;
int dp[1001][1001];
// declare any functions
void initialize(){
    cin >> str1 >> str2;
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            dp[i][j]=1000000;
        }
    }
    for(int i=1; i<=str1.size(); i++) dp[i][0] = i;
    for(int i=1; i<=str2.size(); i++) dp[0][i] = i;
}
int compare(int a, int b){
    if(str1[a]==str2[b]) return 0;
    return 1;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            dp[i][j]=min(min(dp[i-1][j-1]+compare(i-1,j-1),dp[i][j-1]+1),dp[i-1][j]+1);
        }
    }
}
int main() {
    
    initialize();
    solve_dp();
    
    cout<<dp[str1.size()][str2.size()];
    
    return 0;
}

```

# [sgraze.cpp](#69)
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
struct point{
    int a; int b;
    point(int a, int b) : a(a), b(b) {}
};
// declare any global variables
struct sorting {
    bool operator() (point i,point j) {
        if(i.b!=j.b) return (i.b<j.b);
        else  return i.a<j.a;
    }
} sorting1;

// declare any functions

int main() {
    // declare any local variables
    int N;
    vector<point> interval;
    // input
    cin >> N;
    for(int i=1;i<=N; i++){
        int a,b;
        cin >> a >> b;
        interval.push_back(point(a,b));
    }
    // main
    sort(interval.begin(), interval.end(), sorting1);
    int maxn = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(interval[i].a >= maxn){
            ans++;
            maxn = max(maxn, interval[i].b);
        }
    }
    // output
    cout<<ans<<endl;
    return 0;
}

```

# [silvlilly.cpp](#70)
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
struct for_ans{
    int min_lilly, min_jumps, paths;
    for_ans(int min_lilly, int min_jumps, int paths): min_lilly(min_lilly),min_jumps(min_jumps),paths(paths) {}
};
struct for_qu{
    int x, y, lilly, jumps;
    for_qu(int x, int y, int lilly, int jumps) : x(x),y(y),lilly(lilly),jumps(jumps) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N; int M;
    int matrix[40][40]; int read;
    int sx=0, sy=0;
    bool visited[40][40];
    int min_lilly[40][40],min_jumps[40][40]; long paths[40][40];
    int ax=0,ay=0;

    // input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> read;
            if(read == 4){
                ax = i; ay = j;
            }
            if(read == 3){
                sx = i; sy = j; matrix[i][j] = 0;
            } else matrix[i][j] = read;
            //            ans[i][j] = for_ans(1001, 1001, 0);
            min_lilly[i][j]=1001;
            min_jumps[i][j]=1001;
            visited[i][j] = false;
            paths[i][j]=0;
        }
    }

    // main
    queue<for_qu> qu;
    qu.push(for_qu(sx,sy,0,0));

    int X[] = {-2,-2,-1,-1,1,1,2,2};
    int Y[] = {-1,1,-2,2,-2,2,-1,1};
    min_lilly[sx][sy]=0;
    min_jumps[sx][sy]=0;
    paths[sx][sy]=1;
    while(!qu.empty()){
        int i=qu.front().x;
        int j=qu.front().y;
        //        int lilly = min(min_lilly[i][j],qu.front().lilly);
        int lilly = min_lilly[i][j];
        //        int jumps = min(min_jumps[i][j],qu.front().jumps);
        int jumps = min_jumps[i][j];
        qu.pop();


        //        cout<<"@ "<<i<<" "<<j<<" w/ lilly "<<lilly<<" and jumps "<<jumps<<" visited_ans "<<visited[ax][ay]<<" "<<min_lilly[i][j]<<" "<<min_jumps[i][j]<<" "<<paths[i][j]<<endl;


        if(visited[i][j]) continue;
        visited[i][j] = true;


        for(int k=0; k<8; k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(x>=1 && x<=N && y>=1 and y<=M){
                //                cout<<x<<" "<<y<<" m: "<<matrix[x][y]<<" "<<lilly<<endl;
                if(matrix[x][y]==0){
                    //                    if(!visited[x][y])
                    qu.push(for_qu(x,y,lilly+1,jumps+1));
                    if (lilly+1 == min_lilly[x][y] && jumps+1 == min_jumps[x][y]){
                        paths[x][y]+=paths[i][j];
                        //                        cout<<"1paths["<<x<<"]["<<y<<"] = "<<paths[x][y]<<" pre: "<<i<<" "<<j<<" lilly "<<min_lilly[x][y]<<endl;
                    }
                    else if (lilly+1 < min_lilly[x][y] || (lilly+1==min_lilly[x][y] && jumps+1<min_jumps[x][y])){
                        min_lilly[x][y] = lilly+1;
                        min_jumps[x][y] = jumps+1;
                        paths[x][y] = paths[i][j];
                        visited[x][y]=false;
                        //          illy[x][y]<<endl;
                    }
                    //                    else if(lilly+1 > min_lilly[x][y] || jumps+1 > min_jumps[x][y]) continue;

                } else if ((matrix[x][y]==1 or matrix[x][y]==4)){
                    if(matrix[x][y]!=4) qu.push(for_qu(x,y,lilly,jumps+1));
                    if (lilly == min_lilly[x][y] && jumps+1 == min_jumps[x][y]){
                        paths[x][y]+=paths[i][j];
                    }
                    else if (lilly < min_lilly[x][y] || (lilly==min_lilly[x][y] && jumps+1<min_jumps[x][y])){
                        min_lilly[x][y] = lilly;
                        min_jumps[x][y] = jumps+1;
                        paths[x][y] = paths[i][j];
                        visited[x][y]=false;
                    }
                }
            }
        }

    }
    // output
    if (min_lilly[ax][ay]==1001)cout<<"-1";
    else cout<<min_lilly[ax][ay]<<endl<<min_jumps[ax][ay]<<endl<<paths[ax][ay]<<endl;
    return 0;
}

```

# [snail.cpp](#71)
```cpp
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

// declare any structures
int max0(int a, int b){
    if (a>b) return a;
    return b;
}
// declare any global variables
int N; int B;
int ans = 0;
map<int, map<int, int> > grid;
map<int, map<int, int> > visited;
int X[5] = {0, 1, 0, -1, 0};
int Y[5] = {0, 0, 1, 0, -1};
int change1(int i){
    if(i==3) return 4;
    return (i+1)%4;
}
int change2(int i){
    if(i==1) return 4;
    return (i+3)%4;
}
/*
 * direction:
 * 1) down
 * 2) right
 * 3) up
 * 4) left
 */

void recurse(int i, int j, int counter, int direction){
    counter++;
    ans = max0(counter, ans);
    //    cout<<i<<" "<<j<<" = "<<counter<<endl;
    visited[i][j] = 1;
    if(direction == 0){
        for(int k=1; k<=4; k++){
            int x = i+X[k]; int y = j+Y[k];
            if(x<1 || x>N || y<1 || y>N){
                continue;
            } else if(visited[x][y]){
                continue;
            } else if(grid[x][y] == 0){
                recurse(x, y, counter, k);
            }
        }
    } else if (direction != 0){
        int x = i+X[direction]; int y = j+Y[direction];
        if(x<1 || x>N || y<1 || y>N || grid[x][y] == 1){
            if(i+X[change1(direction)] >= 1 && i+X[change1(direction)] <= N){
                if(j+Y[change1(direction)] >= 1 && j+Y[change1(direction)] <= N){
                    if(!visited[i+X[change1(direction)]][j+Y[change1(direction)]] && grid[i+X[change1(direction)]][j+Y[change1(direction)]] == 0){
                        recurse(i+X[change1(direction)], j+Y[change1(direction)],counter, change1(direction));
                    }
                }
            }
            if(i+X[change2(direction)] >= 1 && i+X[change2(direction)] <= N){
                if(j+Y[change2(direction)] >=1 && j+Y[change2(direction)] <= N){
                    if(!visited[i+X[change2(direction)]][j+Y[change2(direction)]] && grid[i+X[change2(direction)]][j+Y[change2(direction)]] == 0){
                        recurse(i+X[change2(direction)], j+Y[change2(direction)],counter, change2(direction));
                    }
                }
            }
        } else if (grid[x][y]==0 && !visited[x][y]){
            recurse(x,y,counter, direction);
        }
    }
    visited[i][j] = 0;
}
int main() {
    
    char read;
    int col;
    
    cin >> N >> B;
    
    for(int i=1; i<=B; i++){
        cin >> read >> col;
        grid[col][int(read-'A'+1)] = 1;
    }
    // main
    recurse(1, 1, 0, 0);
    // output
    cout<< ans<<endl;
    return 0;
}

```

# [soda.cpp](#72)
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
struct node{
    int location; bool start;
    node(int location, bool start) : location(location), start(start) {}
};
struct myclass {
    bool operator() (node i,node j) {
        if(i.location!=j.location) return (i.location<j.location);
        return i.start==true;
    }
} waytosort;

// declare any global variables
int N;
vector<node> interval; int read_s, read_e;
// declare any functions
void initialize(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> read_s >> read_e;
        interval.push_back(node(read_s, true));
        interval.push_back(node(read_e, false));
    }
    sort(interval.begin(), interval.end(), waytosort);
}
void solve(){
    int ans = 0;
    int counter = 0;
    for(int i=0; i<(2*N); i++){
        if(interval[i].start){
            counter++;
            ans = max(ans, counter);
        } else if (!interval[i].start){
            counter--;
        }
    }
    cout<< ans <<endl;
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

# [stamps.cpp](#73)
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
int K, N, stamp[51];
int dp[2000010];
int maxn = 0;
int total = 0;
// declare any functions
void initialize(){
    cin >> K >> N;
    for(int i=1; i<=N; i++){
        cin >> stamp[i];
        total = max(total, stamp[i]);
    }
    total *= K;
    for(int j=0; j<=total; j++) dp[j]=201;
}
void solve_dp(){
    dp[0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=total; j++){
            if(dp[j]+1 <= K)
                dp[j+stamp[i+1]] = min(dp[j+stamp[i+1]], dp[j]+1);
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    int max_s = 0;
    int streak = 0;
    for(int i=1; i<=total; i++){
        if(dp[i] <= K){
            streak++;
            max_s = max(max_s, streak);
        } else{
            streak = 0;
        }
    }
    cout<<max_s<<endl;
    return 0;
}

```

# [subset.cpp](#74)
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

// declare any functions

int main() {
    // declare any local variables
    int N, DP[50][400];
    // input
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=(N*(N+1)/2); j++)
            DP[i][j] = 0;
    // main
    DP[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=(N*(N+1)/4); j++){
            DP[i][j] += DP[i-1][j] + DP[i-1][j-i];
        }
    }
    // output
    if((N*(N+1)%4)!=0 || DP[N][(N*(N+1)/4)]==0) cout<<"0"<<endl;
    else cout<<DP[N][(N*(N+1)/4)]<<endl;
    return 0;
}

```

# [tallest.cpp](#75)
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
struct p{
    int s,e;
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N,I,H,R;
    int temp[10001];
    map<int, map<int, int> > visited;
    
    cin >> N >> I >> H >> R;
    
    for(int i=1; i<=10000; i++){
        temp[i]=H;
    }
    
    for(int i=1; i<=R; i++){
        int x,y;
        cin >> x >> y;
        if(x>y) swap(x,y);
        if(visited[x][y]) continue;
        visited[x][y]=1;
        if(x+1 > N or y-1<1) continue;
        for(int j=x+1; j<=y-1; j++){
            temp[j] = temp[j]-1;
        }
    }
    // main
    for(int i=1; i<=N; i++){
        cout<<temp[i]<<endl;
    }
    // output
    
    return 0;
}

```

# [tractor.cpp](#76)
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
#include <deque>
#include <algorithm>
using namespace std;

struct p{
    int x,y,b;
    p(int x, int y, int b) : x(x), y(y), b(b) {}
};
// declare any structures

// declare any global variables

// declare any functions


int main() {
    // declare any local variables
    int N; int tx, ty;
    //    map<int, map<int, int> > field;
    int field[1010][1010];
    //    map<int, map<int, int> > visited;
    bool visited[1010][1010];
    int bx,by;
    bx=by=1001;
    
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            field[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    // input
    cin >> N >> tx >> ty;
    for(int i=1; i<=N; i++){
        int x,y;
        cin >> x >> y;
        field[x][y] = 1;
        if(bx!=1000)bx = max(bx,x+1);
        if(by!=1000)by = max(by,y+1);
    }
    
    deque<p> myde;
    
    myde.push_front(p(tx,ty,0));
    
    
    int X[] = {-1,0,1,0};
    int Y[] = {0,-1,0,1};
    while(!myde.empty()){
        
        int i=myde.front().x;
        int j=myde.front().y;
        int b=myde.front().b;
        //        cout<<i<<" "<<j<<" "<<b<<endl;
        myde.pop_front();
        
        if(visited[i][j]==1) continue;
        
        visited[i][j] = 1;
        
        if(i==0 || j==0){
            cout<<b<<endl;
            break;
        }
        for(int k=0; k<4; k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(visited[x][y]==0 && x>=0 && x<=bx && y>=0 && y<=by){
                if(field[x][y]==1) myde.push_back(p(x,y,b+1));
                else myde.push_front(p(x,y,b));
            }
        }
        
    }
    
    
    // main
    // output
    
    return 0;
}

```

# [waterslides.cpp](#77)
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
#define MAXN 50010
struct point{
    int b, e;
    point(int b, int e) : b(b), e(e) {}
};
// declare any global variables
void readfile(){
    
}
int V,E,K;
int DP[MAXN][11];
vector<point> edges[MAXN];
// declare any functions
int min(int a, int b){
    if(a<b) return a;
    return b;
}
int max(int a, int b){
    if(a>b) return a;
    return b;
}
int dfs(int a, int k){
    if(a == V) return 0;
    if(DP[a][k] != 0) return DP[a][k];
    int maxn = 0;
    int minn = 100000000;
    for(int i=0; i<edges[a].size(); i++){
        int b = edges[a][i].b;
        int e1 = edges[a][i].e;
        maxn = max(maxn, dfs(b,k)+e1);
        //        cout<<a<<" "<<k<<" maxn: "<<maxn<<endl;
        if(k-1 >= 0){
            minn = min(minn, dfs(b,k-1)+e1);
            //            cout<<a<<" "<<k<<" minn: "<<minn<<endl;
        }
    }
    DP[a][k] = min(minn, maxn);
    //    cout<<"dp["<<a<<"]["<<k<<"] = min("<<minn<<", "<<maxn<<") + "<<e<<" = "<<DP[a][k]<<endl;
    return DP[a][k];
}
//long solve(){
//    long minn = 100000000000;
//    for(int k=0; k<=K; k++){
//        for(int i=1; i<=V; i++){
//            for(int j=0; j<=K; j++){
//                DP[i][j]=0;
//            }
//        }
//        minn = min0(minn, dfs(V,k,0));
//    }
//    return minn;
//}
int main() {
    // declare any local variables
    
    // input
    cin >> V >> E >> K;
    for(int i=1; i<=E; i++){
        int a,b,e;
        cin >> a >> b >> e;
        edges[a].push_back(point(b,e));
    }
    // main
    cout<<dfs(1,K)<<endl;
    // output
    
    return 0;
}

```

