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
     bool valid(TreeNode* root, long long low, long long high) {
        if (root == nullptr) return true;
        if (root->val <= low || root->val >= high) return false;
        if (!valid(root->left, low, root->val)) return false;
        if (!valid(root->right, root->val, high))return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
