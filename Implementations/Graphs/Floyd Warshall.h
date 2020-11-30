/**
 * FloydWarshall<3> fw;
 * fw.edge(1, 2, 1)
 * fw.edge(2, 3, 1)
 * fw.edge(1, 3, 5)
 * fw.calc()
 * cout << fw.get(1, 3) << "\n"; // 2
 * cout << fw.get(2, 3) << "\n"; // 1
*/

template<int SZ> struct FloydWarshall {
    long long d[SZ][SZ];
    FloydWarshall() {
        for(int i=0; i<SZ; i++)
        for(int j=0; j<SZ; j++)
            d[i][j] = (i==j)?0:1e18;
    }
    void edge(int i, int j, long long weight) {
        d[i][j] = min(d[i][j], weight);
        d[j][i] = min(d[j][i], weight);
    }
    void calc() {
        for(int k=0; k<SZ; k++)
        for(int i=0; i<SZ; i++)
        for(int j=0; j<SZ; j++)
            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
    long long get(int i, int j) {
        if (d[i][j] == 1e18) return -1;
        return d[i][j];
    }
};