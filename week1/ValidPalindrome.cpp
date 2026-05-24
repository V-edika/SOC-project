class Solution {
public:
    bool isAlphaNum(char c){
        if((c>='0'&&c<='9') || (tolower(c)>='a'&& tolower(c)<='z')) return true;
        return false;
    }
    bool isPalindrome(string s) {
     int l = 0 , r = s.size()-1;
     while(l<r){
        if(!isAlphaNum(s[l])){ l++; continue;}
        if(!isAlphaNum(s[r])){r--; continue;}
        if(tolower(s[l]) != tolower(s[r])) return false;
        l++;
        r--;
     }
     return true;
    }
};
