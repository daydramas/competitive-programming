class Solution {
public:
    void add(int& a, const int& b) {
        a = (a + b) % 1000000007;
    }
    int numOfWays(int n) {
        int dp[n][3][3][3];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (i != j && j != k)
                        dp[0][i][j][k] = 1;
        for (int i = 1; i < n; ++i)
            for (int x = 0; x < 3; ++x)
                for (int y = 0; y < 3; ++y)
                    for (int z = 0; z < 3; ++z)
                        if (x != y && y != z)
                            for (int _x = 0; _x < 3; ++_x)
                                for (int _y = 0; _y < 3; ++_y)
                                    for (int _z = 0; _z < 3; ++_z)
                                        if (_x != _y && _y != _z)
                                            if (x != _x && y != _y && z != _z)
                                                add(dp[i][x][y][z], dp[i - 1][_x][_y][_z]);
        int ans = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    add(ans, dp[n - 1][i][j][k]);
        return ans;
    }
};