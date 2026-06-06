class Solution {
public:
    void allSum(vector<int>& candidates,vector<int>& curr,int target,int st,vector<vector<int>>&out) {
    if (target == 0) {
         out.push_back(curr);
          return; 
          }
    for (int i = st; i < (int)candidates.size(); i++) {
        if (candidates[i] > target) continue;             
        curr.push_back(candidates[i]);
        allSum(candidates, curr, target - candidates[i], i, out);    
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> curr;
        allSum(candidates,curr,target,0, out);
        return out;
    }
};
