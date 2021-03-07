class Solution {
public:
    long long INF = 0x3F3F3F3F3F3F3F3F;
    int maxProduct(vector<int>& nums) {
        int n = (int) nums.size();
        long long ans = -INF;
        int sign = 1, f0, f1, l0, l1;
        sign = 1, f0 = n, f1 = 0, l0 = l1 = -1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (long long) nums[i]);
            if (nums[i] < 0) sign *= -1;
            if (nums[i] == 0) {
                if (l1 >= f1) {
                    long long temp = 1;
                    for (int i = f1; i <= l1; ++i)
                        temp *= nums[i];
                    ans = max(ans, temp);
                }
                if (l0 >= f0) {
                    long long temp = 1;
                    for (int i = f0; i <= l0; ++i)
                        temp *= nums[i];
                    ans = max(ans, temp);
                }
                sign = 1;
                f0 = n, f1 = i + 1, l0 = l1 = -1;
            } else {
                if (sign > 0) f1 = min(f1, i + 1), l1 = max(l1, i);
                if (sign < 0) f0 = min(f0, i + 1), l0 = max(f1, i);
            }
        }
        if (l1 >= f1) {
            long long temp = 1;
            for (int i = f1; i <= l1; ++i)
                temp *= nums[i];
            ans = max(ans, temp);
        }
        if (l0 >= f0) {
            long long temp = 1;
            for (int i = f0; i <= l0; ++i)
                temp *= nums[i];
            ans = max(ans, temp);
        }
        return ans;
        
    }
};