class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> freq;
       int l = 0, length = 0;
    for (int r = 0; r < s.length(); r++) {
        freq[s[r]]++;
        
        while (freq[s[r]] > 1) {
            freq[s[l]]--;
            l++;
        }
        length = max(length, r - l + 1);
    }
    return length; 
    }
};
