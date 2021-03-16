class Solution {
public:
    int minSteps(int n) {
        int ans = 0, pri = 2;
        while (n != 1) {
            while (n % pri == 0) {
                n /= pri;
                ans += pri;
            }
            pri++;
        }
        return ans;
    }
};