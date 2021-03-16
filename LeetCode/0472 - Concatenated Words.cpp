#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(begin(words), end(words), [&](const string& x, const string& y) -> bool {
            return x.length() < y.length();
        });
        vector<string> ans;
        Tree<string> st[1001];
        auto contains = [&](const string& s) -> bool {
            bool dp[s.size() + 1];
            memset(dp, 0, sizeof(dp));
            dp[0] = true;
            for (int i = 1; i <= s.size(); ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j] && st[i - j].find(s.substr(j, i - j)) != st[i - j].end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return (bool)dp[s.size()];
        };
        bool fst = true;
        for (string& s : words) {
            if (!fst && contains(s))
                ans.push_back(s);
            st[(int)s.size()].insert(s);
            fst = false;
        }
        return ans;
    }
};