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
    int goodNodes(TreeNode* root) {
        // BFS
        if (!root) return 0;
        queue<pair<TreeNode*, int>> qTree;        
        qTree.push(pair<TreeNode*, int>(root, root->val));
        int count = 0;
        while (!qTree.empty()) {
            int size = qTree.size();
            for (int i = 0; i<size; ++i) {
                auto tmp = qTree.front();
                qTree.pop();
                if (tmp.first->val >= tmp.second) {
                    count++;
                    if (tmp.first->left) qTree.push(
                        pair<TreeNode*, int>(tmp.first->left, tmp.first->val));
                    if (tmp.first->right) qTree.push(
                        pair<TreeNode*, int>(tmp.first->right, tmp.first->val));
                } else {
                    if (tmp.first->left) qTree.push(
                        pair<TreeNode*, int>(tmp.first->left, tmp.second));
                    if (tmp.first->right) qTree.push(
                        pair<TreeNode*, int>(tmp.first->right, tmp.second));
                }
            }

        }

        return count;
    }
};
