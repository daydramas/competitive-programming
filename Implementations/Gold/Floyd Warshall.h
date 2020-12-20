const int maxn = 500;

using T = long long; T ID=1e18;
T d[maxn+5][maxn+5];
void init() {
    for(int i=0; i<maxn; i++)
    for(int j=0; j<maxn; j++)
        d[i][j]=(i==j?0:ID); }
void ae(int a, int b, T c) {
    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
}
void fw() {
    for(int k=0; k<maxn; k++)
    for(int i=0; i<maxn; i++)
    for(int j=0; j<maxn; j++)
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}