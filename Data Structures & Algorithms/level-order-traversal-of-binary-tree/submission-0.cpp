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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // solve with BST
        // using queue<>
        // pop the nodes in the queue from the front
        // push the child nodes of the nodes to the queue
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q_nodes;
        q_nodes.push(root);
        while (!q_nodes.empty()) {
            int size = q_nodes.size();
            vector<int> level_nodes;
            for (int i = 0; i<size; ++i) {
                TreeNode* tmp = q_nodes.front();
                q_nodes.pop();
                level_nodes.push_back(tmp->val);
                if (tmp->left) q_nodes.push(tmp->left);
                if (tmp->right) q_nodes.push(tmp->right);
            }
            if (!level_nodes.empty()) {
                ans.push_back(level_nodes);
            }
        }
        return ans;
    }
};
