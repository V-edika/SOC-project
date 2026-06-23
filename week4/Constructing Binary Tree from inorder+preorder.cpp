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
    unordered_map<int,int> idx;
    TreeNode* build(vector<int>&preorder, int& preIdx, int left, int right){
        if(left>right) return nullptr;
        int v = preorder[preIdx++];
        TreeNode* root = new TreeNode(v);
        int pos = idx[v];
        root->left = build(preorder, preIdx, left, pos-1);
        root->right = build(preorder, preIdx, pos+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < (int)inorder.size(); i++) idx[inorder[i]]=i;
        int preIdx = 0 ;
        return build(preorder, preIdx,0, (int)inorder.size()-1);
    }
};
