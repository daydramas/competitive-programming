class Solution {
public:
    vector<int> manacher(string s) {
        string s1 = "@";
        for(char c : s) s1 += c, s1 += "#";
        s1.back() = '&';
        vector<int> ans(s1.size() - 1); 
        int lo = 0, hi = 0;
        for(int i = 1; i <= s1.size() - 2; ++i) {
            if (i != 1)
                ans[i] = min(hi - i, ans[hi - i + lo]);
            while (s1[i - ans[i] - 1] == s1[i+ans[i]+1])
                ans[i]++;
            if (i+ans[i] > hi)
                lo = i - ans[i], hi = i + ans[i];
        }
        ans.erase(begin(ans));
        for (int i = 0; i < ans.size(); ++i)
            if ((i & 1) == (ans[i] & 1)) ans[i]++;
        return ans;
    }
    string longestPalindrome(string s) {
        vector<int> x = manacher(s);
        pair<int, int> ans = {-1, -1};
        for (int i = 0; i < x.size(); ++i)
            ans = max(ans, {x[i], i});
        return s.substr((ans.second + 1) / 2 - ans.first / 2, ans.first);
    }
};