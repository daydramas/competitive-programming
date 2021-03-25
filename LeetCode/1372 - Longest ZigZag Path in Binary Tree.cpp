/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void up(int& a, const int& b) {
        a = max(a, b);
    }
    int solve(TreeNode* x, int d) {
        if (x == NULL)
            return 0;
        int sub = 0;
        if (d == 0) {
            up(ans, sub = solve(x->right, 1) + 1);
            up(ans, solve(x->right, 0));
        } else {
            up(ans, sub = solve(x->left, 0) + 1);
            up(ans, solve(x->left, 1));
        }
        return sub;
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0); solve(root, 1);
        return ans - 1;
    }
};