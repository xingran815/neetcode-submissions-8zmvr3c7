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
    // if a tree is BST
    // then the root value > maximum of left tree
    //                     < minimum of the right tree
    // the right child is BST
    // the left child is BST
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left, right;
        bool left_child, right_child;
        if (root->left) {
            int left_max = root->left->val;
            maximum(root->left, left_max);
            if (root->val > left_max) {
                left = true;
            } else {
                left = false;
            }
        } else {
            left = true;
        }
        if (root->right) {
            int right_min = root->right->val;
            minimum(root->right, right_min);
            if (root->val < right_min) {
                right = true;
            } else {
                right = false;
            }
        } else {
            right = true;
        }
        left_child = isValidBST(root->left);
        right_child = isValidBST(root->right);
        if (left && right && left_child && right_child) {
            return true;
        }
        return false;
    }
    void minimum(TreeNode* root, int& v) {
        if (!root) {
            return;
        }
        v = min(root->val, v);
        minimum(root->left, v);
        minimum(root->right, v);
    }
    void maximum(TreeNode* root, int& v) {
        if (!root) {
            return;
        }
        v = max(root->val, v);
        maximum(root->left, v);
        maximum(root->right, v);
    }
};
