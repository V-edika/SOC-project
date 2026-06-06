class Solution {
public:
    void Subsets(vector<int>& nums, vector<int>& curr, int i, vector<vector<int>>& out){
        if(i==nums.size()){
         out.push_back({curr});
         return;
        }
        curr.push_back(nums[i]);
        Subsets(nums, curr, i+1, out);
        curr.pop_back();
        Subsets(nums, curr, i+1, out);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> curr;

        Subsets(nums, curr,0 , out);
     return out;
    }
};
