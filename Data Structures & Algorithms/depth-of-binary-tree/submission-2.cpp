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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> qTree;
        if (root) {
            qTree.push(root);
        }
        while (!qTree.empty()) {
            int size = qTree.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = qTree.front();
                qTree.pop();
                if (tmp->left) {
                    qTree.push(tmp->left);
                }
                if (tmp->right) {
                    qTree.push(tmp->right);
                }
            }
            depth++;
        }

        return depth;
        
    }
};
