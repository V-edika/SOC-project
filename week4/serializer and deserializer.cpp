/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string& ans){
        if(root==NULL){
            ans = ans +"N,";
            return;
        }
        ans = ans + to_string(root->val) + ",";
        serializeHelper(root->left , ans);
        serializeHelper(root->right, ans);

    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serializeHelper(root, ans);
        return ans;
    }
    TreeNode* deserializeHelper(vector<string>& node, int& i){
        if(node[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(node[i++]));
        root->left = deserializeHelper(node , i);
        root->right = deserializeHelper(node, i);
        return root; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> node;
        string tmp;
        for(char ch : data){
            if(ch==','){
                node.push_back(tmp);
                tmp.clear();
            }
            else tmp =tmp + ch;
        }
        int i = 0 ;
        return deserializeHelper(node,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
