class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;       
       freq[0] = 1;                         
       int sum = 0, answer = 0;
        for (int x : nums) {
         sum += x;
         answer += freq[sum - k];
        freq[sum]++;
       }
   
    return answer;
   }
    
};
