class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size())return false;
        int F1[26]={0};
        for(char c : s){
            F1[c-'a']++;
        }
         for(char c : t){
            F1[c-'a']--;
        }
        for(int i = 0; i < 26;i++){
            if(F1[i]!=0) return false;
        }
       return true;
    }
};
