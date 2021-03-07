class Solution {
public:
    long long INF = 0x3F3F3F3F3F3F3F3F;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0;
        for (int x : arr)
            sum += x;
        if (k == 1) {
            // max subarray sum here
            long long ans = 0, cur = 0;
            for (int x : arr) {
                cur = max(cur + x, (long long)x);
                ans = max(ans, cur);
            }
            ans = ans % 1000000007;
            return ans;
        }
        if (sum < 0 || k == 2) {
            // max subarray sum here
            long long ans = 0, cur = 0;
            for (int x : arr) {
                cur = max(cur + x, (long long)x);
                ans = max(ans, cur);
            }
            for (int x : arr) {
                cur = max(cur + x, (long long)x);
                ans = max(ans, cur);
            }
            ans = ans % 1000000007;
            return ans;
        } else {
            long long ans = (k - 2) * sum % 1000000007;
            long long best = 0, cur = 0;
            for (int x : arr) {
                cur += x;
                best = max(best, cur);
            }
            ans = (ans + best) % 1000000007; 
            reverse(begin(arr), end(arr));
            best = 0, cur = 0;
            for (int x : arr) {
                cur += x;
                best = max(best, cur);
            }
            ans = (ans + best) % 1000000007;
            return ans;
        }
    }
};