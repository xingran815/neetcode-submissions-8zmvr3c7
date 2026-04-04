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
    vector<int> rightSideView(TreeNode* root) {
        // Breadth-First-Search
        // using queue<>
        // fetch each nodes in the queue
        // and push its child nodes to the queue
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q_nodes;
        q_nodes.push(root);
        
        while (!q_nodes.empty()) {
            TreeNode* back = q_nodes.back();
            ans.push_back(back->val);
            int size = q_nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = q_nodes.front();
                q_nodes.pop();
                if (tmp->left) q_nodes.push(tmp->left);
                if (tmp->right) q_nodes.push(tmp->right);
            }
        }
        return ans;
    }
};
