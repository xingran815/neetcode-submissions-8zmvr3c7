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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check the cur node
        // check the left nodes
        // check the right nodes
        // p is null, q is not null....
        // p->val != q->val
        // left = dfs(p->left, q->left)
        // right = ..
        // left && right && p->val == q->val
        
        if (!q && !p) {
            // p and q are nullptrs
            return true;
        } else if ((p && !q) || (!p && q)) {
            // only one of them is nullptr
            return false;
        }
 
        // p and q are not nullptrs
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        if (left && right && p->val == q->val) {
            return true;
        }
        return false;
    }
};
