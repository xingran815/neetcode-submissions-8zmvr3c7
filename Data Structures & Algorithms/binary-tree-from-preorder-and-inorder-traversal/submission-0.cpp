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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hmap_inorder;
        if (inorder.size() == 0) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            hmap_inorder[inorder[i]] = i;
        }

        // creat root
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = hmap_inorder[root->val];
        int left = idx, right = inorder.size()-1-idx;
        vector<int> pre_left, pre_right, in_left, in_right;
        for (int i = 0; i < left; ++i) {
            pre_left.push_back(preorder[1+i]);
            in_left.push_back(inorder[i]);
        }
        for (int i = 0; i < right; ++i) {
            pre_right.push_back(preorder[1+left+i]);
            in_right.push_back(inorder[1+left+i]);
        }
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};
