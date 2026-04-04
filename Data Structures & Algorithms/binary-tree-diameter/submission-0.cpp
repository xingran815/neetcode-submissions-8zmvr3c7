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
    int max_diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        dfs(root);
        return max_diameter;
        
    }
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        max_diameter = max(max_diameter, left+right);

        return max(left, right) + 1;
    }
};
