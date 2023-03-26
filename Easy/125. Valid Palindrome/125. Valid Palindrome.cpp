    class Solution {
public:
    bool isPalindrome(string s) {
        char *c=&s[0] ;
        char *c1=&s[s.size()-1] ;
        
        while (c<c1){
            while (!isalnum(*c) && c<c1)
                c++ ;
            while (!isalnum(*c1) && c<c1)
                c1-- ;
            if (c<c1 && tolower(*c)!=tolower(*c1))
                return false ;
            c++ ;
            c1--;

        }
        return true ;
    }
};