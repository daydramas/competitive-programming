class Solution {
public:
    vector<int> twoSum(vector<int>& a, int m) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (a[i] + a[j] == m)
                    return {i, j};
        return {0, 0};
    }
};