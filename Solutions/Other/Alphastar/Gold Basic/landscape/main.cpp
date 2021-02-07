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
