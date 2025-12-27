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
    int dfs(TreeNode* node, unordered_map<long long, int> &m, long long prefixSum, const int targetSum) {

        if(!node) return 0;

        prefixSum += node->val;

        int cnt = m[prefixSum - targetSum];

        m[prefixSum]++;

        cnt += dfs(node->left, m, prefixSum, targetSum);
        cnt += dfs(node->right, m, prefixSum, targetSum);

        m[prefixSum]--;

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        m[0] = 1;

        return dfs(root, m, 0, targetSum);
    }
};