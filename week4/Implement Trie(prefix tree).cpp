class Trie {
       struct TreeNode {
        TreeNode* child[26];
        bool isEnd = false;
        TreeNode(){
            for(int i = 0 ; i < 26 ; i++) child[i] = nullptr;
        }
       };
       TreeNode* root;
       TreeNode* walk(string& word){
        TreeNode* ans = root;
        for(char c : word){
            int i = c-'a';
            if(ans->child[i]==NULL) return nullptr;
            ans = ans->child[i];
        }
        return ans ;
       }

public:
    Trie() {
       root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* ans = root;
        for(char c : word){
            int i = c-'a';
            if(ans->child[i]== NULL) ans->child[i] = new TreeNode();
            ans = ans->child[i];
        }
        ans->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* ans = walk(word);
        if(ans == nullptr) return false;
        return ans->isEnd;
    }
    
    bool startsWith(string prefix) {
        return walk(prefix)!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
