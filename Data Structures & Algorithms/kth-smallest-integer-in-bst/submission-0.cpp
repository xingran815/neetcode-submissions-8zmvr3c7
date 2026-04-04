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
private:
    int n;
    int val;
public:
    int kthSmallest(TreeNode* root, int k) {
        n = 0;
        // print the numbers in ascending order
        helper_asc(root, k);
        return val;
    }
    void helper_asc(TreeNode* root, int k) {
        // find the leftest node, print it
        if (!root) {
            return;
        }
        helper_asc(root->left, k);
        n++;
        if (n == k) {
            val = root->val;    
        }
        helper_asc(root->right, k);
    }
};
