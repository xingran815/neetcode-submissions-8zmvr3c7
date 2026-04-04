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
    bool isValidBST(TreeNode* root) {
        return helper_bst(root, -INT_MAX, INT_MAX);
    }
    bool helper_bst(TreeNode* root, int minimum, int maximum) {
        if (!root) {
            return true;
        }
        if (root->val <= minimum || root->val >= maximum) {
            return false;
        }
        // minimum < left descendants < root->val
        bool left = helper_bst(root->left, minimum , root->val);
        // root->val < right descendants < maximum
        bool right = helper_bst(root->right, root->val, maximum);
        if (left && right) {
            return true;
        }
        return false;
    }
};
