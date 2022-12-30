class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false ;
        else {
            string s ;
            stringstream ss ;
            ss<<x ;
            ss>>s ;
            int l = s.length();
            
            for (int i=0 ;i<((l/2)+1) ; i++){
                if (s[i]!=s[l-i-1]){
                    return false ;
                }
            }
            return true ;
        }
    }
};