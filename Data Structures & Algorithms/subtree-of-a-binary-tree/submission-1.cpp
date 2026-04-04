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
    // find the same node in the root as subRoot
    // define it as candidateRoot
    // check if candidateRoot and subRoot are the same
    // same node value, same children
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        cout << "entering the function issubtree" << endl;
        if (!subRoot) {
            // subRoot is null
            cout << "suroot is null" << endl;
            return true;
        } else if (!root) {
            // root is null but subRoot isn't
            cout << "root is null" << endl;
            return false;
        }
        
        if (isSametree(root, subRoot)) {
            return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        if (left || right) {
            return true;
        }
        return false;
    }

    bool isSametree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            // both are nullptrs
            return true;
        }
        if (root1 && root2) {
            bool left = isSametree(root1->left, root2->left);
            bool right = isSametree(root1->right, root2->right);
            if (left && right && root1->val == root2->val) {
                return true;
            }
        }
        return false;
    }
};
