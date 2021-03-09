class Solution {
public:
    long long INF = 0x3F3F3F3F3F3F3F3F;
    int maxSubArray(vector<int>& nums) {
        long long ans = -INF, cur = 0;
        for (int x : nums) {
            cur = max(cur + x, (long long)x);
            ans = max(ans, cur);
        }
        return ans;
    }
};