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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = (p->val < q->val) ? p->val : q->val;
        int large = (p->val < q->val) ? q->val : p->val;
        if (small <= root->val && root->val <= large) {
            return root;
        } else if (root->val < small) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};
