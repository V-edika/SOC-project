class Solution {
public:
    void Permutations(vector<int>& permute, int st, vector<vector<int>>& out) {
    if (st == (int)permute.size()) {
         out.push_back(permute);
          return;
           }
    for (int i = st; i < (int)permute.size(); i++) {
        swap(permute[st], permute[i]);
        Permutations(permute, st + 1, out);
        swap(permute[st], permute[i]);             
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        Permutations(nums, 0 ,out);
        return out;
    }
};
