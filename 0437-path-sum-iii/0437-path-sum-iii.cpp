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
    int dfs(TreeNode* root, unordered_map<int, int> &m, int prefixSum, const int targetSum) {

        if(!root) return 0;

        prefixSum += root->val;

        int cnt = m[prefixSum - targetSum];

        m[prefixSum]++;

        cnt += dfs(root->left, m, prefixSum, targetSum);
        cnt += dfs(root->right, m, prefixSum, targetSum);

        m[prefixSum]--;

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> m;
        m[0] = 1;

        return dfs(root, m, 0, targetSum);
    }
};