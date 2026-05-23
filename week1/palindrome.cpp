#include<climits>
class Solution {
public:
    bool isPalindrome(int x){
      if(x<0) return false;
       int n = x;
       int k = 0 ;
       while(x>=1){
        if(k>INT_MAX/10 || (k==INT_MAX/10 && x%10>7)) return false;
        k=k*10+x%10;
        x=x/10;
       }
       if(k==n) return true;
    

       return false;  
    }
};
