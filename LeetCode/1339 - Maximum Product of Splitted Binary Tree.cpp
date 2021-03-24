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
    long long int sum = 0, ans = 0;
    const long long int mod = 1e9 + 7;
    void search(TreeNode* x) {
        if (x == NULL)
            return;
        sum += x->val;
        search(x->left);
        search(x->right);
    }
    int _search(TreeNode* x) {
        if (x == NULL)
            return 0;
        long long int sub = x->val;
        sub += _search(x->left);
        sub += _search(x->right);
        ans = max(ans, (sum - sub) * sub);
        return sub;
    }
    long long maxProduct(TreeNode* root) {
        search(root);
        _search(root);
        return ans % mod;
    }
};